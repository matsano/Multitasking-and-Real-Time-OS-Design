#include "Timespec.h"

int main()
{

    // Test timespec_to_ms function
    std::cout << "Testing timespec_to_ms function..." << std::endl;
    struct timespec testTime;
    testTime.tv_sec = 3;
    testTime.tv_nsec = 250110000;
    double testTime_ms = timespec_to_ms(testTime);
    std::cout << "Test time (ms): " << testTime_ms << "ms\n" << std::endl;


    // Test timespec_from_ms function with positive time
    std::cout << "Testing timespec_from_ms function with positive time..." << std::endl;
    struct timespec testTime_ts = timespec_from_ms(testTime_ms);
    std::cout << "Test time (timespec): " << testTime_ts.tv_sec << "s , " << testTime_ts.tv_nsec << " ns\n" << std::endl;

    // Test timespec_to_ms function with negative time
    std::cout << "Testing timespec_from_ms function with negative time..." << std::endl;
    struct timespec testTimeNegative_ts = timespec_from_ms(-testTime_ms);
    std::cout << "Test time (timespec): " << testTimeNegative_ts.tv_sec << "s , " << testTimeNegative_ts.tv_nsec << " ns\n" << std::endl;


    // Test timespec_now function
    std::cout << "Testing timespec_now function..." << std::endl;
    struct timespec testTimeNow = timespec_now();
    std::cout << "Test time now (timespec): " << testTimeNow.tv_sec << "s , " << testTimeNow.tv_nsec << " ns\n" << std::endl;


    // Test timespec_negate function
    std::cout << "Testing timespec_negate function..." << std::endl;
    struct timespec negativeTime_ts = timespec_negate(testTime);
    std::cout << "Negative test time (timespec): " << negativeTime_ts.tv_sec << "s , " << negativeTime_ts.tv_nsec << " ns" << std::endl;
    std::cout << "Negative test time (ms): " << timespec_to_ms(negativeTime_ts) << "ms\n" << std::endl;


    // Test timespec_add function
    std::cout << "Testing timespec_add function..." << std::endl;
    struct timespec testTime1, testTime2;
    testTime1.tv_sec = 3;
    testTime1.tv_nsec = 999999999;
    testTime2.tv_sec = 1;
    testTime2.tv_nsec = 1;
    struct timespec timeSum_ts = timespec_add(testTime1, testTime2);
    std::cout << "Result sum (timespec): " << timeSum_ts.tv_sec << "s , " << timeSum_ts.tv_nsec << " ns\n" << std::endl;


    // Test timespec_subtract function
    std::cout << "Testing timespec_subtract function..." << std::endl;
    testTime1.tv_sec = 5;
    testTime1.tv_nsec = 1;
    testTime2.tv_sec = 6;
    testTime2.tv_nsec = 999999999;
    struct timespec timeSubt_ts = timespec_subtract(testTime1, testTime2);
    std::cout << "Result subtraction (timespec): " << timeSubt_ts.tv_sec << "s , " << timeSubt_ts.tv_nsec << " ns\n" << std::endl;


    // Test timespec_wait function
    std::cout << "Testing timespec_wait function..." << std::endl;
    struct timespec delayTime_ts, remTime_ts, initTime, finalTime, deltaTime;
    delayTime_ts.tv_sec = 2;
    delayTime_ts.tv_nsec = 500000000;

    initTime = timespec_now();
    remTime_ts = timespec_wait(delayTime_ts);
    finalTime = timespec_now();

    deltaTime = timespec_subtract(finalTime, initTime);
    std::cout << "Delta time: " << deltaTime.tv_sec << "s , " << deltaTime.tv_nsec << " ms" << std::endl;
    std::cout << "Remaining time: " << remTime_ts.tv_sec << "s , " << remTime_ts.tv_nsec << " ms\n" << std::endl;

    // Test operators
    std::cout << "Testing operators..." << std::endl;
    struct timespec result;
    testTime1.tv_sec = 5;
    testTime1.tv_nsec = 1;
    testTime2.tv_sec = 6;
    testTime2.tv_nsec = 999999999;
    
    // Test operator-
    std::cout << "Test operator-:" <<std::endl;
    result = -testTime1;
	std::cout << "- testTime1: " << result.tv_sec << "s , " << result.tv_nsec << " ms\n" << std::endl;
    
    // Test operator+
    std::cout << "Test operator+:" <<std::endl;
    result = testTime1 + testTime2;
	std::cout << "testTime1 + testTime2: " << result.tv_sec << "s , " << result.tv_nsec << " ms\n" << std::endl;
    
    // Test operator-
    std::cout << "Test operator-:" <<std::endl;
    result = testTime1 - testTime2;
	std::cout << "testTime1 - testTime2: "<< result.tv_sec << "s , " << result.tv_nsec << " ms\n" << std::endl;
 
    // Test operator+=
    std::cout << "Test operator+=:" <<std::endl;
    testTime1 += testTime2;
	std::cout << "testTime1 += testTime2: "<< testTime1.tv_sec << "s , " << testTime1.tv_nsec << " ms\n" << std::endl;

    // Test operator-=
    std::cout << "Test operator-=:" <<std::endl;
    testTime1 -= testTime2;
	std::cout << "testTime1 -= testTime2: "<< testTime1.tv_sec << "s , " << testTime1.tv_nsec << " ms\n" << std::endl;

    // Test operator==
    std::cout << "Test operator==:" <<std::endl;
	std::cout << "testTime1 == testTime2: " << (testTime1 == testTime2) <<  std::endl; 
	std::cout << "testTime2 == testTime1: " << (testTime2 == testTime1) << "\n" << std::endl; 
    
    // Test operator!=
    std::cout << "Test operator!=:" <<std::endl;
	std::cout << "testTime1 != testTime2: " << (testTime1 != testTime2) <<  std::endl; 
	std::cout << "testTime2 != testTime1: " << (testTime2 != testTime1) << "\n" << std::endl; 

	// Test operator<
    std::cout << "Test operator<:" <<std::endl;
	std::cout << "testTime1 < testTime2: " << (testTime1 < testTime2) <<  std::endl; 
	std::cout << "testTime2 < testTime1: " << (testTime2 < testTime1) << "\n" << std::endl; 

    // Test operator>
    std::cout << "Test operator>:" <<std::endl;
	std::cout << "testTime1 > testTime2: " << (testTime1 > testTime2) <<  std::endl; 
	std::cout << "testTime2 > testTime1: " << (testTime2 > testTime1) << "\n" << std::endl; 

    return 0;
}
