#ifndef IncrThreadMutex_h_INCLUDED
#define IncrThreadMutex_h_INCLUDED

#include <time.h>
#include "Lock.h"
#include "Thread.h"


struct Data
{
    volatile unsigned int nLoops;
    volatile double pCounter;
};

class IncrThreadMutex : public Thread
{
private:
	Data* incrMutexData;
    Mutex& mutex;

public :
	IncrThreadMutex(Data* data, Mutex& m);
	~IncrThreadMutex();

	void run();
	double getPCounter();
};

#endif