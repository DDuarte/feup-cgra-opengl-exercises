#include "myLamp.h"

myLamp::myLamp(int slices, int stacks) : _slices(slices), _stacks(stacks), _vertices(stacks)
{
    const double thetainc = 2*M_PI / _slices;
    const double phiinc = 2*M_PI / _stacks;
    
    double phi = 0.0;

    for (int i = 0; i < _stacks ; ++i)
    {
        _vertices[i].resize(_slices);

        double theta = 0.0;
        for (int j = 0 ; j < _slices && theta <= M_PI ; ++j)
        {
            Point p(cos(theta) * cos(phi), cos(theta) * sin(phi), sin(theta));
            _vertices[i][j] = p;

            theta += thetainc;
        }

        phi += phiinc;
    }
}

void myLamp::draw()
{
    for (int i = 0; i < _vertices.size(); ++i)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j < _vertices[i].size(); ++j)
        {
            _vertices[(i+1)%_vertices.size()][j].glNormal();
            _vertices[(i+1)%_vertices.size()][j].glVertex();
            _vertices[i][j].glNormal();
            _vertices[i][j].glVertex();
        }
        glEnd();
    }
}
