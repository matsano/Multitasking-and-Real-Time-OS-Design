#ifndef CounterIncrementer_h_INCLUDED
#define CounterIncrementer_h_INCLUDED

#include <climits>
#include <signal.h>
#include <time.h>
#include <vector>
#include <tuple>
#include <cmath>
#include "Timespec.h"

struct Data
{
    volatile unsigned int nLoops;
    volatile double pCounter;
    pthread_mutex_t mutex;
};

void incr(unsigned int nLoops, double* pCounter);

void* call_incr(void* v_data);

void* call_incrMutex(void* v_data);

#endif