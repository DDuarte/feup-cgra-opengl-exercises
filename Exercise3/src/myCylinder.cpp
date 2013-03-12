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
            Point p(cos(ang),sin(ang),z);
            _vertices[i][j] = p;
            ang += angle;
        }

        z += 1.0/_stacks;
    }
}

void myCylinder::draw()
{
    // bottom
    glNormal3d(0.0, 0.0, -1.0);
    glBegin(GL_POLYGON);
    for (int i = _slices - 1; i >= 0; --i)
        glVertex3d(_vertices[0][i].X , _vertices[0][i].Y , _vertices[0][i].Z);
    glEnd();

    // top
    glNormal3d(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < _slices; ++i)
        glVertex3d(_vertices[_stacks-1][i].X , _vertices[_stacks-1][i].Y , _vertices[_stacks-1][i].Z);
    glEnd();

    // lateral faces
    for (int i = 0 ; i < _stacks - 1; ++i)
    {
        for (int j = 0 ; j < _slices; ++j)
        {
            glBegin(GL_POLYGON);
            
            if (j == _slices - 1)
            {
                Point normal = (_vertices[i][0] - _vertices[i][j]).Cross(_vertices[i + 1][0] - _vertices[i][j]);
                glNormal3d(normal.X, normal.Y, normal.Z);

                glVertex3d(_vertices[i][j].X,     _vertices[i][j].Y,     _vertices[i][j].Z);
                glVertex3d(_vertices[i][0].X,     _vertices[i][0].Y,     _vertices[i][0].Z);
                glVertex3d(_vertices[i + 1][0].X, _vertices[i + 1][0].Y, _vertices[i + 1][0].Z);
                glVertex3d(_vertices[i + 1][j].X, _vertices[i + 1][j].Y, _vertices[i + 1][j].Z);
            }
            else
            {
                Point normal = (_vertices[i][j + 1] - _vertices[i][j]).Cross(_vertices[i + 1][j + 1] - _vertices[i][j]);
                glNormal3d(normal.X, normal.Y, normal.Z);

                glVertex3d(_vertices[i][j].X,         _vertices[i][j].Y,         _vertices[i][j].Z);
                glVertex3d(_vertices[i][j + 1].X,     _vertices[i][j + 1].Y,     _vertices[i][j + 1].Z);
                glVertex3d(_vertices[i + 1][j + 1].X, _vertices[i + 1][j + 1].Y, _vertices[i + 1][j + 1].Z);
                glVertex3d(_vertices[i + 1][j].X,     _vertices[i + 1][j].Y,     _vertices[i + 1][j].Z);
            }
            
            glEnd();
        }
    }
}

myCylinder::Point myCylinder::Point::Cross(const Point& vec)
{
    Point p;
    p.X = Y * vec.Z - Z * vec.Y;
    p.Y = Z * vec.X - X * vec.Z;
    p.Z = X * vec.Y - Y * vec.X;
    return p;
}

myCylinder::Point myCylinder::Point::operator-(const Point& vec)
{
    Point p;
    p.X = X - vec.X;
    p.Y = Y - vec.Y;
    p.Z = Z - vec.Z;
    return p;
}
