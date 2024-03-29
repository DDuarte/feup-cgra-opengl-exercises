#include "myClock.h"

float ambClock[3] = {0.5, 0.5, 0.5};
float difClock[3] = {0.522, 0.522, 0.522};
float specClock[3] = {0.1, 0.1, 0.1};
float shininessClock = 10.f;

myClock::myClock()
{
    _cyli = new  myCylinder(12, 1, true);
    _seconds = new myClockHand(0.45);
    _minutes = new myClockHand(0.3);
    _hours = new myClockHand(0.15);
    _clockAppearence = new CGFappearance("clock.png", GL_CLAMP, GL_CLAMP);
    _clockAppearence->setAmbient(ambClock);
    _clockAppearence->setDiffuse(difClock);
    _clockAppearence->setShininess(shininessClock);
    _clockAppearence->setSpecular(specClock);
}

myClock::~myClock()
{
    delete _cyli;
    delete _clockAppearence;
    delete _seconds;
    delete _minutes;
    delete _hours;
}

void myClock::draw()
{
    glPushMatrix();
    _seconds->draw();
    glPopMatrix();

    glPushMatrix();
    _minutes->draw();
    glPopMatrix();

    glPushMatrix();
    _hours->draw();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.5, 0.5, 1.5);
    _clockAppearence->apply();
    _cyli->draw();
    glPopMatrix();
}

void myClock::update(unsigned long millis)
{
    unsigned long seconds = (millis / 1000) % 60;
    unsigned long minutes = (millis / 1000 / 60) % 60;
    unsigned long hours   = (millis / 1000 / 60 / 60) % 12;

    float secs = seconds * (360.0f / 60.0f);
    float mins = minutes * (360.0f / 60.0f) + secs / 60.0f;
    float hrs = hours * (360.0f / 12.0f) + mins / 60.0f;

    _seconds->setAngle(secs);
    _minutes->setAngle(mins);
    _hours->setAngle(hrs);
}
