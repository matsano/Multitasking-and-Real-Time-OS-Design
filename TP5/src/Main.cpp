#include <thread>
#include "ExampleThread.h"
#include "Calibrator.h"
#include "CpuLoop.h"
#include "Chrono.h"

int main(int, char*argv[])
{
    // Use only one thread

    cpu_set_t cpuSet;
    // Initially there is no CPU core selected
    CPU_ZERO(&cpuSet);
    // The threads that will be created later will only be executed on the first CPU core
    CPU_SET(0, &cpuSet);
    // Setting the CPU affinity of the current process to run on only CPU 0
    sched_setaffinity(0, sizeof(cpu_set_t), &cpuSet);

    // Choose a single scheduling policy for all tasks
    struct sched_param schedParam;
    schedParam.sched_priority = sched_get_priority_max(SCHED_RR);
    if (pthread_setschedparam(pthread_self(), SCHED_RR, &schedParam) < 0)
    {
        std::cerr << "Error in pthread_setschedparam" << std::endl;
    }


    // Verify if there is a priority inversion
    std::string priorityInversion(argv[1]);
    bool doPriorityInv = false;
    if (priorityInversion == "true")
    {
        doPriorityInv = true;
    }
    else if (priorityInversion == "false")
    {
        doPriorityInv = false;
    }

    Mutex R(doPriorityInv);


    // Set the CPU loops
    Calibrator calibrator(200, 5);
    CpuLoop cpuLoopA(calibrator);
    CpuLoop cpuLoopB(calibrator);
    CpuLoop cpuLoopC(calibrator);

    // Set the 3 tasks (A, B and C) and the mutex (R)
    int priorityA = 90;
    double execTimeA = 4;
    double timeCallMutexA = 1;
    double durationMutexA = 1;
    bool canUseMutexA = true;

    int priorityB = 50;
    double execTimeB = 1;
    bool canUseMutexB = false;

    int priorityC = 25;
    double execTimeC = 5;
    double timeCallMutexC = 2;
    double durationMutexC = 2;
    bool canUseMutexC = true;

    ExampleThread A(priorityA, execTimeA, timeCallMutexA, durationMutexA, canUseMutexA, &R, &cpuLoopA);
    ExampleThread B(priorityB, execTimeB, canUseMutexB, &cpuLoopB);
    ExampleThread C(priorityC, execTimeC, timeCallMutexC, durationMutexC, canUseMutexC, &R, &cpuLoopC);


    // Start scenario
    std::cout << "Activating tasks..." << std::endl;
    C.start();
    
    timespec_wait(timespec_from_ms(3000));

    A.start();
    B.start();
    
    // Join Threads
    A.join();
    B.join();
    C.join();

    // Calculate execution time of the threads
    double finalExecTimeA = A.execTime_ms();
    double finalExecTimeB = B.execTime_ms();
    double finalExecTimeC = C.execTime_ms();

    std::cout << "\nFinal order of the threads:" << std::endl;

    if (finalExecTimeA <= finalExecTimeB && finalExecTimeA <= finalExecTimeC) {
        std::cout << "Task A finished with execution time: " << finalExecTimeA << " ms." << std::endl;
        if (finalExecTimeB <= finalExecTimeC) {
            std::cout << "Task B finished with execution time: " << finalExecTimeB << " ms." << std::endl;
            std::cout << "Task C finished with execution time: " << finalExecTimeC << " ms." << std::endl;
        } else {
            std::cout << "Task C finished with execution time: " << finalExecTimeC << " ms." << std::endl;
            std::cout << "Task B finished with execution time: " << finalExecTimeB << " ms." << std::endl;
        }
    } else if (finalExecTimeB <= finalExecTimeA && finalExecTimeB <= finalExecTimeC) {
        std::cout << "Task B finished with execution time: " << finalExecTimeB << " ms." << std::endl;
        if (finalExecTimeA <= finalExecTimeC) {
            std::cout << "Task A finished with execution time: " << finalExecTimeA << " ms." << std::endl;
            std::cout << "Task C finished with execution time: " << finalExecTimeC << " ms." << std::endl;
        } else {
            std::cout << "Task C finished with execution time: " << finalExecTimeC << " ms." << std::endl;
            std::cout << "Task A finished with execution time: " << finalExecTimeA << " ms." << std::endl;
        }
    } else {
        std::cout << "Task C finished with execution time: " << finalExecTimeC << " ms." << std::endl;
        if (finalExecTimeA <= finalExecTimeB) {
            std::cout << "Task A finished with execution time: " << finalExecTimeA << " ms." << std::endl;
            std::cout << "Task B finished with execution time: " << finalExecTimeB << " ms." << std::endl;
        } else {
            std::cout << "Task B finished with execution time: " << finalExecTimeB << " ms." << std::endl;
            std::cout << "Task A finished with execution time: " << finalExecTimeA << " ms." << std::endl;
        }
    }

    return 0;

}
