#include "CounterIncrementer.h"

int main()
{

    unsigned int nLoops = UINT_MAX;
    bool stop = false;
    double periodTime = 10;
    timespec initTime, finalTime, execTime;

    std::cout << "Verify if the calibration is correct..." << std::endl;
    // Calculate the calibration parameters
    initTime.tv_sec = 4;
    initTime.tv_nsec = 0;
    finalTime.tv_sec = 6;
    finalTime.tv_nsec = 0;
    struct parameters params = calib(nLoops, stop, initTime, finalTime);
    std::cout << "1) Calculate the calibration parameters: a = " << params.a << ", b = " << params.b << std::endl;

    // Calculate the number of loops with the parameters
    double countLoopsCalibration = params.a * periodTime + params.b;
    std::cout << "2) Number of loops with the parameters for " << periodTime << " seconds: " << countLoopsCalibration << std::endl;

    // Get the actual number of loops
    initTime = timespec_now();
    unsigned countLoopsReal = timerIncrementer(nLoops, stop, periodTime, 0);
    finalTime = timespec_now();
    execTime = finalTime - initTime;
    std::cout << "3) Number of loops: " << (double)countLoopsReal << " (executed in " << (timespec_to_ms(execTime)/1000) << " s)\n" << std::endl;

    // Calculate the accuracy
    std::cout << "4) Accuracy: " << ((1 - (std::abs(countLoopsReal - countLoopsCalibration) / countLoopsReal))*100) << "%" << std::endl;

    return 0;
}
