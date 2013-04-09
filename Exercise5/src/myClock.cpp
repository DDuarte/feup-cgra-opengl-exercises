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

	_seconds->incAngle();

	glPushMatrix();
	_minutes->draw();
	glPopMatrix();

	if((int)_seconds->getAngle() % 360 == 0)
		_minutes->incAngle();

	glPushMatrix();
	_hours->draw();
	glPopMatrix();

	if((int)_minutes->getAngle() % (360/5) == 0)
		_hours->incAngle();

	glPushMatrix();
	glScaled(0.5, 0.5, 1.5);
	_clockAppearence->apply();
	_cyli->draw();
	glPopMatrix();
}
