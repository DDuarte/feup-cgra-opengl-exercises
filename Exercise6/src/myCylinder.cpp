#include "myCylinder.h"


myCylinder::myCylinder(int slices, int stacks, bool smooth /*= false */) : _slices(slices), _stacks(stacks), _smooth(smooth), _vertices(stacks)
{
    const double angle = 2*M_PI / _slices;

    double ang = 0.0;
    double z = 0.0;
    for (int i = 0; i < _stacks ; ++i)
    {
        _vertices[i].resize(_slices);

        for(int j = 0 ; j < _slices ; ++j)
        {
            Point p(cos(ang), sin(ang), z);
            _vertices[i][j] = p;
            ang += angle;
        }

        z += 1.0/_stacks;
        ang = 0.0;
    }
}

void myCylinder::draw()
{
    const float slicesf = (float)_slices;
    const float stacksf = (float)_stacks;

#define helper(i,j) glTexCoord2f( _vertices[i][j].X * 0.5 + 0.5, _vertices[i][j].Y * 0.5 + 0.5); \
    _vertices[i][j].glVertex();

    // bottom
    glNormal3d(0.0, 0.0, -1.0);
    glBegin(GL_POLYGON);
    for (int i = _slices - 1; i >= 0; --i)
    {
       helper(0,i);
    }
    glEnd();

    // top
    glNormal3d(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < _slices; ++i)
    {
        helper(_stacks - 1 , i);
    }
    glEnd();
#undef helper
#ifndef helper
#define helper(i, j) if (_smooth) (_vertices[i][j] - ringCenter).glNormal();              \
                     glTexCoord2f(asin(_vertices[i][j].Y) / (2*M_PI), _vertices[i][j].Z);  \
                     _vertices[i][j].glVertex();
#endif

    // lateral faces
    for (int i = 0 ; i < _stacks - 1; ++i)
    {
        const Point ringCenter(0.0, 0.0, i * 1.0/_stacks);

        for (int j = 0 ; j < _slices; ++j)
        {
            glBegin(GL_POLYGON);

            if (j == _slices - 1)
            {
                if (!_smooth)
                    (_vertices[i][0] - _vertices[i][j]).Cross(_vertices[i + 1][0] - _vertices[i][j]).glNormal();

                helper(i, j)
                helper(i, 0)
                helper(i + 1, 0)
                helper(i + 1, j)
            }
            else
            {
                if (!_smooth)
                    (_vertices[i][j + 1] - _vertices[i][j]).Cross(_vertices[i + 1][j + 1] - _vertices[i][j]).glNormal();

                helper(i, j)
                helper(i, j + 1)
                helper(i + 1, j + 1)
                helper(i + 1, j)
            }

            glEnd();
        }
    }

#undef helper
}
