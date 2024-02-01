#include "CounterIncrementer.h"

void incr(volatile unsigned int nLoops, volatile double* pCounter)
{
    for (unsigned int iLoop = 0; iLoop < nLoops; iLoop++)
    {
        *pCounter = *pCounter + 1;
    }
}

void incrMutex(volatile unsigned int nLoops, volatile double* pCounter, pthread_mutex_t* mutex)
{
    for (unsigned int iLoop = 0; iLoop < nLoops; iLoop++)
    {
        pthread_mutex_lock(mutex);
        *pCounter = *pCounter + 1;
        pthread_mutex_unlock(mutex);
    }
}

void* call_incr(void* v_data)
{
    Data* p_data = (Data*) v_data;
    incr(p_data->nLoops, &p_data->pCounter);
    
    return v_data;
}

void* call_incrMutex(void* v_data)
{
    Data* p_data = (Data*) v_data;
    incrMutex(p_data->nLoops, &p_data->pCounter, &p_data->mutex);
    
    return v_data;
}
