#include "MyRobot.h"


#include "NewellsMethod.h"
#include <iostream>

#define YBASE 0.3f
#define RADIUS 0.25f
#define SLICES 12

MyRobot::MyRobot(int stacks) : _position(10.0f, 0.5f, 8.0f), _stacks(stacks + 1)
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

    double x, y, z;

    for (int i = 0 ; i < _vertices.size() - 1; ++i)
    {
        for (int j = 0 ; j < _vertices[i].size(); ++j)
        {
            p = _vertices[i][j];

            x = _vertices[_stacks - 1][j].X - _vertices[0][j].X;
            y = _vertices[_stacks - 1][j].Y - _vertices[0][j].Y;
            z = _vertices[_stacks - 1][j].Z - _vertices[0][j].Z;

            p.X += x/(_stacks - 1);
            p.Y += y/(_stacks - 1);
            p.Z += z/(_stacks - 1);

            _vertices[i + 1].push_back(p);
        }
    }

    // calculate normals

    std::vector<Point> points(4);

    for (int i = 0; i < _stacks; ++i)
    {
        for (int j = 0; j < SLICES; ++j)
        {
            points[0] = _vertices[i][j];
            points[1] = _vertices[i][(j + 1) % SLICES];
            points[2] = _vertices[(i + 1) % _stacks][(j + 1) % SLICES];
            points[3] = _vertices[(i + 1) % _stacks][j];

            _normals.push_back(CalculateSurfaceNormal(points));
        }
    }
}

void MyRobot::draw()
{
    // base (square)
    glBegin(GL_QUADS);
    glNormal3f(0.0f, -1.0f, 0.0f);
    for (int i = 3; i >= 0; --i)
        _vertices[0][i*3].glVertex();
    glEnd();

    // top (circle)
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 1.0f, 0.0f);
    for (int i = 0; i < SLICES; i++)
        _vertices[_stacks - 1][i].glVertex();
    glEnd();

    std::vector<Point> points(4);

    // sides
    for (int i = 0; i < _stacks; ++i)
    {
        for (int j = 0; j < SLICES; ++j)
        {
            glBegin(GL_POLYGON);
            _normals[i * SLICES + j].glNormal();
            _vertices[i][j].glVertex();
            _vertices[i][(j + 1) % SLICES].glVertex();
            _vertices[(i + 1) % _stacks][(j + 1) % SLICES].glVertex();
            _vertices[(i + 1) % _stacks][j].glVertex();
            glEnd();
        }
    }
}
