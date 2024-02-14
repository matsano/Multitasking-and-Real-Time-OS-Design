#include "IncrThread.h"

IncrThread::IncrThread(unsigned int numberLoops)
{
    data.nLoops = numberLoops;
    data.pCounter = 0;

}

IncrThread::~IncrThread()
{

}

void IncrThread::run()
{
    for(unsigned int i=0; i < data.nLoops; i++)
    {
        data.pCounter += 1.0;
    }
}

Data IncrThread::getData()
{
    return data;
}


