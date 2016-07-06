#pragma SPARK_NO_PREPROCESSOR

#include "application.h"

#include "Heartbeat.h"

class PwmLed {
public:

    PwmLed(int pin) :
    _pin (pin)
    {
        pinMode(_pin, OUTPUT);
        analogWrite(_pin, 0, _freq);
    }

    // only allow values between [0, 1.0]
    void setDuty(float v) {
        if (v < 0) {
            v = 0;
        }
        else if (v > 1) {
            v = 1;
        }

        analogWrite(_pin, 255 * v);
    }


private:
    int _pin;
    const int _freq = 2000;

};

/* VARIABLES */
PwmLed red(D0);
PwmLed blue(D2);

float redDuty = 0;
float blueDuty = 0;

/* FUNCTIONS */

/* SETUP */
void setup() {
    Heartbeat::instance().start();

}

/* LOOP */
void loop() {
    redDuty = redDuty + 0.2;
    blueDuty = blueDuty + 0.3;

    if (redDuty > 1) {
        redDuty -= 1;
    }

    if (blueDuty > 1) {
        blueDuty -= 1;
    }

    blue.setDuty(blueDuty);
    red.setDuty(redDuty);
    delay(400);

}
