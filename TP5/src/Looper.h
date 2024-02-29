#ifndef Looper_h_INCLUDED
#define Looper_h_INCLUDED

class Looper
{
private:
    bool doStop;
    double iLoop;

public:
    double runLoop(double nLoops = __DBL_MAX__);
    double getSample();
    double stopLoop();

};

#endif
