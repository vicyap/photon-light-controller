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

    //setADCSampleTime(ADC_SampleTime_480Cycles); // 480 cycles @ 120Mhz = 4 us
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


