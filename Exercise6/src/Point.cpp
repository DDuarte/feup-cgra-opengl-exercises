#include "Point.h"
#include <math.h>

Point Point::Cross(const Point& vec) const
{
    Point p;
    p.X = Y * vec.Z - Z * vec.Y;
    p.Y = Z * vec.X - X * vec.Z;
    p.Z = X * vec.Y - Y * vec.X;
    return p;
}

Point Point::operator-(const Point& vec) const
{
    Point p;
    p.X = X - vec.X;
    p.Y = Y - vec.Y;
    p.Z = Z - vec.Z;
    return p;
}

Point Point::GetNormalized() const
{
    double length = sqrt(X * X + Y * Y + Z * Z);
    return Point(X / length, Y / length, Z / length);
}
