#include "Thread.h"

Thread::Thread()
{
    started = false;
}

Thread::~Thread()
{
}

void Thread::start()
{
    if(! started)
    {
        started = true;
        startTime_ts = timespec_now();
        PosixThread::start(call_run, (void*) this);
        stopTime_ts = timespec_now();
    }
}

void Thread::join()
{
    PosixThread::join();
    stopTime_ts = timespec_now();
}

void* Thread::call_run(void* v_thread)
{
    Thread* thread = (Thread*) v_thread;
    thread->run();
    return (void*) thread;
}

void Thread::sleep_ms(double delay_ms)
{
    timespec_wait(timespec_from_ms(delay_ms));
}

double Thread::startTime_ms()
{
    return timespec_to_ms(startTime_ts);
}

double Thread::stopTime_ms()
{
    return timespec_to_ms(stopTime_ts);
}

double Thread::execTime_ms()
{
    return timespec_to_ms(stopTime_ts - startTime_ts);
}
