#ifndef TPSCENE_H
#define TPSCENE_H

#include "CGFscene.h"
//#include "ExampleObject.h"
//#include "myUnitCube.h"
#include "myTable.h"
#include "myFloor.h"
#include "myChair.h"

class TPscene : public CGFscene
{
private:
    //ExampleObject myObject;
    //myUnitCube cube;
    myTable table;
    myFloor floor;
	myChair chair;
public:
	void init();
	void display();
};

#endif