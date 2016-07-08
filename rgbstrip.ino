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

    Serial.begin(9600);
    Serial.println("Hello World!");
}

/* LOOP */
void loop() {

    Msgeq7::Spectrum s = msgeq.read();
    Serial.printf("  63  160  400   1k 2.5k 6.2k  16k\n");
    Serial.printf("%4d %4d %4d %4d %4d %4d %4d\n",
        s[0], s[1], s[2], s[3], s[4], s[5], s[6]);

    delay(100);
}
