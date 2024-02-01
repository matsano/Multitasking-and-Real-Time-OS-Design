#include "Timespec.h"

// Convert timespec to milliseconds
double timespec_to_ms(const timespec& time_ts)
{
    return time_ts.tv_sec * 1000.0 + time_ts.tv_nsec / 1e6;
}

// Convert milliseconds to timespec
timespec timespec_from_ms(double time_ms)
{
    struct timespec time_ts;
    if (time_ms < 0)
    {
        // Round down tv_sec so that tv_nsec is positive
        time_ts.tv_sec = (time_ms / 1000) - 1;
    } else
    {
        time_ts.tv_sec = time_ms / 1000;
    }
    
    time_ts.tv_nsec = (time_ms - (time_ts.tv_sec * 1000)) * 1e6;
    return time_ts;
}


// Get current time
timespec timespec_now()
{
    struct timespec timeNow;
    clock_gettime(CLOCK_REALTIME, &timeNow);
    return timeNow;
}


// Get opposite of a time
timespec timespec_negate(const timespec& time_ts)
{
    timespec timeNegative_ts;
    // Round down tv_sec so that tv_nsec is positive
    timeNegative_ts.tv_sec = -time_ts.tv_sec - 1;
    
    timeNegative_ts.tv_nsec = 1e9 - time_ts.tv_nsec;
    
    return timeNegative_ts;
}

// Add two timespec
timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts)
{
    struct timespec resultTime_ts;
    
    double result_sec = time1_ts.tv_sec + time2_ts.tv_sec;
    double result_nsec = time1_ts.tv_nsec + time2_ts.tv_nsec;

    if (result_nsec >= 1e9)
    {
        result_nsec = result_nsec - 1e9;
        result_sec = result_sec + 1;
    }

    resultTime_ts.tv_sec = result_sec;
    resultTime_ts.tv_nsec = result_nsec;
    
    return resultTime_ts;
}

// Subtract two timespec
timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts)
{
    struct timespec resultTime_ts;

    double result_sec = time1_ts.tv_sec - time2_ts.tv_sec;
    double result_nsec = time1_ts.tv_nsec - time2_ts.tv_nsec;

    if (result_nsec < 0)
    {
        result_sec = result_sec - 1;
        result_nsec = 1e9 + result_nsec;
    }

    resultTime_ts.tv_sec = result_sec;
    resultTime_ts.tv_nsec = result_nsec;

    return resultTime_ts;
}

// Put a task to sleep for a specified time
timespec timespec_wait(const timespec& delay_ts)
{
    struct timespec remainingTime_ts;

    if (nanosleep(&delay_ts, &remainingTime_ts) == -1)
    {
        // If the call is interrupted by a signal handler or encounters an error, then it returns -1, with errno set to indicate the error.
        switch (errno)
        {
        case EFAULT:
            std::cout << "Problem with copying information from user space." << std::endl;
            break;

        case EINTR:
            std::cout << "The pause has been interrupted by a signal that was delivered to the thread." << std::endl;
            break;

        case EINVAL:
            std::cout << "The value in the tv_nsec field was not in the range [0, 999999999] or tv_sec was negative." << std::endl;
            break;
        
        default:
            std::cout << "Problem with reading information." << std::endl;
            break;
        }
    } else
    {
        // on successfully sleeping for the requested interval, nanosleep() returns 0
        remainingTime_ts.tv_sec = 0;
        remainingTime_ts.tv_nsec = 0;
    }

    return remainingTime_ts;
}

timespec operator- (const timespec& time_ts)
{
    return timespec_negate(time_ts);
}

timespec operator+ (const timespec& time1_ts, const timespec& time2_ts)
{
    return timespec_add(time1_ts, time2_ts);
}

timespec operator- (const timespec& time1_ts, const timespec& time2_ts)
{
    return timespec_subtract(time1_ts, time2_ts);
}

timespec& operator+= (timespec& time_ts, const timespec& delay_ts)
{
    time_ts = timespec_add(time_ts, delay_ts);
    return time_ts;
}

timespec& operator-= (timespec& time_ts, const timespec& delay_ts)
{
    time_ts = timespec_subtract(time_ts, delay_ts);
    return time_ts;
}

bool operator== (const timespec& time1_ts, const timespec& time2_ts)
{
    return ((time1_ts.tv_sec == time2_ts.tv_sec) && (time1_ts.tv_nsec == time2_ts.tv_nsec));
}

bool operator!= (const timespec& time1_ts, const timespec& time2_ts)
{
    return ((time1_ts.tv_sec != time2_ts.tv_sec) || (time1_ts.tv_nsec != time2_ts.tv_nsec));
}

bool operator< (const timespec& time1_ts, const timespec& time2_ts)
{
    return ((time1_ts.tv_sec < time2_ts.tv_sec) || ((time1_ts.tv_sec == time2_ts.tv_sec) && (time1_ts.tv_nsec < time2_ts.tv_nsec)));
}

bool operator> (const timespec& time1_ts, const timespec& time2_ts)
{
    return ((time1_ts.tv_sec > time2_ts.tv_sec) || ((time1_ts.tv_sec == time2_ts.tv_sec) && (time1_ts.tv_nsec > time2_ts.tv_nsec)));
}
