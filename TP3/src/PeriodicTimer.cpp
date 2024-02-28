#include "PeriodicTimer.h"

void PeriodicTimer::start(double duration_ms)
{
    Timer::start(duration_ms, true);
}
