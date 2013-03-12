#include "myFloor.h"

void myFloor::draw() 
{
    glPushMatrix();
    glTranslatef(0.0f, 0.1f / 2, 0.0f);
    glScalef(50.0f, 0.1f, 40.0f);
    _unitCube.draw();
    glPopMatrix();
}
