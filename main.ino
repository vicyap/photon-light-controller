#pragma SPARK_NO_PREPROCESSOR

#include "application.h"

#include "Color.hpp"
#include "convert.hpp"
#include "Heartbeat.hpp"
#include "Msgeq7.hpp"
#include "Msgeq7Utils.hpp"
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

//    white.strobeFreq(10);

    Serial.begin(9600);
    Serial.println("Hello World!");
    Serial.printf("time,  63,  160,  400,   1k, 2.5k, 6.2k,  16k, whiteon\n");
}

/* LOOP */
void loop() {

    Msgeq7::Spectrum s = msgeq.read();

    std::array<unsigned int, Msgeq7Utils::L * (Msgeq7::NUM_FREQUENCY_BANDS-1)> interp;
    Msgeq7Utils::interpolate(interp, s);

    for (int i = 0; i < interp.size() - Msgeq7Utils::L; ++i){
        Serial.printf("%5d", interp[i]);
    }
    Serial.println();
    delay(100);
}
