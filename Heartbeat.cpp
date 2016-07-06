#include "Heartbeat.h"

Heartbeat::Heartbeat() :
_isOn(false),
_timer(PERIOD, &Heartbeat::_toggle, *this)
{}

void Heartbeat::_toggle() {
	if (_isOn) {
		RGB.brightness(0);
		_isOn = false;
	}
	else {
		RGB.brightness(BRIGHTNESS);
		_isOn = true;
	}
}

void Heartbeat::start() {
	_timer.start();
}

void Heartbeat::stop() {
	_timer.stop();
}

Heartbeat& Heartbeat::instance() {
	RGB.control(true);
	RGB.color(255, 0, 0);
	RGB.brightness(0);
	static Heartbeat inst;
	return inst;
}

