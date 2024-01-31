#include <unistd.h>
#include "Chrono.h"

int main()
{
    double labActivated_ms, labDeactivated_ms;
    
    std::cout << "Initialize the chronometer..." << std::endl;
    std::cout << "Waiting 10 secondes..." << std::endl;
    // Chronometer initialization
    Chrono chronometer;
    chronometer.restart();

    // Wait for 10 seconds
    sleep(10);

    // Get lab time while chronometer is activated
    labActivated_ms = chronometer.lab();
    std::cout << "Lab time (chronometer activated): " << labActivated_ms << " ms\n" << std::endl;

    // Wait for 10 seconds
    std::cout << "Waiting 10 secondes..." << std::endl;
    sleep(10);

    // Stop chronometer
    chronometer.stop();

    // Get lab time when chronometer is desactive
    labDeactivated_ms = chronometer.lab();

    std::cout << "Deactivate the chronometer..." << std::endl;
    std::cout << "Lab time (chronometer deactivated): " << labDeactivated_ms << " ms\n" << std::endl;

    // Test the restart() function
    std::cout << "Restart the chronometer..." << std::endl;
    std::cout << "Waiting 5 secondes..." << std::endl;

    // Restart the chronometer
    chronometer.restart();

    // Wait for 5 seconds
    sleep(5);

    // Stop chronometer
    chronometer.stop();

    // Get lab time when chronometer is desactive
    labDeactivated_ms = chronometer.lab();

    std::cout << "Deactivate the chronometer..." << std::endl;
    std::cout << "Lab time (chronometer deactivated): " << labDeactivated_ms << " ms" << std::endl;


    return 0;
}
