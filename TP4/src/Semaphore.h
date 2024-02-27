#ifndef Semaphore_h_INCLUDED
#define Semaphore_h_INCLUDED

#include "Lock.h"

class Semaphore
{
private:
    unsigned counter;
    unsigned maxCount;
    Mutex mutex;

public:
	Semaphore(unsigned initCount = 0, unsigned maxCount = __UINT32_MAX__);
    void give();
    void take();
    bool take(double timeout_ms);
    unsigned getCounter();
};

#endif
