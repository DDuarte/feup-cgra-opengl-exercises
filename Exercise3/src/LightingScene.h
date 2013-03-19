#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "myChair.h"
#include "Plane.h"
#include "myComplexLamp.h"

class LightingScene : public CGFscene
{
public:
    void init();
    void display();

    CGFlight* light0;
    CGFlight* light1;
    CGFlight* light2;
    CGFlight* light3;

    myTable* table;
    myChair* chair;
    Plane* wall;
    Plane* boardA;
    Plane* boardB;
    myComplexLamp* lamp;
    CGFappearance* materialA;
    CGFappearance* materialB;
    CGFappearance* materialW;
    CGFappearance* materialF;
    CGFappearance* materialC;

    ~LightingScene();
};

#endif
