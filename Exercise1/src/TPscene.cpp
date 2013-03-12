#include "TPscene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#include "CGFappearance.h"

CGFappearance *mat1;

void TPscene::init() 
{
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient);  // Define ambient light
	
	// Declares and enables a light
	float light0_pos[4] = {4.0, 6.0, 5.0, 1.0};
	CGFlight* light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->enable();

	// Defines a default normal
	glNormal3f(0,0,1);

    chairs.resize(20);
    tables.resize(20);
}

void TPscene::display() 
{
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	// Draw axis
	axis.draw();

    glPushMatrix();
    glTranslatef(20.0f, 0.00f, 20.0f);
    floor.draw();
    glPopMatrix();

    int x = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            glPushMatrix();
            glTranslatef(i * 10.0f + 5.0f, 0.1f, j * 10.0f + 5.0f);
            tables[x].draw();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(i * 10.0f + 4.0f, 0.1f, j * 10.0f + 2.0f);
            chairs[x].draw();
            glPopMatrix();

            x++;
        }
    }

    // swap buffers
	glutSwapBuffers();
}
