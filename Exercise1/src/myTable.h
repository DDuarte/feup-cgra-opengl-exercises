#ifndef MYTABLE_H
#define MYTABLE_H

#include "CGFobject.h"
#include "myUnitCube.h"

class myTable: public CGFobject {
private:
    myUnitCube _unitCube;
public:
    void draw();
};

#endif
