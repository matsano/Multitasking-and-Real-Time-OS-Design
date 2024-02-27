#ifndef Moitor_h_INCLUDED
#define Monitor_h_INCLUDED

#include <exception>
#include "Mutex.h"

class Mutex::Monitor
{
protected:
    Mutex& mutex;
    
    Monitor(Mutex& m);

public:
    class TimeoutException;

    void wait();
    bool wait(double timeout_ms);
    void notify();
    void notifyAll();
};

class Mutex::Monitor::TimeoutException : public std::exception
{
public:
    const char* what() const noexcept override;
};

#endif