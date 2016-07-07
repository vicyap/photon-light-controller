#pragma SPARK_NO_PREPROCESSOR

#include "application.h"

#include "Color.hpp"
#include "convert.hpp"
#include "Heartbeat.hpp"
#include "Led.hpp"
#include "Rgb.hpp"

/* VARIABLES */
Led red(D0);
Rgb strip(D0, D1, D2);

/* FUNCTIONS */

/* SETUP */
void setup() {
    Heartbeat::instance().start();
}

/* LOOP */
void loop() {
    strip.setColor(Color::BLUE);
    delay(3000);
    strip.setColor(Color::GREEN);
    delay(3000);
    strip.setColor(Color::RED);
    delay(3000);
    strip.setColor(200, 0, 150);
    delay(3000);

}
