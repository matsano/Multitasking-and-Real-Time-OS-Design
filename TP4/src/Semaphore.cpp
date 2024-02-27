#include "Semaphore.h"

Semaphore::Semaphore(unsigned initCount, unsigned maxCount) : counter(initCount), maxCount(maxCount)
{
}

void Semaphore::give()
{
    Mutex::Lock lock(mutex);

    if (counter < maxCount)
    {
        counter += 1;
    }

    lock.notify();
    lock.~Lock();
}

void Semaphore::take()
{
    Mutex::Lock lock(mutex);

    if (counter > 0)
    {
        counter -= 1;
    }
    else
    {
        // If the semaphore token counter is zero, the function is blocked
        lock.wait();
    }

    lock.notify();
    lock.~Lock();
}

bool Semaphore::take(double timeout_ms)
{
    try
    {
        Mutex::Lock lock(mutex, timeout_ms);
        while (counter = 0)
        {
            if (! lock.wait(timeout_ms))
            {
                return false;
            }
        }
        counter -= 1;
        return true;
    }
    catch(const Mutex::Monitor::TimeoutException&)
    {
        return false;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const std::string& errmsg)
    {
        std::cerr << "Exception: " << errmsg << std::endl;
    }
    catch(...)
    {
        std::cerr << "Unkown Exception" << std::endl;
    }

    return false;
    
}

unsigned Semaphore::getCounter()
{
    return counter;
}
