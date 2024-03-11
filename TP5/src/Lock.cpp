#include "Lock.h"

Mutex::Lock::Lock(Mutex& m) : Monitor(m)
{
    m.lock();
}

Mutex::Lock::Lock(Mutex& m, double timeout_ms) : Monitor(m)
{
    if (! m.lock(timeout_ms))
    {
        throw Monitor::TimeoutException();
    }
}

Mutex::Lock::~Lock()
{
    mutex.unlock();
}
