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

    bool _isOn;
    int _period;
    int _brightness;
    Timer _timer;
};


#endif
