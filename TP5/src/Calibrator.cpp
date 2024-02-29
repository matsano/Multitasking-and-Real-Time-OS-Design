#include "Calibrator.h"

Calibrator::Calibrator(double samplingPeriod_ms, unsigned nSamples) : nTotalSamples(nSamples)
{
    // Least Squares Method
    start(samplingPeriod_ms);
    looper.runLoop();

    // Calculate Sx and Sy
    double Sx = 0.0;
    double Sy = 0.0;

    for (int i = 0; i < nSamples; i++)
    {
        Sx += i * samplingPeriod_ms;
        Sy += samples[i];
    }

    // Calculate Sxy and Sxx
    double Sxx = 0.0;
    double Sxy = 0.0;
    for (int i = 0; i < nSamples; i++)
    {
        Sxy += (i * samplingPeriod_ms) * samples[i];
        Sxx += std::pow((i * samplingPeriod_ms), 2);
    }

    // Calculate the parameters a and b
    a = (Sxy - Sx*Sy/nSamples) / (Sxx - (Sx*Sx)/nSamples);
    b = (Sxx*Sy - Sxy*Sx) / (Sxx*nSamples - Sx*Sx);
}


void Calibrator::callback()
{
    samples.push_back(looper.getSample());

    if (samples.size() == nTotalSamples)
    {
        looper.stopLoop();
    }
}


double Calibrator::nLoops(double duration_ms)
{
    return (a * duration_ms + b);
}
