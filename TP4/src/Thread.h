#ifndef Thread_h_INCLUDED
#define Thread_h_INCLUDED

#include "PosixThread.h"

class Thread : public PosixThread
{
private:
    timespec startTime_ts, stopTime_ts, execTIme_ts;
    static void* call_run(void* v_trhead);

protected:
    virtual void run() = 0;

public:
    Thread();
    ~Thread();

    void start();
    static void sleep_ms(double delay_ms);
    double startTime_ms();
    double stopTime_ms();
    double execTime_ms();

};

#endif
