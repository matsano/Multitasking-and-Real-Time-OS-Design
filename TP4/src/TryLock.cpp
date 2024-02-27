#include "TryLock.h"

Mutex::TryLock::TryLock(Mutex& m) : Monitor(m)
{
    if (! m.trylock())
    {
        throw Monitor::TimeoutException();
    }
}

Mutex::TryLock::~TryLock()
{
    mutex.unlock();
}
