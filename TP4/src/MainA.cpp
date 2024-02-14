#include "IncrThread.h"

int main(int, char*argv[])
{
    unsigned int nLoops = std::stoi(argv[1]);
    unsigned int nTasks = std::stoi(argv[2]);

    double totalExecTime_ms = 0.0;
    double totalCounter = 0.0;

    // Create nTasks threads
    IncrThread* threads[nTasks];
    for (unsigned int i = 0; i < nTasks; i++)
    {
        threads[i] = new IncrThread(nLoops);
    }

    // Start the threads
    for (unsigned int i = 0; i < nTasks; i++)
    {
        threads[i]->start();
        totalExecTime_ms += threads[i]->execTime_ms();
    }

    // Join the threads
    for (unsigned int i = 0; i < nTasks; i++)
    {
        std::cout << "Counter" << "[" << i << "] = " << threads[i]->getData().pCounter << std::endl;
        totalCounter += threads[i]->getData().pCounter;
        threads[i]->join();
    }

    std::cout << "Counter: " << totalCounter << std::endl;
    std::cout << "Total execution time (all threads) : " << totalExecTime_ms << " ms" << std::endl;

    return 0;
}
