#include "Timer.h"

void myHandler(int, siginfo_t* si, void*)
{
    int* myCounter = (int*) si->si_value.sival_ptr;
    *myCounter = *myCounter + 1;
    std::cout << "Incremented counter: " << *myCounter << std::endl;
}

void timerPOSIX()
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    struct sigevent sev;
    volatile int counter = 0;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void*) &counter;

    timer_t tid;
    timer_create(CLOCK_REALTIME, &sev, &tid);
    itimerspec its;
    // A periodic Posix timer with a frequency of 2 Hz (0,5 s)
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = 500000000;
    its.it_interval = its.it_value;

    timer_settime(tid, 0, &its, nullptr);

    while (true)
    {
        if (counter == 15)
        {
            break;
        }
    }
    
    timer_delete(tid);
}
