#ifndef Mutex_h_INCLUDED
#define Mutex_h_INCLUDED

#include <pthread.h>
#include "Timespec.h"

class Mutex
{
private:
	pthread_mutex_t posixId;
    pthread_cond_t posixCondId;

    void lock();
    bool lock(double timeout_ms);
    bool trylock();
    void unlock();

public:
	class Lock;
    class TryLock;
    class Monitor;

    Mutex(bool isInversionSafe);
    ~Mutex();
};

#endif
