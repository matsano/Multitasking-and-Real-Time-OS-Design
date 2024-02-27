#ifndef IncrThread_h_INCLUDED
#define IncrThread_h_INCLUDED

#include "Thread.h"

struct Data
{
    volatile unsigned int nLoops;
    volatile double pCounter;
};

class IncrThread : public Thread
{
private:
	Data* incrData;

public :
	IncrThread(Data* data);
	~IncrThread();

	void run();
	double getPCounter();
};

#endif