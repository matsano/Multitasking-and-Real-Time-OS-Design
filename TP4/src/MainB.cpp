#include "IncrThreadMutex.h"

int main(int, char*argv[])
{
    unsigned int nLoops = std::stoi(argv[1]);
    unsigned int nTasks = std::stoi(argv[2]);
    Data data = {nLoops, 0.0};
    Mutex mutex;

    // Create nTasks threads
    IncrThreadMutex* threads[nTasks];
    for (unsigned int i = 0; i < nTasks; i++)
    {
        threads[i] = new IncrThreadMutex(&data, mutex);
    }

    timespec initTime = timespec_now();

    // Start the threads
    for (unsigned int i = 0; i < nTasks; i++)
    {
        threads[i]->start();
    }

    // Join the threads
    for (unsigned int i = 0; i < nTasks; i++)
    {
        threads[i]->join();
    }

    timespec finalTime = timespec_now();

    std::cout << "Counter: " << threads[0]->getPCounter() << std::endl;
    std::cout << "Total execution time (all threads) : " << timespec_to_ms(finalTime - initTime) << " ms" << std::endl;

    return 0;
}
