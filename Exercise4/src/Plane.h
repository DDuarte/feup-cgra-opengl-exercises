#pragma once

#include "CGF\CGFobject.h"
#include <functional>

class Plane
{
public:
    Plane(void);
    Plane(int);
    ~Plane(void);
    void draw(std::function<float(float)> sfunc, std::function<float(float)> tfunc);
private:
    int _numDivisions; // Number of triangles that constitute rows/columns
};

