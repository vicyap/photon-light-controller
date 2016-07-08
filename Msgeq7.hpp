#ifndef MSGEQ7_H
#define MSGEQ7_H

#include "application.h"

#include <array>

class Msgeq7{

public:
    typedef std::array<int, 7> Spectrum;

    Msgeq7(int, int, int);

    const Spectrum& read();
    const Spectrum& readLast() const;

private:
    int _analogPin;
    int _strobePin;
    int _resetPin;

    Spectrum _spectrum;
};

#endif
