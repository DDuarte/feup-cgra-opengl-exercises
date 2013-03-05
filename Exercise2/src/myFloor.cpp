#include "myFloor.h"

void myFloor::draw() 
{
    glPushMatrix();
    glTranslatef(0.0f, 0.1f / 2, 0.0f);
    glScalef(8.0f, 0.1f, 6.0f);
    _unitCube.draw();
    glPopMatrix();
}
