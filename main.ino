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

const int AVGLEN = 2;
// Msgeq7Avg msgeq(A0, D4, D5, AVGLEN);
Msgeq7 msgeq(A0, D4, D5);

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

    Msgeq7Utils::ISpectrum interp;
    Msgeq7Utils::interpolate(interp, s);

/*    for (int i = 0; i < interp.size(); ++i){
        Serial.printf("%5d", interp[i]);
    }
    Serial.println();
*/


    int red_pwm = map(100 * Msgeq7Utils::areaLeft(interp, Msgeq7Utils::L*3), 25, 100, 0, 200);
    int green_pwm = map(100 * Msgeq7Utils::areaMiddle(interp, Msgeq7Utils::L*2, Msgeq7Utils::L*4), 25, 100, 0, 100);
    int blue_pwm = map(100 * Msgeq7Utils::areaRight(interp, Msgeq7Utils::L*4), 25, 100, 0, 150);

    unsigned total = 0;
    for (const auto& i : interp) {
        total += i;
    }

    double p = 0.75;
    if (total > interp.size()*4096 * p) {
        white.on();
        red.off();
        green.off();
        blue.off();
    }
    else {
        white.off();
        red.setDuty(red_pwm);
        green.setDuty(green_pwm);
        blue.setDuty(blue_pwm);
    }

    Serial.printf("%4d%4d%4d\n", red_pwm, green_pwm, blue_pwm);
}
