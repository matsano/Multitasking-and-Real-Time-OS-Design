#include "ProducerThread.h"

ProducerThread::ProducerThread(Semaphore* sem) : semaphore(sem)
{
}

void ProducerThread::run()
{
    semaphore->give();
}
