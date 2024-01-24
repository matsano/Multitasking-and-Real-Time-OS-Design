#ifndef CounterIncrementer_h_INCLUDED
#define CounterIncrementer_h_INCLUDED

#include <climits>
#include <signal.h>
#include <time.h>
#include <vector>
#include <tuple>
#include <cmath>
#include "Timespec.h"

struct parameters
{
    double a;
    double b;
};

void incr(unsigned int nLoops, double* pCounter);

unsigned incr(unsigned int nLoops, double* pCounter, bool* pStop);

void myHandler(int, siginfo_t* si, void*);

unsigned timerIncrementer(unsigned int nLoops, bool pStop, double periodSec, double periodNSec);

struct parameters calib(unsigned int nLoops, bool pStop, timespec initTime, timespec finalTime);

struct parameters calibImproved(unsigned int nLoops, bool pStop);

#endif