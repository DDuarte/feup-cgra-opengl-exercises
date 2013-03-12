#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};

float light2_pos[4] = {10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6.0, 5.0, 1.0};

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4]= {0.0,0.0,0.0,1.0}; //{0.2,0.2,0.2,1.0};

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

// Coefficients for material A
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0.0, 0.8, 0.8}; /* {0.2, 0.2, 0.2} */
float shininessA = 120.f; /* 10.f */

// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.6, 0.6, 0.6};
float specB[3] = {0.8, 0.8, 0.8};
float shininessB = 120.f;

// Coefficients for material F - floor
float ambF[3] = {0.2, 0.2, 0.2};
float difF[3] = {0.0, 0.3, 0.4};
float specF[3] = {0.3, 0.3, 0.3};
float shininessF = 10.f;

// Coefficients for material W - walls
float ambW[3] = {1, 1, 1};
float difW[3] = {0.5, 0.5, 0.5};
float specW[3] = {0.3, 0.3, 0.3};
float shininessW = 5.f;

// Coefficients for material C - chairs
float ambC[3] = {1, 1, 1};
float difC[3] = {0.5, 0.5, 0.1};
float specC[3] = {0.3, 0.3, 0.3};
float shininessC = 5.f;

float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};

void LightingScene::init()
{
    // Enables lighting computations
    glEnable(GL_LIGHTING);

    // Sets up some lighting parameters
    // Computes lighting only using the front face normals and materials
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

    // Define ambient light (do not confuse with ambient component of individual lights)
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);

    // Declares and enables two lights, with null ambient component

    light0 = new CGFlight(GL_LIGHT0, light0_pos);
    light0->setAmbient(ambientNull);
    light0->setSpecular(yellow);
    light0->enable();

    light1 = new CGFlight(GL_LIGHT1, light1_pos);
    light1->setAmbient(ambientNull);
    light1->enable();

    light2 = new CGFlight(GL_LIGHT2, light2_pos);
    light2->setAmbient(ambientNull);
    light2->setKc(0.0f);
    light2->setKl(1.0f);
    light2->setKq(0.0f);
    light2->enable();

    light3 = new CGFlight(GL_LIGHT3, light3_pos);
    light3->setAmbient(ambientNull);
    light3->setKc(0.0f);
    light3->setKl(0.0f);
    light3->setKq(0.2f);
    light3->enable();

    // Uncomment below to enable normalization of lighting normal vectors
    glEnable(GL_NORMALIZE);

    //glShadeModel(GL_FLAT);
    glShadeModel(GL_SMOOTH);

    //Declares scene elements
    table = new myTable();
    chair = new myChair();
    wall = new Plane();
    boardA = new Plane(BOARD_A_DIVISIONS);
    boardB = new Plane(BOARD_B_DIVISIONS);
    cylinder = new myCylinder(4, 3);

    ////Declares materials
    materialA = new CGFappearance(ambA,difA,specA,shininessA);
    materialB = new CGFappearance(ambB,difB,specB,shininessB);
    materialF = new CGFappearance(ambF,difF,specF,shininessF);
    materialW = new CGFappearance(ambW,difW,specW,shininessW);
    materialC = new CGFappearance(ambC,difC,specC,shininessC);
}

void LightingScene::display()
{

    // ---- BEGIN Background, camera and axis setup

    // Clear image and depth buffer everytime we update the scene
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Initialize Model-View matrix as identity (no transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Apply transformations corresponding to the camera position relative to the origin
    CGFscene::activeCamera->applyView();

    light0->draw();
    light1->draw();
    light2->draw();
    light3->draw();

    // Draw axis
    axis.draw();

    // ---- END Background, camera and axis setup

    // ---- BEGIN Primitive drawing section

    cylinder->draw();

    /*
    //First Chair
    glPushMatrix();
        glTranslated(4,0,5);
        materialC->apply();
        chair->draw();
    glPopMatrix();

    //Second Chair
    glPushMatrix();
        glTranslated(11,0,5);
        chair->draw();
    glPopMatrix();

    //First Table
    glPushMatrix();
        glTranslated(5,0,8);
        table->draw();
    glPopMatrix();

    //Second Table
    glPushMatrix();
        glTranslated(12,0,8);
        table->draw();
    glPopMatrix();

    //Floor
    glPushMatrix();
        glTranslated(7.5,0,7.5);
        glScaled(15,0.2,15);
        materialF->apply();
        wall->draw();
    glPopMatrix();

    //LeftWall
    glPushMatrix();
        glTranslated(0,4,7.5);
        glRotated(-90.0,0,0,1);
        glScaled(8,0.2,15);
        materialW->apply();
        wall->draw();
    glPopMatrix();

    //PlaneWall
    glPushMatrix();
        glTranslated(7.5,4,0);
        glRotated(90.0,1,0,0);
        glScaled(15,0.2,8);
        materialW->apply();
        wall->draw();
    glPopMatrix();


    // Board A
    glPushMatrix();
        glTranslated(4,4,0.2);
        glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
        glRotated(90.0,1,0,0);
        materialA->apply();
        boardA->draw();
    glPopMatrix();

    //PlaneB
    glPushMatrix();
        glTranslated(10.5,4,0.2);
        glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
        glRotated(90.0,1,0,0);
        materialB->apply();
        boardB->draw();
    glPopMatrix();
    */

    // ---- END Primitive drawing section


    // We have been drawing in a memory area that is not visible - the back buffer,
    // while the graphics card is showing the contents of another buffer - the front buffer
    // glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
    glutSwapBuffers();
}

LightingScene::~LightingScene()
{
    delete(light0);
    delete(light1);
    delete(light2);
    delete(light3);

    delete(chair);
    delete(table);
    delete(wall);
    delete(boardA);
    delete(boardB);
    delete(cylinder);
    delete(materialA);
    delete(materialB);
    delete(materialW);
    delete(materialF);
    delete(materialC);
}