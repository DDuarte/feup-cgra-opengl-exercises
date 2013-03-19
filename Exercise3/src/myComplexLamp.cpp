#include "myComplexLamp.h"


void myComplexLamp::draw()
{
	/*
	glPushMatrix();
	_cube.draw();
	glPopMatrix();
	*/
	glPushMatrix();
	glScaled(0,0,5);
	glTranslated(0,0,0.5 + 2.5);
	_cyli.draw();
	glPopMatrix();

	glPushMatrix();
	glPopMatrix();

	glPushMatrix();
	glPopMatrix();

	glPushMatrix();
	glPopMatrix();

	glPushMatrix();
	glPopMatrix();

	glPushMatrix();
	glPopMatrix();
}
