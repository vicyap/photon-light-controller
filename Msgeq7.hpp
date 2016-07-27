#ifndef MSGEQ7_H
#define MSGEQ7_H

#include "application.h"

#include <array>
#include <vector>

class Msgeq7{

public:
    const static int NUM_FREQUENCY_BANDS = 7;
    typedef std::array<unsigned int, NUM_FREQUENCY_BANDS> Spectrum;

public:
    Msgeq7(int, int, int); // analog, strobe, reset

    const Spectrum& read();
    const Spectrum& readLast() const;

protected:
    int _analogPin;
    int _strobePin;
    int _resetPin;

    Spectrum _spectrum;
};

class Msgeq7Avg : public Msgeq7 {

public:
    Msgeq7Avg(int, int, int, unsigned);

    const Msgeq7::Spectrum& read();

private:
    const unsigned _LEN;
};

#endif
