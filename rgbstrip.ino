#pragma SPARK_NO_PREPROCESSOR

#include "application.h"

#include "Color.hpp"
#include "convert.hpp"
#include "Heartbeat.hpp"
#include "Msgeq7.hpp"
#include "Led.hpp"
#include "Rgb.hpp"

/* VARIABLES */
Led red(D0);
Led green(D1);
Led blue(D2);

Msgeq7 msgeq(A0, D3, D4);

/* FUNCTIONS */

/* SETUP */
void setup() {
    Heartbeat::instance().start();

    red.strobeFreq(10);
    green.strobeFreq(10);
    blue.strobeFreq(10);

    Serial.begin(9600);
    Serial.println("Hello World!");
}

/* LOOP */
void loop() {

    Msgeq7::Spectrum s = msgeq.read();
    Serial.printf("  63  160  400   1k 2.5k 6.2k  16k\n");
    Serial.printf("%4d %4d %4d %4d %4d %4d %4d\n",
        s[0], s[1], s[2], s[3], s[4], s[5], s[6]);

    if (s[0] > 3000 || s[1] > 3000) {
        red.on();
    }
    else {
        red.off();
    }

    if (s[2] > 3000 || s[3] > 3000 || s[4] > 3000) {
        green.on();
    }
    else {
        green.off();
    }

    if (s[5] > 3000 || s[6] > 3000) {
        blue.on();
    }
    else {
        blue.off();
    }
}
