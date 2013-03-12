#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGF/CGFobject.h"
#include <vector>

#define _USE_MATH_DEFINES
#include <math.h>

class myCylinder : public CGFobject
{
    struct Point
    {
        Point(): X(0.0), Y(0.0), Z(0.0) {}
        Point(double x, double y, double z): X(x), Y(y), Z(z) {}
        double X;
        double Y;
        double Z;

        Point Cross(const Point& vec);
        Point operator -(const Point& vec);
    };

private:
    std::vector<std::vector<Point>> _vertices;
    int _slices;
    int _stacks;
    bool _smooth;

public:
    myCylinder(int slices, int stacks, bool smooth = false);
    void draw();
};



#endif
