#include <vector>
#include "CounterIncrementer.h"

int main(int, char* argv[])
{

    unsigned int nLoops = std::stoi(argv[1]);
    double counter = 0.0;

    Data data = {nLoops, counter};
    std::vector<pthread_t> incrementThread(std::stoi(argv[2]));

    // Create and start the tasks
    for (unsigned int i = 0; i < incrementThread.size(); i++)
    {
        pthread_create(&incrementThread[i], nullptr, call_incr, &data);
    }

    // Wait for the tasks to finish executing
    for (unsigned int i = 0; i < incrementThread.size(); i++)
    {
        pthread_join(incrementThread[i], nullptr);
    }

    std::cout << "Counter: " << data.pCounter << std::endl;

    return 0;
}
