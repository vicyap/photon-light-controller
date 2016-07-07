#pragma SPARK_NO_PREPROCESSOR

#include "application.h"

#include "Color.hpp"
#include "convert.hpp"
#include "Heartbeat.hpp"
#include "Led.hpp"
#include "Rgb.hpp"

/* VARIABLES */
Led red(D0);
Led green(D1);
Led blue(D2);
#define FADESPEED 5

/* FUNCTIONS */

/* SETUP */
void setup() {
    Heartbeat::instance().start();
}

/* LOOP */
void loop() {

	int r, g, b;
    // fade from blue to violet
    for (r = 0; r < 256; r++) { 
        red.setDuty(r);
        delay(FADESPEED);
    } 
    // fade from violet to red
    for (b = 255; b > 0; b--) { 
        blue.setDuty(b);;
        delay(FADESPEED);
    } 
    // fade from red to yellow
    for (g = 0; g < 256; g++) { 
        green.setDuty(g);
        delay(FADESPEED);
    } 
    // fade from yellow to green
    for (r = 255; r > 0; r--) { 
        red.setDuty(r);;
        delay(FADESPEED);
    } 
    // fade from green to teal
    for (b = 0; b < 256; b++) { 
        blue.setDuty(b);
        delay(FADESPEED);
    } 
    // fade from teal to blue
    for (g = 255; g > 0; g--) { 
        green.setDuty(g);
        delay(FADESPEED);
    } 
}
