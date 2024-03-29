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
    // bottom
    glNormal3d(0.0, 0.0, -1.0);
    glBegin(GL_POLYGON);
    for (int i = _slices - 1; i >= 0; --i)
        _vertices[0][i].glVertex();
    glEnd();

    // top
    glNormal3d(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < _slices; ++i)
        _vertices[_stacks - 1][i].glVertex();
    glEnd();

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

                if (_smooth) (_vertices[i][j] - ringCenter).glNormal();
                _vertices[i][j].glVertex();
                if (_smooth) (_vertices[i][0] - ringCenter).glNormal();
                _vertices[i][0].glVertex();
                if (_smooth) (_vertices[i + 1][0] - ringCenter).glNormal();
                _vertices[i + 1][0].glVertex();
                if (_smooth) (_vertices[i + 1][j] - ringCenter).glNormal();
                _vertices[i + 1][j].glVertex();
            }
            else
            {
                if (!_smooth)
                    (_vertices[i][j + 1] - _vertices[i][j]).Cross(_vertices[i + 1][j + 1] - _vertices[i][j]).glNormal();

                if (_smooth) (_vertices[i][j] - ringCenter).glNormal();
                _vertices[i][j].glVertex();
                if (_smooth) (_vertices[i][j + 1] - ringCenter).glNormal();
                _vertices[i][j + 1].glVertex();
                if (_smooth) (_vertices[i + 1][j + 1] - ringCenter).glNormal();
                _vertices[i + 1][j + 1].glVertex();
                if (_smooth) (_vertices[i + 1][j] - ringCenter).glNormal();
                _vertices[i + 1][j].glVertex();
            }

            glEnd();
        }
    }
}
