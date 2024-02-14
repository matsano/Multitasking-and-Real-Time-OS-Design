#ifndef IncrThread_h_INCLUDED
#define IncrThread_h_INCLUDED

#include "Thread.h"
#include <time.h>

struct Data
{
    volatile unsigned int nLoops;
    volatile double pCounter;
};

class IncrThread : public Thread
{
private:
	Data data;

public :
	IncrThread(unsigned int numberLoops);
	~IncrThread();

	void run();
	Data getData();
};

#endif