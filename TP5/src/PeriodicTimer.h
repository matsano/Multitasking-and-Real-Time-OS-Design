#ifndef PeriodicTimer_h_INCLUDED
#define PeriodicTimer_h_INCLUDED

#include "Timer.h"


class PeriodicTimer : public Timer
{
    
public:
    void start(double duration_ms);

};

#endif
