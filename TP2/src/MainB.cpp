#include <vector>
#include "CounterIncrementer.h"

int main(int, char* argv[])
{

    unsigned int nLoops = std::stoi(argv[1]);

    // Verify if the increment of counter must be protected by a mutex
    std::string protectedMutex(argv[3]);
    
    timespec initTime, finalTime, execTime;
    double counter = 0.0;
    pthread_mutex_t mutex;

    Data data = {nLoops, counter, mutex};
    std::vector<pthread_t> incrementThread(std::stoi(argv[2]));

    // Create and start the tasks
    if (protectedMutex == "protected")
    {
        // Construct the mutex
        pthread_mutex_init(&data.mutex, nullptr);
        for (unsigned int i = 0; i < incrementThread.size(); i++)
        {
            pthread_create(&incrementThread[i], nullptr, call_incrMutex, &data);
        }
    }
    else
    {
        for (unsigned int i = 0; i < incrementThread.size(); i++)
        {
            pthread_create(&incrementThread[i], nullptr, call_incr, &data);
        }
    }

    initTime = timespec_now();
    // Wait for the tasks to finish executing
    for (unsigned int i = 0; i < incrementThread.size(); i++)
    {
        pthread_join(incrementThread[i], nullptr);
    }
    finalTime = timespec_now();
    execTime = finalTime - initTime;

    // Destroy the mutex
    if (protectedMutex == "protected")
    {
        pthread_mutex_destroy(&data.mutex);
    }
    

    std::cout << "Counter: " << data.pCounter << std::endl;
    std::cout << "Execution time: " << (timespec_to_ms(execTime)/1000) << " s" << std::endl;

    return 0;
}
