#include "ConsumerThread.h"

ConsumerThread::ConsumerThread(Semaphore* sem) : semaphore(sem)
{
}

void ConsumerThread::run()
{
    semaphore->take();
}
