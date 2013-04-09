#ifndef MY_SPHERE
#define MY_SPHERE

#include "CGF/CGFobject.h"
#include <vector>
#include "Point.h"

#define _USE_MATH_DEFINES
#include <math.h>

class mySphere : public CGFobject
{
private:
    std::vector<std::vector<Point>> _vertices;
    int _slices;
    int _stacks;

public:
    mySphere(int slices, int stacks);
    void draw();
};

#endif
