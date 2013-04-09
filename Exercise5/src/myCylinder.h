#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGF/CGFobject.h"
#include <vector>
#include <functional>
#include "Point.h"

#define _USE_MATH_DEFINES
#include <math.h>

class myCylinder : public CGFobject
{
private:
    std::vector<std::vector<Point>> _vertices;
    int _slices;
    int _stacks;
    bool _smooth;

public:
    myCylinder(int slices, int stacks, bool smooth = false);
    virtual void draw();
};

#endif
