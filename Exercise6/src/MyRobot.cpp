#include "MyRobot.h"
#include <iostream>

#define YBASE 0.3f
#define RADIUS 0.25f
#define SLICES 12

MyRobot::MyRobot(int stacks) : _position(10.0f, 0.5f, 8.0f), _stacks(stacks)
{
    SetAngle(200.0f);
    _vertices.resize(_stacks);
    Point p;
    p.Y = YBASE;
    p.X = -0.5;
    p.Z = -0.5;

    for (int i = 0 ; i < 3; ++i)
    {
        _vertices[0].push_back(p);
        p.Z += 1.0/3.0;
    }

    for (int i = 0 ; i < 3; ++i)
    {
        _vertices[0].push_back(p);
        p.X += 1.0/3.0;
    }

    for (int i = 0 ; i < 3; ++i)
    {
        _vertices[0].push_back(p);
        p.Z -= 1.0/3.0;
    }

    for (int i = 0 ; i < 3; ++i)
    {
        _vertices[0].push_back(p);
        p.X -= 1.0/3.0;
    }


    double ang = M_PI / 4 + M_PI;

    for (int i = 0; i < SLICES; ++i)
    {
        p.X = RADIUS * sin(ang);
        p.Y = 1;
        p.Z = RADIUS * cos(ang);

        _vertices[_stacks - 1].push_back(p);

        ang += M_PI / 6;
    }

    for (int i = 0 ; i < _vertices.size() - 1; ++i)
    {
        for (int j = 0 ; j < _vertices[i].size(); ++j)
        {
            p = _vertices[i][j];
            double x, y, z;

            x = _vertices[_stacks - 1][j].X - _vertices[i][j].X;
            y = _vertices[_stacks - 1][j].Y - _vertices[i][j].Y;
            z = _vertices[_stacks - 1][j].Z - _vertices[i][j].Z;


            p.X += x*1/_stacks;
            p.Y += y*1/_stacks;
            p.Z += z*1/_stacks;

            _vertices[i + 1].push_back(p);
        }
    }
}

void MyRobot::draw()
{
    glBegin(GL_QUADS);
    glNormal3f(0.0f, -1.0f, 0.0f);
    for (int i = 3; i >= 0; --i)
        _vertices[0][i*3].glVertex();
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 1.0f, 0.0f);
    for (int i = 0; i < SLICES; i++)
        _vertices[_stacks - 1][i].glVertex();
    glEnd();

    for (int i = 0; i < _stacks; ++i)
    {
        for (int j = 0; j < SLICES; ++j)
        {
            glBegin(GL_POLYGON);
            //glNormal3f(0.0f, 1.0f, 0.0f);
            _vertices[i][j].glVertex();
            _vertices[i][(j + 1) % SLICES].glVertex();
            _vertices[(i + 1) % _stacks][(j + 1) % SLICES].glVertex();
            _vertices[(i + 1) % _stacks][j].glVertex();
            glEnd();
        }
    }
}
