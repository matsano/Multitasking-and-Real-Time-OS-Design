#include "PriorityThread.h"

PriorityThread::PriorityThread(int priorityThread, double execTime, double delay, double initTimeMutex, double durationMutex, bool canUseMutex, Mutex *mux, CpuLoop *loop) : priority(priorityThread), executionTime(execTime), delayTime(delay), timeMutexRequired(initTimeMutex), durationTimeMutex(durationMutex), mutex(mux), cpuLoop(loop), availableMutex(canUseMutex)
{
    setScheduling(SCHED_RR, priorityThread);
}

PriorityThread::PriorityThread(int priorityThread, double execTime, double delay, bool canUseMutex, CpuLoop *loop) : priority(priorityThread), executionTime(execTime), delayTime(delay), cpuLoop(loop), availableMutex(canUseMutex)
{
    setScheduling(SCHED_RR, priorityThread);
}

PriorityThread::~PriorityThread()
{
}

void PriorityThread::run()
{
    std::cout << "Run is working" << std::endl;
    // If the thread can use the mutex
    if (availableMutex)
    {
        // Thread waits to get the mutex
        cpuLoop->runTime(timeMutexRequired*1000);

        // Mutex locked
        Mutex::Lock lock(*mutex);
        std::cout << "With Mutex: " << priority << " (Thread's priority)" << std::endl;

        // Stay with mutex during a period of time
        cpuLoop->runTime(durationTimeMutex*1000);

        // Unlock mutex
        lock.~Lock();
        std::cout << "No Mutex: " << priority << " (Thread's priority)" << std::endl;

        // Run the rest time
        cpuLoop->runTime((executionTime - timeMutexRequired - durationTimeMutex)*1000);
    }
    else
    {
        // Run the execution time
        std::cout << "No Mutex: " << priority << " (Thread's priority)" << std::endl;
        cpuLoop->runTime(executionTime*1000);
    }
}
