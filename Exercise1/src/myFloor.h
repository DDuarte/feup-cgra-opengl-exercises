#ifndef MYFLOOR_H
#define MYFLOOR_H

#include "CGFobject.h"
#include "myUnitCube.h"

class myFloor: public CGFobject {
private:
    myUnitCube _unitCube;
public:
    void draw();
};

#endif
