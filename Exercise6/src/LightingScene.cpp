#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"
#include <cassert>

#include <GL/glext.h> // needed for gl_clamp_to_edge on Windows

#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

#define LIGHT_COUNT 6

// Positions for two lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};

float light2_pos[4] = {10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6.0, 5.0, 1.0};
float light4_pos[4] = {1.0, 4.0, 7.5, 1.0};
float light5_pos[4] = {-25.0, 4.0, 7.5, 1.0};

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4]= {0.0,0.0,0.0,1.0}; //{0.2,0.2,0.2,1.0};

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

// Coefficients for material A
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0.2, 0.2, 0.2};
float shininessA = 10.f;

// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.3, 0.3, 0.3};
float specB[3] = {0.6, 0.6, 0.6};
float shininessB = 120.f;

// Coefficients for material F - floor
float ambF[3] = {0.2, 0.2, 0.2};
float difF[3] = {0.3, 0.3, 0.3};
float specF[3] = {0.3, 0.3, 0.3};
float shininessF = 10.f;

// Coefficients for material W - walls
float ambW[3] = {0.5, 0.5, 0.5};
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

float bgAmbient[4] = { 0, 0, 0, 1 };
float bgDiffuse[4] = { 1, 1, 1, 10 };
float bgSpecular[4] = { 1, 1, 1, 10 };

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

    light4 = new CGFlight(GL_LIGHT4, light4_pos);
    light4->setAmbient(ambientNull);
    light4->setKc(0.0f);
    light4->setKl(1.0f);
    light4->setKq(0.0f);
    light4->enable();

	light5 = new CGFlight(GL_LIGHT5, light5_pos);
	light5->setAmbient(bgAmbient);
	light5->setDiffuse(bgDiffuse);
	light5->setSpecular(bgSpecular);
	light5->enable();

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
    lamp = new myComplexLamp(20, 20);
    column = new myCylinder(20, 20, true);
    sphere = new mySphere(20, 20);
    clock = new myClock();
    plane = new myAirplane();

    drawMode = 0; // default rendering mode (textured)

    currentRobotTexture = 0; // default texture
    robot = new MyRobot(10);

    impostor = new myImpostorWall();

    ////Declares materials
    materialA = new CGFappearance(ambA,difA,specA,shininessA);
    materialB = new CGFappearance(ambB,difB,specB,shininessB);
    materialF = new CGFappearance(ambF,difF,specF,shininessF);
    materialW = new CGFappearance(ambW,difW,specW,shininessW);
    materialC = new CGFappearance(ambC,difC,specC,shininessC);

    slidesAppearance = new CGFappearance("slides.png", GL_REPEAT, GL_REPEAT);
    slidesAppearance->setAmbient(ambA);
    slidesAppearance->setDiffuse(difA);
    slidesAppearance->setSpecular(specA);
    slidesAppearance->setShininess(shininessA);

    boardAppearance = new CGFappearance("board.png", GL_REPEAT, GL_REPEAT);
    boardAppearance->setAmbient(ambB);
    boardAppearance->setDiffuse(difB);
    boardAppearance->setSpecular(specB);
    boardAppearance->setShininess(shininessB);

    windowAppearance = new CGFappearance("window.png", GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
    windowAppearance->setAmbient(ambW);
    windowAppearance->setDiffuse(difW);
    windowAppearance->setSpecular(specW);
    windowAppearance->setShininess(shininessW);

    floorAppearance = new CGFappearance("floor.png", GL_REPEAT, GL_REPEAT);
    floorAppearance->setAmbient(ambF);
    floorAppearance->setDiffuse(difF);
    floorAppearance->setSpecular(specF);
    floorAppearance->setShininess(shininessF);

    marbleAppearance = new CGFappearance("marble.jpg", GL_REPEAT, GL_REPEAT);
    marbleAppearance->setAmbient(ambF);
    marbleAppearance->setDiffuse(difF);
    marbleAppearance->setSpecular(specF);
    marbleAppearance->setShininess(shininessF);

    fancyAppearance = new CGFappearance("fancy.jpg", GL_REPEAT, GL_REPEAT);
    fancyAppearance->setAmbient(ambF);
    fancyAppearance->setDiffuse(difF);
    fancyAppearance->setSpecular(specF);
    fancyAppearance->setShininess(shininessF);

    earthAppearance = new CGFappearance("earth.jpg", GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
    earthAppearance->setAmbient(ambF);
    earthAppearance->setDiffuse(difF);
    earthAppearance->setSpecular(specF);
    earthAppearance->setShininess(shininessF);

    woodAppearance = new CGFappearance("wood.jpg", GL_REPEAT, GL_REPEAT);
    woodAppearance->setAmbient(ambF);
    woodAppearance->setDiffuse(difF);
    woodAppearance->setSpecular(specF);
    woodAppearance->setShininess(shininessF);

	backGroundAppearance = new CGFappearance("background.jpg", GL_CLAMP, GL_CLAMP);
	backGroundAppearance->setAmbient(ambF);
	backGroundAppearance->setDiffuse(difF);
	backGroundAppearance->setSpecular(specF);
	backGroundAppearance->setShininess(shininessF);

	nightAppearance = new CGFappearance("night.jpg", GL_CLAMP, GL_CLAMP);
	nightAppearance->setAmbient(ambF);
	nightAppearance->setDiffuse(difF);
	nightAppearance->setSpecular(specF);
	nightAppearance->setShininess(shininessF);

    for (int i = 0; i < LIGHT_COUNT; ++i)
        lightsSwitcher.push_back(1); // on

    setUpdatePeriod(100);
}

static std::function<float(float)> defaultS = [](float s) -> float { return s; };
static std::function<float(float)> defaultT = [](float t) -> float { return t; };

static std::function<float(float)> windowS = [](float s) -> float { return 3*s - 1; };
static std::function<float(float)> windowT = [](float t) -> float { return 3*t - 1; };

static std::function<float(float)> floorS = [](float s) -> float { return s * 10; };
static std::function<float(float)> floorT = [](float t) -> float { return t * 12; };

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

	CGFappearance *ptr;
    lightsSwitcher[0] ? light0->enable() : light0->disable();
    lightsSwitcher[1] ? light1->enable() : light1->disable();
    lightsSwitcher[2] ? light2->enable() : light2->disable();
    lightsSwitcher[3] ? light3->enable() : light3->disable();
    lightsSwitcher[4] ? light4->enable() : light4->disable();
	lightsSwitcher[5] ? light5->enable() : light5->disable();
	lightsSwitcher[5] ? ptr = backGroundAppearance : ptr = nightAppearance;

    light0->update();
    light1->update();
    light2->update();
    light3->update();
    light4->update();
	light5->update();

    // Draw axis
    axis.draw();

    // ---- END Background, camera and axis setup
    
    // ---- BEGIN Primitive drawing section
    //First Chair
    //glPushMatrix();
    //glTranslated(4,0,5);
    //woodAppearance->apply();
    //chair->draw();
    //glPopMatrix();
    //
    ////Second Chair
    //glPushMatrix();
    //glTranslated(11,0,5);
    //chair->draw();
    //glPopMatrix();

    //First Table
    glPushMatrix();
    glTranslated(5,0,8);
    table->draw();
    glPopMatrix();

    //Second Table
    //glPushMatrix();
    //glTranslated(12,0,8);
    //table->draw();
    //glPopMatrix();

    //Floor
    glPushMatrix();
    glTranslated(7.5,0,7.5);
    glScaled(15,0.2,15);
    floorAppearance->apply();
    wall->draw(floorS, floorT);
    glPopMatrix();

    //LeftWall
    glPushMatrix();
	glTranslated(0,0,15);
	glRotated(90,0,1,0);
    glScaled(15,8,0.2);
    windowAppearance->apply();
    impostor->draw(windowS, windowT);
    glPopMatrix();

	//"Background"
	glPushMatrix();
	glTranslated(-30,12,7.5);
	glRotated(-90.0,0,0,1);
	glRotated(90.0,0,1,0);
	glScaled(75,0.2,40);
	ptr->apply();
	wall->draw(defaultS, defaultT);
	glPopMatrix();

    //PlaneWall
    glPushMatrix();
    glTranslated(7.5,4,0);
    glRotated(90.0,1,0,0);
    glScaled(15,0.2,8);
    materialW->apply();
    wall->draw(defaultS, defaultT);
    glPopMatrix();

    // Board A
    glPushMatrix();
    glTranslated(4,4,0.2);
    glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
    glRotated(90.0,1,0,0);
    //materialA->apply();
    slidesAppearance->apply();
    wall->draw(defaultS, defaultT);
    glPopMatrix();

    // Board B
    glPushMatrix();
    glTranslated(10.5,4,0.2);
    glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
    glRotated(90.0,1,0,0);
    boardAppearance->apply();
    wall->draw(defaultS, defaultT);
    glPopMatrix();

    //Column
    glPushMatrix();
    glTranslated(5.0, 8.0, 12.0);
    glRotated(90.0, 1.0, 0.0, 0.0);
    glScaled(1.0, 1.0, 8.5);
    marbleAppearance->apply();
    column->draw();
    glPopMatrix();

    //Lamp
    //glPushMatrix();
    //glTranslated(5.0, 8.0, 7.0);
    ////glRotated(90.0, 1.0, 0.0, 0.0);
    //glScaled(0.5, 0.5, 0.5);
    //fancyAppearance->apply();
    //lamp->draw();
    //glPopMatrix();

    //Globe
    glPushMatrix();
    glTranslated(4.0, 4.3, 8.0);
    glRotated(-90.0, 0.0, 1.0, 0.0);
    glRotated(180, 0.0, 0.0, 1.0);
    glScaled(0.5, 0.5, 0.5);
    earthAppearance->apply();
    sphere->draw();
    glPopMatrix();

    //Clock
    glPushMatrix();
    glTranslated(7.25,7.5,0.1);
    clock->draw();
    glPopMatrix();

    //Plane
    //glPushMatrix();
    //glTranslated(12.0, 4.15, 8.0);
    //glRotated(90.0, 0.0, 1.0, 0.0);
    //glScaled(0.5, 0.5, 0.5);
    //plane->draw();
    //glPopMatrix();

    //Robot

	int mode = -1;

	switch (drawMode)
	{
	case 0:
		mode = GL_FILL;
		break;
	case 1:
		mode = GL_LINE;
		break;
	case 2:
		mode = GL_POINT;
		break;
	default:
		assert(false && "Undefined mode.");
	}

	glPolygonMode(GL_FRONT_AND_BACK, mode);

    glPushMatrix();
    glTranslatef(robot->GetPosition().X, robot->GetPosition().Y, robot->GetPosition().Z);
    glRotatef(robot->GetAngle(), 0.0f, 1.0f, 0.0f);
    robot->draw();
    glPopMatrix();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

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
    delete(light4);
	delete(light5);

    delete(sphere);
    delete(column);
    delete(chair);
    delete(table);
    delete(wall);
    delete(boardA);
    delete(boardB);
    delete(lamp);
    delete(materialA);
    delete(materialB);
    delete(materialW);
    delete(materialF);
    delete(materialC);
    delete(slidesAppearance);
    delete(boardAppearance);
    delete(windowAppearance);
    delete(floorAppearance);
    delete(marbleAppearance);
    delete(fancyAppearance);
    delete(earthAppearance);
    delete(woodAppearance);
	delete(backGroundAppearance);
	delete(nightAppearance);
    delete(clock);
    delete(plane);
    delete(robot);
    delete(impostor);
}

void LightingScene::update(unsigned long millis)
{
    clock->update(millis);
}
