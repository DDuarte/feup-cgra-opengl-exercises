#ifndef MYCHAIR_H
#define MYCHAIR_H

#include "CGFobject.h"
#include "myUnitCube.h"

class myChair: public CGFobject
{
	myUnitCube _cube;
public:
	void draw();
};

#endif