#ifndef MYCLOCK_H
#define MYCLOCK_H

#include "CGFobject.h"
#include "myCylinder.h"
#include "myClockHand.h"
#include <CGFappearance.h>

class myClock : public CGFobject
{
private:
    myCylinder* _cyli;
    CGFappearance* _clockAppearence;
    myClockHand* _seconds;
    myClockHand* _minutes;
    myClockHand* _hours;

    bool _paused;

public:
    myClock();
    ~myClock();
    virtual void draw() override;
    void update(unsigned long millis);

    void PauseReboot() { _paused ^= true; }
};

#endif