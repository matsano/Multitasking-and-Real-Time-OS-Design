#ifndef PriorityThread_h_INCLUDED
#define PriorityThread_h_INCLUDED

#include "Thread.h"
#include "Mutex.h"
#include "CpuLoop.h"
#include "Lock.h"

class PriorityThread : public Thread
{
private:
    int priority;
    double executionTime;
    double delayTime;
    double timeMutexRequired;
    double durationTimeMutex;
    Mutex *mutex;
    CpuLoop *cpuLoop;
    bool availableMutex;

    void run();


public:
    PriorityThread(int priorityThread, double execTime, double delay, double initTimeMutex, double durationMutex, bool canUseMutex, Mutex *mux, CpuLoop *loop);
    PriorityThread(int priorityThread, double execTime, double delay, bool canUseMutex, CpuLoop *loop);
    ~PriorityThread();

};

#endif
