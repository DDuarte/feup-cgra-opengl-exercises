#include "myChair.h"

myChair::myChair()
{
    angle = rand() % 41 - 20;
    transl = rand() % 1 - 1;
}

void myChair::draw()
{
    glPushMatrix();
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glTranslatef(transl, 0.0f, transl*0.5f);

    // Leg 1
    glPushMatrix();
    glTranslated(0,3.5/4,0);
    glScalef(0.3f, 3.5/2, 0.3f);
    _cube.draw();
    glPopMatrix();

    // Leg 2
    glPushMatrix();
    glTranslated(0,3.5/4,3.5/2);
    glScalef(0.3f, 3.5/2, 0.3f);
    _cube.draw();
    glPopMatrix();

    // Leg 3
    glPushMatrix();
    glTranslated(3.5/2,3.5/4,0);
    glScalef(0.3f, 3.5/2, 0.3f);
    _cube.draw();
    glPopMatrix();

    // Leg 4
    glPushMatrix();
    glTranslated(3.5/2,3.5/4,3.5/2);
    glScalef(0.3f, 3.5/2, 0.3f);
    _cube.draw();
    glPopMatrix();

    // Seat
    glPushMatrix();
    glTranslated(3.5/4,3.5/2+0.3/2,3.5/4);
    glScalef(3.5/2+0.3, 0.3f, 3.5/2+0.3);
    _cube.draw();
    glPopMatrix();

    // Back
    glPushMatrix();
    glTranslated(3.5/4,(3.5/2+0.3)/4+2.9,0);
    glRotated(90,-1,0,0);
    glScalef(3.5/2+0.3, 0.3f, (3.5/2+0.3)/2);
    _cube.draw();
    glPopMatrix();

    // Back 1
    glPushMatrix();
    glTranslated(0,3.5/8+3.5/2+ 0.3f,0);
    glScalef(0.3f, 3.5/4, 0.3f);
    _cube.draw();
    glPopMatrix();

    // Back 2
    glPushMatrix();
    glTranslated(3.5/2,3.5/8+3.5/2+ 0.3f,0);
    glScalef(0.3f, 3.5/4, 0.3f);
    _cube.draw();
    glPopMatrix();

    glPopMatrix();
}
