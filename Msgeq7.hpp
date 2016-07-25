#ifndef MSGEQ7_H
#define MSGEQ7_H

#include "application.h"

#include <array>

class Msgeq7{

public:
    const static int NUM_FREQUENCY_BANDS = 7;
    typedef std::array<int, NUM_FREQUENCY_BANDS> Spectrum;

    Msgeq7(int, int, int); // analog, strobe, reset

    const Spectrum& read();
    const Spectrum& readLast() const;

private:
    int _analogPin;
    int _strobePin;
    int _resetPin;

    Spectrum _spectrum;
};

#endif
