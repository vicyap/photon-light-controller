#include "Led.hpp"

Led::Led(int pin) :
_pin (pin),
_duty(0),
_isOn (false),
_timer(100, &Led::toggle, *this)
{
	pinMode(_pin, OUTPUT);
}

void Led::setDuty(int v) {
    v = constrain(v, 0, 255); // make sure v is between 0 and 255
	_duty = v;
	_isOn = (_duty == 0);
    analogWrite(_pin, v, SWITCH_FREQ);
}

void Led::strobeFreq(double freq) {
    freq = freq * 2; // multiple by 2 to account for on/off
    freq = constrain(freq, 0, 65535);
    int p = 1000.0 / freq;
    _timer.changePeriod(p);
}

void Led::strobeOn() {
    _timer.start();
}

void Led::strobeOff() {
    _timer.stop();
    off();
}

void Led::on() {
    digitalWrite(_pin, HIGH);
    _isOn = true;
}

void Led::off() {
    digitalWrite(_pin, LOW);
    _isOn = false;
}

void Led::toggle() {
	if (_isOn) {
        on();
	}
	else {
        off();
	}
    _isOn = !_isOn;
}
