#ifndef MY_COMPLEX_LAMP
#define MY_COMPLEX_LAMP

#include "CGF/CGFlight.h"
#include "myLamp.h"
#include <vector>
#include "Point.h"
#include "myCylinder.h"
#include "myUnitCube.h"

class myComplexLamp : public CGFobject
{
private:
	myLamp _lamp;
	myUnitCube _cube;
	myCylinder _cyli;

public:
	myComplexLamp(int slices, int stacks) : _lamp(slices,stacks) , _cube() , _cyli(slices, stacks, true){}
	void draw();
};

#endif
