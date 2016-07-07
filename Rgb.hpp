#ifndef RGB_H
#define RGB_H

#include "Color.hpp"
#include "Led.hpp"

class Rgb {
public:
    Rgb(int, int, int);

    void setColor(int, int, int);
    void setColor(const Color::Color&);

private:
    Led _Rled;
    Led _Gled;
    Led _Bled;

};

#endif
