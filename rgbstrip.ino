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

    // only allow values between 0 and 100
    void setDuty(int v) {
        v = constrain(v, 0, 100); // make sure v is between 0 and 100
        v = map(v, 0, 100, 0, 255); // remap to 0, 255
        analogWrite(_pin, v);
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
   delay(400);

}
