#ifndef MYTABLE_H
#define MYTABLE_H

#include "CGFobject.h"
#include "myUnitCube.h"

class myTable: public CGFobject {
private:
    myUnitCube _unitCube;
    float angle;
    float transl;
public:
    myTable();
    void draw();
};

#endif
