#include "Point.h"

Point Point::Cross(const Point& vec)
{
    Point p;
    p.X = Y * vec.Z - Z * vec.Y;
    p.Y = Z * vec.X - X * vec.Z;
    p.Z = X * vec.Y - Y * vec.X;
    return p;
}

Point Point::operator-(const Point& vec)
{
    Point p;
    p.X = X - vec.X;
    p.Y = Y - vec.Y;
    p.Z = Z - vec.Z;
    return p;
}
