#include "CountDown.h"

int main()
{

    std::cout << "Initialize the CountDown..." << std::endl;
    CountDown countDown(10);
    bool endCountDown = false;

    // A periodic Posix timer with a frequency of 1 Hz
    countDown.start(1000, true);
    
    while (! endCountDown)
    {
        if (countDown.getNCount() < 0)
        {
            endCountDown = true;
        }
    }

    std::cout << "Destroy the CountDown..." << std::endl;

    return 0;
}
