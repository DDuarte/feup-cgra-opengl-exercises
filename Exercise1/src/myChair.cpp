#include "myChair.h"

void myChair::draw()
{
	// PERNAS //
	glPushMatrix();
	glTranslated(0,3.5/4,0);
	glScalef(0.3f, 3.5/2, 0.3f);
	_cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,3.5/4,3.5/2);
	glScalef(0.3f, 3.5/2, 0.3f);
	_cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.5/2,3.5/4,0);
	glScalef(0.3f, 3.5/2, 0.3f);
	_cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.5/2,3.5/4,3.5/2);
	glScalef(0.3f, 3.5/2, 0.3f);
	_cube.draw();
	glPopMatrix();
	//---- JA NAO VÃO SER PERNAS ----//

	//SITIO ONDE METES O CU (OS GAYS PODEM METER NAS PERNAS)//

	glPushMatrix();
	glTranslated(3.5/4,3.5/2+0.3/2,3.5/4);
	glScalef(3.5/2+0.3, 0.3f, 3.5/2+0.3);
	_cube.draw();
	glPopMatrix();
	//-------------------------------------//

	//PODIA ESCREVER ALGO PARVO MAS O DUDU NAO DEIXA... COSTAS//
	glPushMatrix();
	glTranslated(3.5/4,(3.5/2+0.3)/2 + 3.5/2+0.3,0);
	glRotated(90,-1,0,0);
	glScalef(3.5/2+0.3, 0.3f, 3.5/2+0.3);
	_cube.draw();
	glPopMatrix();
	//-----------------------------------//
}

