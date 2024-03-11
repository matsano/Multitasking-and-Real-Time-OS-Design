#include <thread>
#include "PriorityThread.h"
#include "Calibrator.h"
#include "CpuLoop.h"
#include "Chrono.h"

int main()
{

    // Use only one thread

    // cpu_set_t cpuSet;
    // // Initially there is no CPU core selected
    // CPU_ZERO(&cpuSet);
    // // The threads that will be created later will only be executed on the first CPU core
    // CPU_SET(0, &cpuSet);
    // // Setting the CPU affinity of the current process to run on only CPU 0
    // sched_setaffinity(0, sizeof(cpu_set_t), &cpuSet);


    // Set the CPU loops
    double samplingPeriod = 200;
    Calibrator calibrator(samplingPeriod, 5);
    CpuLoop cpuLoopA(calibrator);
    CpuLoop cpuLoopB(calibrator);
    CpuLoop cpuLoopC(calibrator);
    CpuLoop cpuLoopD(calibrator);
    // Run time in CPU
    // std::cout << "Runing time in CPU..." << std::endl;
    // double runTime = 3000;
    // Chrono chronometer;
    // chronometer.restart();
    // cpuLoop.runTime(runTime);
    // chronometer.stop();



    // Set the 3 tasks (A, B and C) and the mutex (R)
    int priorityA = 100;
    double execTimeA = 40;
    double delayTimeA = 60;
    double timeCallMutexA = 10;
    double durationMutexA = 10;
    bool canUseMutexA = true;

    int priorityB = 50;
    double execTimeB = 10;
    double delayTimeB = 70;
    bool canUseMutexB = false;

    int priorityC = 25;
    double execTimeC = 5000;
    double delayTimeC = 110;
    double timeCallMutexC = 20;
    double durationMutexC = 20;
    bool canUseMutexC = true;

    Mutex R(false);

    PriorityThread A(priorityA, execTimeA, delayTimeA, timeCallMutexA, durationMutexA, canUseMutexA, &R, &cpuLoopA);
    PriorityThread B(priorityB, execTimeB, delayTimeB, canUseMutexB, &cpuLoopB);
    PriorityThread C(priorityC, execTimeC, delayTimeC, timeCallMutexC, durationMutexC, canUseMutexC, &R, &cpuLoopC);

    // double runTime = 5000;
    // cpuLoopD.runTime(runTime);

    // Start scenario
    std::cout << "t = 0" << std::endl;
    std::cout << "Task B is activated..." << std::endl;
    B.start();

    
    // double lap1 = chronometer.lap();
    // timespec_wait(timespec_from_ms(3000));
    // double lap2 = chronometer.lap();

    // std::cout << "t = 3" << std::endl;

    // std::cout << "Task A is activated..." << std::endl;
    // std::cout << "Task B is activated..." << std::endl;
    // A.start();
    // B.start();
    



    // Join Threads
    // A.join();
    B.join();
    // C.join();

    std::cout << "Task B finished with execution time: " << B.execTime_ms() << " ms." << std::endl;

    // std::cout << "Task A finished" << std::endl;
    // std::cout << "Task B finished" << std::endl;
    // std::cout << "Task C finished" << std::endl;

    // std::cout << "Lap 1 = " << lap1 << std::endl;
    // std::cout << "Lap 2 = " << lap2 << std::endl;





    return 0;

}
