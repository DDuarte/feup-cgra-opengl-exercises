#include "Plane.h"
#include "myUnitCube.h"
#include <GL/GLU.h>



Plane::Plane(void)
{
    _numDivisions = 1;
}

Plane::Plane(int n)
{
    _numDivisions = n;
}


Plane::~Plane(void)
{
}

void Plane::draw(std::function<float(float)> sfunc, std::function<float(float)> tfunc)
{
    float numDivisionsf = (float)_numDivisions;

    glPushMatrix();
        glRotatef(180.0,1,0,0);
        glTranslatef(-0.5,0.0,-0.5);
        glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
        glNormal3f(0,-1,0);

        for (int bx = 0; bx<_numDivisions; bx++)
        {
            glBegin(GL_TRIANGLE_STRIP);
                glTexCoord2f(sfunc(bx / numDivisionsf), tfunc(0));
                glVertex3f(bx, 0, 0);

                for (int bz = 0; bz<_numDivisions; bz++)
                {
                    glTexCoord2f(sfunc((bx + 1) / numDivisionsf), tfunc(bz / numDivisionsf));
                    glVertex3f(bx + 1, 0, bz);
                    glTexCoord2f(sfunc(bx / numDivisionsf), tfunc((bz + 1) / numDivisionsf));
                    glVertex3f(bx, 0, bz + 1);
                }
                glTexCoord2f(sfunc((bx + 1) / numDivisionsf), tfunc(1));
                glVertex3d(bx+ 1, 0, _numDivisions);
            glEnd();
        }
    glPopMatrix();

}
