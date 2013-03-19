#include "myComplexLamp.h"


void myComplexLamp::draw()
{
	glPushMatrix();
	_cube.draw();
	glPopMatrix();

    static int rot = 0;

    glPushMatrix();

    glRotated(rot, 0, 1.0, 0);

    rot++;

	glPushMatrix();
	glScaled(0.2, 0.2, 2.0);
	glTranslated(0.0, 0.0, 0.1);
	_cyli.draw();
	glPopMatrix();

	glPushMatrix();
    glTranslated(0.0, 0.0f, 2.5f);
    _cube.draw();
	glPopMatrix();

	glPushMatrix();
    glTranslated(0.0f, -1.5f, 2.5f);
    glRotated(-90.0, 1.0, 0.0, 0.0);
    _lamp.draw();
	glPopMatrix();

	glPushMatrix();
    glTranslated(0.0f, -1.5f, -1.5f);
    _cube.draw();
	glPopMatrix();

	glPushMatrix();
    glRotated(90.0 + 45.0, 1.0, 0.0, 0.0);
    glScaled(0.2, 0.2, 2.0);
    _cyli.draw();
	glPopMatrix();

	glPushMatrix();
    glTranslated(0.0f, -3.5f, -1.5f);
    glRotated(-90.0, 1.0, 0.0, 0.0);
    glScaled(0.2, 0.2, 2.0);
    _cyli.draw();
	glPopMatrix();

    glPushMatrix();
    glTranslated(0.0f, -4.5f, -1.5f);
    glRotated(-90.0, 1.0, 0.0, 0.0);
    _lamp.draw();

    float pos[] = { 5.0f, 5.0f, 5.0f, 1.0f };

    CGFlight light(GL_LIGHT4, pos);
    light.enable();
    //light.draw();

    glPopMatrix();

    glPopMatrix();
}
