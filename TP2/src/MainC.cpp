#include "CounterIncrementer.h"

int main(int argc, char* argv[])
{

    unsigned int nLoops = std::stoi(argv[1]);
    double counter = 0.0;
    timespec initTime, finalTime, execTime;

    initTime = timespec_now();
    incr(nLoops, &counter);
    finalTime = timespec_now();
    execTime = finalTime - initTime;

    std::cout << "Counter: " << counter << std::endl;
    std::cout << "Execution time: " << (timespec_to_ms(execTime)/1000) << " s" << std::endl;

    return 0;
}
