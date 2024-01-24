#ifndef Timer_h_INCLUDED
#define Timer_h_INCLUDED

#include <iostream>
#include <signal.h>
#include <time.h>

void timerPOSIX();

void myHandler(int sig, siginfo_t* si, void*);

#endif
