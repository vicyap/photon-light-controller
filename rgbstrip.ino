#pragma SPARK_NO_PREPROCESSOR

#include "application.h"

#include "Heartbeat.h"
#include "Led.h"

/* VARIABLES */
Led red(D0);
float freq;

/* FUNCTIONS */

/* SETUP */
void setup() {
    Heartbeat::instance().start();
    freq = 1;
}

/* LOOP */
void loop() {
    red.strobeOff();
    delay(1000);
    red.strobeFreq(freq);
    freq += 0.5;
    red.strobeOn();
    delay(1000);


}
