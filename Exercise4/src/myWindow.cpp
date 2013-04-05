#include "myWindow.h"
#include <GL/GLU.h>

void myWindow::draw()
{
    glBegin(GL_QUADS);

    glNormal3f(0.0f, 0.0f, 1.0f);

    glTexCoord2f(-1.0f, -1.0f);      
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glTexCoord2f(2.0f, -1.0f);      
    glVertex3f(0.5f, -0.5f, 0.0f); 
    glTexCoord2f(2.0f, 2.0f);      
    glVertex3f(0.5f, 0.5f, 0.0f);  
    glTexCoord2f(-1.0f, 2.0f);      
    glVertex3f(-0.5f, 0.5f, 0.0f); 
    glEnd(); 
}
