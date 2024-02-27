#ifndef ProducerThread_h_INCLUDED
#define ProducerThread_h_INCLUDED

#include "Thread.h"
#include "Semaphore.h"

class ProducerThread : public Thread
{
private:
    Semaphore *semaphore;

    void run();

public :
	ProducerThread(Semaphore* sem);

};

#endif
