#include "IncrThread.h"

IncrThread::IncrThread(Data* data) : incrData(data)
{
}

IncrThread::~IncrThread()
{
}

void IncrThread::run()
{
    for(unsigned int i=0; i < incrData->nLoops; i++)
    {
        incrData->pCounter += 1.0;
    }
}

double IncrThread::getPCounter()
{
    return incrData->pCounter;
}


