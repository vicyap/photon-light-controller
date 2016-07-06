#pragma SPARK_NO_PREPROCESSOR

#include "application.h"

class Heartbeat {
public:
    Heartbeat(Heartbeat const&) = delete;
    void operator=(Heartbeat const&) = delete;

public:
    void start() {
        _timer.start();
    }

    void stop() {
        _timer.stop();
    }

    static Heartbeat& instance() {
        static Heartbeat inst;
        RGB.control(true);
        RGB.color(255, 0, 0);
        RGB.brightness(0);
        return inst;
    }

private:
    static Heartbeat* _inst;
    Heartbeat() :
    _period(1000),
    _isOn(false),
    _brightness(128),
    _timer(_period, &Heartbeat::_toggleHeartbeat, *this)
    {}

    void _toggleHeartbeat() {
        if (_isOn) {
            RGB.brightness(0);
            _isOn = false;
        }
        else {
            RGB.brightness(_brightness);
            _isOn = true;
        }
    }

    int _period;
    bool _isOn;
    int _brightness;
    Timer _timer;
};

/* VARIABLES */

/* FUNCTIONS */

/* SETUP */
void setup() {
    Heartbeat::instance().start();
}

/* LOOP */
void loop() {

}
