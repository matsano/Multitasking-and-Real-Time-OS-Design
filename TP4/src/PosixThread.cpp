#include "PosixThread.h"


PosixThread::PosixThread() : posixId(0), isActive(false)
{
    pthread_attr_init(&posixAttr);
    pthread_attr_setinheritsched(&posixAttr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&posixAttr, SCHED_OTHER);
    sched_param schedParam;
    schedParam.sched_priority = 0;
    pthread_attr_setschedparam(&posixAttr, &schedParam);
}

PosixThread::PosixThread(pthread_t posixId) : posixId(posixId), isActive(true)
{
    pthread_attr_init(&posixAttr);
    pthread_attr_setinheritsched(&posixAttr, PTHREAD_EXPLICIT_SCHED);
    sched_param schedParam;
    int policy= SCHED_RR;
    int param = pthread_getschedparam(this->posixId, &policy, &schedParam);
    if (param < 0)
    {
        isActive = false;
        posixId = 0;
    }
    else
    {
    	isActive = true;
        pthread_attr_setschedparam(&posixAttr, &schedParam);
    	pthread_attr_setschedpolicy(&posixAttr, policy);
    }
}

PosixThread::~PosixThread()
{
    pthread_attr_destroy(&posixAttr);
}

void PosixThread::start(void*(*threadFunc)(void*), void* threadArg)
{
    isActive = true;
    pthread_create(&posixId, &posixAttr, threadFunc, threadArg);

}

void PosixThread::join()
{
    pthread_join(posixId, NULL);
}

bool PosixThread::join(double timeout_ms)
{
    timespec timeout_ts(timespec_from_ms(timeout_ms));

    return pthread_timedjoin_np(posixId, NULL, &timeout_ts);
}

bool PosixThread::setScheduling(int schedPolicy, int priority)
{
    sched_param schedParam;
    schedParam.sched_priority = priority; 
    
    // Distinguish the two cases where the thread is already active or not
    if(isActive)
    {
        pthread_setschedparam(posixId, schedPolicy, &schedParam);
    }
    else
    {
        pthread_attr_setschedpolicy(&posixAttr, schedPolicy);
        pthread_attr_setschedparam(&posixAttr, &schedParam);
    }

    return isActive;
}

bool PosixThread::getScheduling(int* pSchedPolicy, int* pPriority)
{
    sched_param schedParam;
    *pPriority = schedParam.sched_priority;

    // Distinguish the two cases where the thread is already active or not
    if(isActive)
    {
        pthread_getschedparam(posixId, pSchedPolicy, &schedParam);
    }
    else
    {
        pthread_attr_getschedpolicy(&posixAttr, pSchedPolicy);
        pthread_attr_getschedparam(&posixAttr, &schedParam);
    }

    return isActive;
}
