#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "myChair.h"
#include "myCylinder.h"
#include "Plane.h"
#include "myComplexLamp.h"
#include "mySphere.h"
#include "myClock.h"

class LightingScene : public CGFscene
{
public:
    void init();
    void display();

    CGFlight* light0;
    CGFlight* light1;
    CGFlight* light2;
    CGFlight* light3;
    CGFlight* light4;

    mySphere* sphere;
    myCylinder* column;
    myTable* table;
    myChair* chair;
    Plane* wall;
    Plane* boardA;
    Plane* boardB;
    myComplexLamp* lamp;
	myClock* clock;
    CGFappearance* materialA;
    CGFappearance* materialB;
    CGFappearance* materialW;
    CGFappearance* materialF;
    CGFappearance* materialC;
    CGFappearance* slidesAppearance;
    CGFappearance* boardAppearance;
    CGFappearance* windowAppearance;
    CGFappearance* floorAppearance;
    CGFappearance* marbleAppearance;
    CGFappearance* fancyAppearance;
    CGFappearance* earthAppearance;
    CGFappearance* woodAppearance;

    ~LightingScene();
};

#endif
