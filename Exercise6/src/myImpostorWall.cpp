#include "myImpostorWall.h"

#define Z 0.0
#define OFFSET 0.15/15.0

myImpostorWall::myImpostorWall(/*int numDivisions*/)
{
    _points.push_back(Point(0.0, 0.0, Z));
    _points.push_back(Point(1.0/3.0 + OFFSET, 1.0/3.0 + OFFSET, Z));
    _points.push_back(Point(0.0, 1.0, Z));
    _points.push_back(Point(1.0/3.0 + OFFSET, 2.0/3.0 - OFFSET, Z));
    _points.push_back(Point(1.0, 1.0, Z));
    _points.push_back(Point(2.0/3.0 - OFFSET, 2.0/3.0 - OFFSET, Z));
    _points.push_back(Point(1.0, 0.0, Z));
    _points.push_back(Point(2.0/3.0 - OFFSET, 1.0/3.0 + OFFSET, Z));

    _points.push_back(Point(0.0, 0.0, Z));
    _points.push_back(Point(1.0/3.0 + OFFSET, 1.0/3.0 + OFFSET, Z));
}

void myImpostorWall::draw(std::function<float(float)> sfunc, std::function<float(float)> tfunc)
{
    glBegin(GL_TRIANGLE_STRIP);
	glNormal3f(0,0,1);
    for (Point& p : _points)
	{
		glTexCoord2f(sfunc(p.X) ,tfunc(p.Y) );
        p.glVertex();
	}
    glEnd();
}
