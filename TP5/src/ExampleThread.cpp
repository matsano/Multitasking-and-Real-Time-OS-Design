#include "ExampleThread.h"

ExampleThread::ExampleThread(int priorityThread, double execTime, double initTimeMutex, double durationMutex, bool canUseMutex, Mutex *mux, CpuLoop *loop) : priority(priorityThread), executionTime(execTime), timeMutexRequired(initTimeMutex), durationTimeMutex(durationMutex), mutex(mux), cpuLoop(loop), canUseMutex(canUseMutex)
{
    setScheduling(SCHED_RR, priorityThread);
}

ExampleThread::ExampleThread(int priorityThread, double execTime, bool canUseMutex, CpuLoop *loop) : priority(priorityThread), executionTime(execTime), cpuLoop(loop), canUseMutex(canUseMutex)
{
    setScheduling(SCHED_RR, priorityThread);
}

void ExampleThread::run()
{
    // If the thread can use the mutex
    if (canUseMutex)
    {
        // Thread waits to get the mutex
        cpuLoop->runTime(timeMutexRequired*1000);

        // Critical section
        {
            // Mutex locked
            Mutex::Lock lock(*mutex);

            // Stay with mutex during a period of time
            cpuLoop->runTime(durationTimeMutex*1000);

            // Unlock mutex
        }

        // Run the rest time
        cpuLoop->runTime((executionTime - timeMutexRequired - durationTimeMutex)*1000);
    }
    else
    {
        // Run the execution time
        cpuLoop->runTime(executionTime*1000);
    }
}
