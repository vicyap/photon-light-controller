#pragma SPARK_NO_PREPROCESSOR

#include "application.h"

#include "convert.hpp"
#include "Heartbeat.hpp"
#include "Led.hpp"

/* VARIABLES */
Led red(D0);
double freq;

/* FUNCTIONS */

/* SETUP */
void setup() {
    Heartbeat::instance().start();
    red.strobeFreq(convert::bpmToFreq<double>(128));
    red.strobeOn();
}

/* LOOP */
void loop() {

}
