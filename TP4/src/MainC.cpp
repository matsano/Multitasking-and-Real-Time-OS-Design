#include <vector>
#include "ProducerThread.h"
#include "ConsumerThread.h"

int main(int, char*argv[])
{
    // Number of producer tasks
    unsigned nProd = std::stoi(argv[1]);

    // Number of consumer tasks
    unsigned nCons = std::stoi(argv[2]);

    // Maximum number of tokens
    unsigned maxTokens = std::stoi(argv[3]);

    Semaphore semaphore(0, maxTokens);

    std::vector<ConsumerThread> consumerThreads;
    std::vector<ProducerThread> producertThreads;

    for (unsigned i = 0; i < nProd; i++)
    {
        producertThreads.push_back(ProducerThread(&semaphore));
    }

    for (unsigned i = 0; i < nCons; i++)
    {
        consumerThreads.push_back(ConsumerThread(&semaphore));
    }

    std::cout << "Producer Threads trying to give " << nProd << " tokens (nMaxTokens = " << maxTokens << ")." << std::endl;

    for (unsigned i = 0; i < nProd; i++)
    {
        producertThreads[i].start();
    }

    for (unsigned i = 0; i < nProd; i++)
    {
        producertThreads[i].join();
    }

    std::cout << "Semaphore: " << semaphore.getCounter() << " tokens." << std::endl;

    std::cout << "Consumer Threads trying to take " << nCons << " tokens." << std::endl;

    for (unsigned i = 0; i < nCons; i++)
    {
        consumerThreads[i].start();
    }

    for (unsigned i = 0; i < nCons; i++)
    {
        consumerThreads[i].join();
    }

    std::cout << "Semaphore: " << semaphore.getCounter() << " tokens." << std::endl;


    return 0;
}
