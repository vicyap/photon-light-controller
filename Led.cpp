#include "Led.h"

Led::Led(int pin) :
_pin (pin),
_duty(0),
_isOn (false)
{
	pinMode(_pin, OUTPUT);
	analogWrite(_pin, 0, SWITCH_FREQ);
}

void Led::setDuty(int v) {
    v = constrain(v, 0, 100); // make sure v is between 0 and 100
    v = map(v, 0, 100, 0, 255); // remap to 0, 255
	_duty = v;
	_isOn = (_duty == 0);
    analogWrite(_pin, v, SWITCH_FREQ);
}

void Led::strobe(int freq) {
    freq = constrain(freq, 0, 65535);
    analogWrite(_pin, _duty, freq);
}

void Led::toggle() {
	if (_isOn) {
		analogWrite(_pin, 0);
		_isOn = false;
	}
	else {
		analogWrite(_pin, _duty);
		_isOn = true;
	}
}
