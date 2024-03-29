#ifndef PosixThread_h_INCLUDED
#define PosixThread_h_INCLUDED

#include <iostream>
#include <exception>
#include <pthread.h>
#include "Timespec.h"

class PosixThread
{
private:
    pthread_t posixId;
    pthread_attr_t posixAttr;
    int policyThread;
    int priorityThread;

protected:
    bool isActive;

public:
    PosixThread();
    PosixThread(pthread_t posixId);
    ~PosixThread();
    void start(void*(*threadFunc)(void*), void* threadArg);
    void join();
    bool join(double timeout_ms);
    bool setScheduling(int schedPolicy, int priority);
    bool getScheduling(int* pSchedPolicy, int* pPriority);

};

#endif
