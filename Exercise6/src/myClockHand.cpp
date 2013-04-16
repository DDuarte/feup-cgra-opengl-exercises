#include "myClockHand.h"


myClockHand::myClockHand()
{
    _cube = new myUnitCube();
    _angle = 0;
    _size = 1;
}

myClockHand::myClockHand( float n )
{
    _cube = new myUnitCube();
    _angle = 0;
    _size = n;
}

myClockHand::~myClockHand()
{
    delete _cube;
}

void myClockHand::draw()
{
    glPushMatrix();

    glRotated(_angle,0,0,-1);
    glTranslated(0, _size/2,0);
    glScaled(0.01, _size, 0.01);

    _cube->draw();
    glPopMatrix();
}
