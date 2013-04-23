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
#include "myAirPlane.h"
#include "MyRobot.h"

class LightingScene : public CGFscene
{
public:
    virtual void init() override;
    virtual void display() override;
    virtual void update(unsigned long millis) override;

    CGFlight* light0;
    CGFlight* light1;
    CGFlight* light2;
    CGFlight* light3;
    CGFlight* light4;

    MyRobot* robot;

    mySphere* sphere;
    myCylinder* column;
    myTable* table;
    myChair* chair;
    Plane* wall;
    Plane* boardA;
    Plane* boardB;
    myComplexLamp* lamp;
    myClock* clock;
    myAirplane* plane;
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

    std::vector<int> lightsSwitcher;

public:
    void PauseRebootClock() { clock->PauseReboot(); }

    void RobotRotateLeft() { robot->RotateLeft(); }
    void RobotRotateRight() { robot->RotateRight(); }
    void RobotMoveForward() { robot->MoveForward(); }
    void RobotMoveBackward() { robot->MoveBackward(); }
    void RobotMoveUp()  { robot->MoveUp(); }
    void RobotMoveDown() { robot->MoveDown(); }

    ~LightingScene();
};

#endif
