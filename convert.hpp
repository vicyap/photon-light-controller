#ifndef CONVERT_H
#define CONVERT_H

namespace convert {
    
    template<typename T>
    T freqToPeriod(T f)
    { return 1000 / f; }

    template<typename T>
    T periodToFreq(T p)
    { return 1000 / p; }

    template<typename T>
    T bpmToPeriod(T bpm)
    { return 60000 / bpm; }

    template<typename T>
    T bpmToFreq(T bpm)
    { return bpm / 60; }
};


#endif
