#ifndef HEARTBEAT_H
#define HEARTBEAT_H

#include "application.h"

class Heartbeat {
public:
    Heartbeat(Heartbeat const&) = delete;
    void operator=(Heartbeat const&) = delete;

public:
    void start();
	void stop();

    static Heartbeat& instance();

private:
    Heartbeat();

    void _toggle();

    const static int PERIOD = 1000;
    const static int BRIGHTNESS = 128;

    bool _isOn;
    Timer _timer;
};


#endif
