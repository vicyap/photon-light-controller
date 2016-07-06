#ifndef LED_H
#define LED_H

#include "application.h"

class Led {
public:

	Led (int pin);

	void setDuty(int v);
	void strobe(int f);
    void toggle();

private:
    const static int SWITCH_FREQ = 2000;
    
	int _pin;
    int _duty;
    bool _isOn;
};

#endif

