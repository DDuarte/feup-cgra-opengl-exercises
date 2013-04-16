#ifndef MYTABLE_H
#define MYTABLE_H

#include "CGFobject.h"
#include "myUnitCube.h"

class CGFappearance;

class myTable: public CGFobject {
private:
    myUnitCube _unitCube;
    //CGFappearance* _wood;
    CGFappearance* tableAppearance;
    CGFappearance* _steel;
public:
    myTable();
    ~myTable();
    void draw();
};

#endif
