#ifndef MSGEQ7UTILS_H
#define MSGEQ7UTILS_H

#include "Msgeq7.hpp"

namespace Msgeq7Utils {

const short L = 4; // upsampling factor

// modifies the input
void interpolate(std::array<unsigned int, L*(Msgeq7::NUM_FREQUENCY_BANDS-1)>& ret, const Msgeq7::Spectrum& s) {
    for (int i = 0; i < Msgeq7::NUM_FREQUENCY_BANDS - 1; ++i){
        for (int j = 0; j < L; ++j) {
            ret[i*L + j] = (s[i] * (L-j)) + (s[i+1] * j);
            ret[i*L + j] /= L;
        }
    }
}

// return a fresh copy, but expensive cause space
const std::array<unsigned int, L*(Msgeq7::NUM_FREQUENCY_BANDS-1)> interpolate(const Msgeq7::Spectrum& s) {
	std::array<unsigned int, L*(Msgeq7::NUM_FREQUENCY_BANDS-1)> ret;
	interpolate(ret, s);
	return ret;
}

};

#endif
