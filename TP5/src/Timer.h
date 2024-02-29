#ifndef Timer_h_INCLUDED
#define Timer_h_INCLUDED

#include <signal.h>
#include "Timespec.h"


class Timer
{
private:
    timer_t tid;
    static void call_callback(int, siginfo_t* si, void*);

protected:
    virtual void callback() = 0;

public:
    Timer();
    ~Timer();
    void start(double duration_ms, bool isPeriodic);
    void stop();


};

#endif
