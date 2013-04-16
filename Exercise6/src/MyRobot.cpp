#include "MyRobot.h"

void MyRobot::draw()
{
    glBegin(GL_TRIANGLES);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, 0.3f, 0.0f);
    glVertex3f(-0.5f, 0.3f, 0.0f);
    glVertex3f(0.0f, 0.3f, 2.0f);
    glEnd();
}
