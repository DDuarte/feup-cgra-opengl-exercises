#ifndef POINT_H_
#define POINT_H_

#include <iostream>
#include <GL/glut.h>


struct Point
{
    Point(): X(0.0), Y(0.0), Z(0.0) {}
    Point(double x, double y, double z): X(x), Y(y), Z(z) {}
    double X;
    double Y;
    double Z;

    Point Cross(const Point& vec) const; // this is a point but it can also represent vectors
    Point operator -(const Point& vec) const;
    Point GetNormalized() const;

    // OpenGL helpers
    void glVertex() const { glVertex3d(X, Y, Z); }
    void glNormal() const { glNormal3d(X, Y, Z); }

    // printer
    friend std::ostream& operator<<(std::ostream& os, const Point& dt);
};

#endif // POINT_H_
