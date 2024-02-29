#include "CpuLoop.h"
#include "Chrono.h"


int main()
{
    double samplingPeriod = 200;
    Calibrator calibrator(samplingPeriod, 5);
    CpuLoop cpuLoop(calibrator);

    // Run time in CPU
    std::cout << "Runing time in CPU..." << std::endl;
    double runTime = 3000;
    Chrono chronometer;
    chronometer.restart();
    cpuLoop.runTime(runTime);
    chronometer.stop();

    std::cout << "Run loop time: " << chronometer.lap() << " ms" << std::endl;

    // Calculate the accuracy
    std::cout << "3) Accuracy: " << ((1 - (std::abs(runTime - chronometer.lap()) / runTime))*100) << "% \n" << std::endl;

    std::cout << "Verify if the calibration is correct (improved calibration)..." << std::endl;
    // // Calculate the number of loops with the calibration parameters
    double countLoopsCalibration = calibrator.nLoops(runTime);
    std::cout << "1) Number of loops with the parameters for " << (runTime / 1000) << " seconds: " << countLoopsCalibration << std::endl;

    // Get the actual number of loops
    double countLoopsReal = cpuLoop.getSample();
    std::cout << "2) Number of loops with timer for "  << (runTime / 1000) << " seconds: " << countLoopsReal << std::endl;

    return 0;

}
