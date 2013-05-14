#include "myImpostorWall.h"

#define Z 0.0

myImpostorWall::myImpostorWall(/*int numDivisions*/)
{
    _points.push_back(Point(0.0, 0.0, Z));
    _points.push_back(Point(1.0/3.0, 1.0/3.0, Z));
    _points.push_back(Point(0.0, 1.0, Z));
    _points.push_back(Point(1.0/3.0, 2.0/3.0, Z));
    _points.push_back(Point(1.0, 1.0, Z));
    _points.push_back(Point(2.0/3.0, 2.0/3.0, Z));
    _points.push_back(Point(1.0, 0.0, Z));
    _points.push_back(Point(2.0/3.0, 1.0/3.0, Z));

    _points.push_back(Point(0.0, 0.0, Z));
    _points.push_back(Point(1.0/3.0, 1.0/3.0, Z));
}

void myImpostorWall::draw(std::function<float(float)> sfunc, std::function<float(float)> tfunc)
{
    glBegin(GL_TRIANGLE_STRIP);
    for (Point& p : _points)
        p.glVertex();
    glEnd();
}
