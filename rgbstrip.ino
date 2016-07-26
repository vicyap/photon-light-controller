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

Led white(D3);

Msgeq7 msgeq(A0, D4, D5);

#define THRESH 0.33
#define SUM_THRESH 20000

/* FUNCTIONS */

/* SETUP */
void setup() {
    Heartbeat::instance().start();

    white.strobeFreq(10);

    Serial.begin(9600);
    Serial.println("Hello World!");
    Serial.printf("time,  63,  160,  400,   1k, 2.5k, 6.2k,  16k, whiteon\n");
}

/* LOOP */
void loop() {

    Msgeq7::Spectrum s = msgeq.read();

    std::array<double, 7> n;

    double sum = 0;
    for (const auto &t : s) {
        sum += t;
    }
    for (unsigned i = 0; i < 7; ++i) {
        n[i] = (s[i] / sum);
    }

    if (n[0] > THRESH || n[1] > THRESH) {
        int duty = (int) ((n[0] + n[1]) * 255);
        red.setDuty(duty);
    }
    else {
        red.off();
    }

    if (n[2] > THRESH || n[3] > THRESH) {
        int duty = (int) ((n[2] + n[3]) * 255);
        green.setDuty(duty);
    }
    else {
        green.off();
    }

    if (n[4] > THRESH || n[5] > THRESH || n[6] > THRESH) {
        int duty = (int) ((n[4] + n[5] + n[6]) * 255);
        blue.setDuty(duty);
    }
    else {
        blue.off();
    }

    bool whiteOn = sum > SUM_THRESH;
    if (whiteOn) {
        white.on();
        red.off();
        green.off();
        blue.off();
    }
    else {
        white.off();
    }
    Serial.printf("%d,%4d,%4d,%4d,%4d,%4d,%4d,%4d,%d\n", micros(),
        s[0], s[1], s[2], s[3], s[4], s[5], s[6], whiteOn);
}
