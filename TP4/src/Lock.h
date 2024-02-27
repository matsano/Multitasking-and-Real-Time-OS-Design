#ifndef Lock_h_INCLUDED
#define Lock_h_INCLUDED

#include "Monitor.h"

class Mutex::Lock : public Monitor
{
public:
    Lock(Mutex& m);
    Lock(Mutex& m, double timeout_ms);
    ~Lock();
};

#endif