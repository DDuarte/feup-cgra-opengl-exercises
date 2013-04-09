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
        for (int j = 0 ; j < _slices && theta <= M_PI; ++j)
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
    double s, t;
    Point p;

    for (int i = 0; i < _vertices.size(); ++i)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j < _vertices[i].size(); ++j)
        {
            p = _vertices[(i+1)%_vertices.size()][j];
            s = 0.5 + atan2(p.Z, p.X) / (2 * M_PI);
            t = 0.5 - 2.0 * asin(p.Y) / (2 * M_PI);

            glTexCoord2f(s, t);
            p.glNormal();
            p.glVertex();

            p = _vertices[i][j];
            s = 0.5 + atan2(p.Z, p.X) / (2 * M_PI);
            t = 0.5 - 2.0 * asin(p.Y) / (2 * M_PI);

            glTexCoord2f(s, t);
            p.glNormal();
            p.glVertex();
        }
        glEnd();
    }
}
