#include "CounterIncrementer.h"

void incr(unsigned int nLoops, double* pCounter)
{
    for (unsigned int iLoop = 0; iLoop < nLoops; iLoop++)
    {
        *pCounter = *pCounter + 1;
    }
}


unsigned incr(unsigned int nLoops, double* pCounter, bool* pStop)
{
    unsigned int iLoop;

    for (iLoop = 0; iLoop < nLoops; iLoop++)
    {
        if (*pStop)
        {
            break;
        }
        *pCounter = *pCounter + 1;
    }

    return iLoop;
}


void myHandler(int, siginfo_t* si, void*)
{
    bool* stop = (bool*) si->si_value.sival_ptr;
    *stop = true;
}


unsigned timerIncrementer(unsigned int nLoops, bool pStop, double periodSec, double periodNSec)
{

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void*) &pStop;

    timer_t tid;
    timer_create(CLOCK_REALTIME, &sev, &tid);
    itimerspec its;
    its.it_value.tv_sec = periodSec;
    its.it_value.tv_nsec = periodNSec;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;

    double counter = 0.0;
    timer_settime(tid, 0, &its, nullptr);
    unsigned finalNLoops = incr(nLoops, &counter, &pStop);
    timer_delete(tid);

    return finalNLoops;
}


struct parameters calib(unsigned int nLoops, bool pStop, timespec initTime, timespec finalTime)
{
    struct parameters params;
    unsigned initL = timerIncrementer(nLoops, pStop, initTime.tv_sec, initTime.tv_nsec);
    unsigned finalL = timerIncrementer(nLoops, pStop, finalTime.tv_sec, finalTime.tv_nsec);

    params.a = (finalL - initL) / (timespec_to_ms(timespec_subtract(finalTime, initTime))/1000);
    params.b = finalL - (timespec_to_ms(finalTime) / 1000) * params.a;

    return params;
}


struct parameters calibImproved(unsigned int nLoops, bool pStop)
{
    // Least Squares Method
    struct parameters params;
    unsigned l;
    std::vector<std::tuple<double, unsigned>> valuesLT;

    // Generate more measurements
    int initT = 3;
    int finalT = 10;
    for (int t = initT; t < finalT; t++)
    {
        l = timerIncrementer(nLoops, pStop, t, 0);
        valuesLT.push_back(std::make_tuple(t, l));
    }

    // Calculate the averages
    double meanL = 0.0;
    double meanT = 0.0;
    for (const auto& tuple : valuesLT)
    {
        meanT = meanT + std::get<0>(tuple);
        meanL = meanL + std::get<1>(tuple);
    }
    meanT = meanT / valuesLT.size();
    meanL = meanL / valuesLT.size();

    // Calculate Sxy and Sxx
    double Sxx = 0.0;
    double Sxy = 0.0;
    for (const auto& tuple : valuesLT)
    {
        Sxy += (std::get<0>(tuple) - meanT) * (std::get<1>(tuple) - meanL);
        Sxx += std::pow((std::get<0>(tuple) - meanT), 2);
    }

    // Calculate the parameters a and b
    params.a = Sxy / Sxx;
    params.b = meanL - params.a * meanT;

    return params;
}
