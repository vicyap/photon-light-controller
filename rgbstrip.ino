#pragma SPARK_NO_PREPROCESSOR

#include "application.h"

#include "Heartbeat.h"

/* VARIABLES */

/* FUNCTIONS */

/* SETUP */
void setup() {
    Heartbeat::instance().start();
}

/* LOOP */
void loop() {

}
