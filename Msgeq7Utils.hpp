#ifndef MSGEQ7UTILS_H
#define MSGEQ7UTILS_H

#include "Msgeq7.hpp"

namespace Msgeq7Utils {

const short L = 8; // upsampling factor
const unsigned INTERP_LEN = L*(Msgeq7::NUM_FREQUENCY_BANDS-1);
typedef std::array<unsigned int, INTERP_LEN> ISpectrum; // interpolated spectrum

// modifies the input
void interpolate(ISpectrum& ret, const Msgeq7::Spectrum& s) {
    for (int i = 0; i < Msgeq7::NUM_FREQUENCY_BANDS - 1; ++i){
        for (int j = 0; j < L; ++j) {
            ret[i*L + j] = (s[i] * (L-j)) + (s[i+1] * j);
            ret[i*L + j] /= L;
        }
    }
}

// return a fresh copy, but expensive cause space
const ISpectrum interpolate(const Msgeq7::Spectrum& s) {
	ISpectrum ret;
	interpolate(ret, s);
	return ret;
}

double areaLeft(const ISpectrum& I, const unsigned x) {
    unsigned int sum = 0;
    unsigned int total = 0;
    for (unsigned i = 0; i < I.size(); ++i) {
        if (i < x) {
            sum += I[i];
        }
        total += I[i];
    }

    return 1.0 * sum / total;
}

double areaRight(const ISpectrum& I, const unsigned x) {
    return 1.0 - areaLeft(I, x);
}

double areaMiddle(const ISpectrum& I, const unsigned x1, const unsigned x2) {
    return areaLeft(I, x2) - areaLeft(I, x1);
}

};

#endif
