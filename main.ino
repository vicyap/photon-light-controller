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

const int AVGLEN = 10;
Msgeq7Avg msgeq(A0, D4, D5, AVGLEN);

#define THRESH 0.33
#define SUM_THRESH 20000

/* FUNCTIONS */

/* SETUP */
void setup() {
    Heartbeat::instance().start();

    Serial.begin(9600);
    Serial.println("Hello World!");
}

/* LOOP */
void loop() {

    Msgeq7::Spectrum s = msgeq.read();

    std::array<unsigned int, Msgeq7Utils::L * (Msgeq7::NUM_FREQUENCY_BANDS-1)> interp;
    Msgeq7Utils::interpolate(interp, s);

    for (int i = 0; i < interp.size(); ++i){
        Serial.printf("%5d", interp[i]);
    }
    Serial.println();
    delay(100);
}
