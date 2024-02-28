// #include "Calibrator.h"
#include "CpuLoop.h"


int main()
{
    double runTime = 1000; // 1 second
    Calibrator calibrator = Calibrator(runTime, 5);
    CpuLoop cpuLoop = CpuLoop(calibrator);

    // Run time in CPU
    std::cout << "Runing time in CPU..." << std::endl;
    cpuLoop.runTime(runTime);

    std::cout << "Verify if the calibration is correct (improved calibration)..." << std::endl;
    
    // // Calculate the number of loops with the calibration parameters
    double countLoopsCalibration = calibrator.nLoops(runTime);
    std::cout << "1) Number of loops with the parameters for " << (runTime / 1000) << " seconds: " << countLoopsCalibration << std::endl;

    // Get the actual number of loops
    double countLoopsReal = cpuLoop.getSample();
    std::cout << "2) Number of loops with timer for "  << (runTime / 1000) << " seconds: " << countLoopsReal << std::endl;

    // Calculate the accuracy
    std::cout << "3) Accuracy: " << ((1 - (std::abs(countLoopsReal - countLoopsCalibration) / countLoopsReal))*100) << "%" << std::endl;

    return 0;

}
