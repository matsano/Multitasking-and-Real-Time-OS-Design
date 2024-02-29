#ifndef Calibrator_h_INCLUDED
#define Calibrator_h_INCLUDED

#include <iostream>
#include <cmath>
#include <vector>
#include "PeriodicTimer.h"
#include "Looper.h"

class Calibrator : public PeriodicTimer
{
private:
    double a;
    double b;
    Looper looper;
    unsigned nTotalSamples;
    
    std::vector<double> samples;

protected:
    void callback();

public:
    Calibrator(double samplingPeriod_ms, unsigned nSamples);
    double nLoops(double duration_ms);

};

#endif
