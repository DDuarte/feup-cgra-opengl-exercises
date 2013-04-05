#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "myChair.h"
#include "Plane.h"
#include "myComplexLamp.h"
#include "myWindow.h"

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

    myTable* table;
    myChair* chair;
    Plane* wall;
    myWindow* window;
    Plane* boardA;
    Plane* boardB;
    myComplexLamp* lamp;
    CGFappearance* materialA;
    CGFappearance* materialB;
    CGFappearance* materialW;
    CGFappearance* materialF;
    CGFappearance* materialC;
    CGFappearance* slidesAppearance;
    CGFappearance* boardAppearance;
    CGFappearance* windowAppearance;
    CGFappearance* floorAppearance;

    ~LightingScene();
};

#endif
