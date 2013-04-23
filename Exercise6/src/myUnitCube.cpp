#include "myUnitCube.h"

#define rect glBegin(GL_QUADS);              \
             glTexCoord2f(0.0f, 0.0f);       \
             glVertex3f(-0.5f, -0.5f, 0.0f); \
             glTexCoord2f(1.0f, 0.0f);       \
             glVertex3f(0.5f, -0.5f, 0.0f);  \
             glTexCoord2f(1.0f, 1.0f);       \
             glVertex3f(0.5f, 0.5f, 0.0f);   \
             glTexCoord2f(0.0f, 1.0f);       \
             glVertex3f(-0.5f, 0.5f, 0.0f);  \
             glEnd();

void myUnitCube::draw()
{
    // front
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.5f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    rect
    glPopMatrix();

    // back
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -0.5f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    rect
    glPopMatrix();

    // left
    glPushMatrix();
    glTranslatef(-0.5f, 0.0f, 0.0f);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    rect
    glPopMatrix();

    // right
    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    rect
    glPopMatrix();

    // top
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    rect
    glPopMatrix();

    // bottom
    glPushMatrix();
    glTranslatef(0.0f, -0.5f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    rect
    glPopMatrix();
}
