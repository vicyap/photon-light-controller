#pragma SPARK_NO_PREPROCESSOR

#include "application.h"

#include "Heartbeat.h"
#include "Led.h"

/* VARIABLES */
Led red(D0);

/* FUNCTIONS */

/* SETUP */
void setup() {
    Heartbeat::instance().start();
}

/* LOOP */
void loop() {

    red.strobe(8);
    delay(2000);
    red.setDuty(75);
    delay(2000);

}
