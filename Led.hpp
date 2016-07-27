#ifndef LED_H
#define LED_H

#include "application.h"

class Led {
public:

    Led (int pin);

    void setDuty(int);
    void strobeFreq(double);
    void strobeOn();
    void strobeOff();
    
    void on();
    void off();
    void toggle();

private:
    const static int SWITCH_FREQ = 2000;
    
    int _pin;
    int _duty;
    bool _isOn;
    Timer _timer;
};

#endif

