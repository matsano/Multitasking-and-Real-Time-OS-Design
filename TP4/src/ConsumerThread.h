#ifndef ConsumerThread_h_INCLUDED
#define ConsumerThread_h_INCLUDED

#include "Thread.h"
#include "Semaphore.h"

class ConsumerThread : public Thread
{
private:
	Semaphore *semaphore;

    void run();

public :
	ConsumerThread(Semaphore* sem);
    
};

#endif