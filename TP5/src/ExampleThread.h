#ifndef ExampleThread_h_INCLUDED
#define ExampleThread_h_INCLUDED

#include "Thread.h"
#include "Mutex.h"
#include "CpuLoop.h"
#include "Lock.h"

class ExampleThread : public Thread
{
private:
    int priority;
    double executionTime;
    double timeMutexRequired;
    double durationTimeMutex;
    Mutex *mutex;
    CpuLoop *cpuLoop;
    bool canUseMutex;

    void run();


public:
    ExampleThread(int priorityThread, double execTime, double initTimeMutex, double durationMutex, bool canUseMutex, Mutex *mux, CpuLoop *loop);
    ExampleThread(int priorityThread, double execTime, bool canUseMutex, CpuLoop *loop);

};

#endif
