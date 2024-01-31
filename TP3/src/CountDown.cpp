#include "CountDown.h"

CountDown::CountDown(int n)
{
    nCount = n;
}


void CountDown::callback()
{
    std::cout << "Counter (CountDown) = " << nCount << std::endl;
    nCount --;
}

int CountDown::getNCount()
{
    return nCount;
}
