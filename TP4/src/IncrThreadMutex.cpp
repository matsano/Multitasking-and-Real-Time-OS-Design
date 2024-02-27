#include "IncrThreadMutex.h"

IncrThreadMutex::IncrThreadMutex(Data* data, Mutex& m) : mutex(m), incrMutexData(data)
{
}

IncrThreadMutex::~IncrThreadMutex()
{
}

void IncrThreadMutex::run()
{
    for(unsigned int i=0; i < incrMutexData->nLoops; i++)
    {
        Mutex::Lock lock(mutex);
        incrMutexData->pCounter += 1.0;
        lock.~Lock();
    }
}

double IncrThreadMutex::getPCounter()
{
    return incrMutexData->pCounter;
}
