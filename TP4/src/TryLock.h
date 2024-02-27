#ifndef TryLock_h_INCLUDED
#define TryLock_h_INCLUDED

#include "Monitor.h"

class Mutex::TryLock : public Monitor
{
public:
    TryLock(Mutex& m);
    ~TryLock();
};

#endif