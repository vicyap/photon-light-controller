#include "Msgeq7.hpp"

namespace {
    const int TR = 1; // tr - reset pulse width (100 ns)
    const int TRS = 72; // trs - reset to strobe delay (72 us)
    const int TS = 18; // ts - strobe pulse width (18 us)
    const int TSS = 72; // tss - strobe to strobe (72 us)
    const int TO = 36; // to - output settling time (36 us)

    const int SAMPLETIME_us = 480 / 120; // 480 cycles @ 120 Mhz = 4 us
}

Msgeq7::Msgeq7(int a, int s, int r) :
_analogPin(a),
_strobePin(s),
_resetPin(r)
{
    pinMode(_analogPin, INPUT);
    pinMode(_strobePin, OUTPUT);
    pinMode(_resetPin, OUTPUT);

    digitalWrite(_resetPin, LOW);
    digitalWrite(_strobePin, HIGH);

    _spectrum = {0, 0, 0, 0, 0, 0, 0};

    setADCSampleTime(ADC_SampleTime_56Cycles);
    // setADCSampleTime(ADC_SampleTime_144Cycles); // 144 cycles @ 120Mhz = 1.2 us
    // setADCSampleTime(ADC_SampleTime_480Cycles); // 480 cycles @ 120Mhz = 4 us
}

const Msgeq7::Spectrum& Msgeq7::read() {
    // reset the output multiplexor
    digitalWrite(_resetPin, HIGH);
    digitalWrite(_resetPin, LOW);

    // Read each band
    for (int i = 0; i < NUM_FREQUENCY_BANDS; ++i) {
        digitalWrite(_strobePin, LOW);
        delayMicroseconds(TO);
        _spectrum[i] = analogRead(_analogPin);
        digitalWrite(_strobePin, HIGH);

        delayMicroseconds(TS);
        delayMicroseconds(TSS - TO - TS);
    }

    return _spectrum;
}

const Msgeq7::Spectrum& Msgeq7::readLast() const {
    return _spectrum;
}

Msgeq7Avg::Msgeq7Avg(int a, int s, int r, unsigned n) :
Msgeq7::Msgeq7(a, s, r),
_LEN(n)
{
    // read some values to preload the _spectrum
    for (unsigned i = 0; i < _LEN; ++i) {
        const Spectrum& nextVal = Msgeq7::read();
        for (unsigned j = 0; j < Msgeq7::NUM_FREQUENCY_BANDS; ++j) {
            _spectrum[j] += nextVal[j] / _LEN;
        }
    }
}

const Msgeq7::Spectrum& Msgeq7Avg::read() {
    const Spectrum& nextVal = Msgeq7::read();
   
    // use _spectrum as the current average and update based on difference
    for (unsigned i = 0; i < Msgeq7::NUM_FREQUENCY_BANDS; ++i) {
        _spectrum[i] += (nextVal[i] - _spectrum[i]) / _LEN;
    }

    return _spectrum;
}
