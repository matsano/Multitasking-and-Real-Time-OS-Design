#ifndef CountDown_h_INCLUDED
#define CountDown_h_INCLUDED

#include "Timer.h"

class CountDown : public Timer
{
private:
    int nCount;
    void callback();

public:
    CountDown(int n);
    int getNCount();

};

#endif
