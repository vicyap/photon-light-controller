#include "Rgb.hpp"

#include "Color.hpp"

Rgb::Rgb(int Rpin, int Gpin, int Bpin) :
_Rled(Rpin),
_Gled(Gpin),
_Bled(Bpin)
{}

void Rgb::setColor(int r, int g, int b)
{
   _Rled.setDuty(r);
   _Gled.setDuty(g);
   _Bled.setDuty(b);
}

void Rgb::setColor(const Color::Color& c) 
{
    _Rled.setDuty(c.R);
    _Gled.setDuty(c.G);
    _Bled.setDuty(c.B);
}


