#include "myUnitCube.h"

void myUnitCube::draw() 
{
    // front
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.5f);
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
    glPopMatrix();

    // back
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -0.5f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
    glPopMatrix();

    // left
    glPushMatrix();
    glTranslatef(-0.5f, 0.0f, 0.0f);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
    glPopMatrix();

    // right
    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
    glPopMatrix();

    // top
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
    glPopMatrix();

    // bottom
    glPushMatrix();
    glTranslatef(0.0f, -0.5f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
    glPopMatrix();
}
