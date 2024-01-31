#include "Chrono.h"

Chrono::Chrono()
{
    restart();
}


void Chrono::stop()
{
    m_stopTime = timespec_now();
}


void Chrono::restart()
{
    m_startTime = timespec_now();
    m_stopTime = timespec_now();
}


bool Chrono::isActive()
{
    return (m_stopTime.tv_sec == m_startTime.tv_sec);
}


double Chrono::lab()
{
    double labTime_ms;

    if (isActive())
    {
        labTime_ms = timespec_to_ms(timespec_now() - m_startTime);
    }
    else
    {
        labTime_ms = timespec_to_ms(m_stopTime - m_startTime);
    }

    return labTime_ms;
}
