#ifndef MY_LAMP
#define MY_LAMP

#include "CGF/CGFobject.h"
#include <vector>
#include "Point.h"

#define _USE_MATH_DEFINES
#include <math.h>

class myLamp : public CGFobject
{
private:
    std::vector<std::vector<Point>> _vertices;
    int _slices;
    int _stacks;

public:
    myLamp(int slices, int stacks);
    void draw();
};

#endif
