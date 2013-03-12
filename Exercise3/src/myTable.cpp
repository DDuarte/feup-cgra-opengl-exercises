#include "myTable.h"

#include <CGF/CGFappearance.h>

float ambWood[3] = {0.5, 0.5, 0.5};
float difWood[3] = {0.522, 0.369, 0.259};
float specWood[3] = {0.1, 0.1, 0.1};
float shininessWood = 10.f;

float ambSteel[3] = {0.5, 0.5, 0.5};
float difSteel[3] = {0.75, 0.75, 0.75};
float specSteel[3] = {0.8, 0.8, 0.8};
float shininessSteel = 150.f;

myTable::myTable()
{
    _wood  = new CGFappearance(ambWood,difWood,specWood,shininessWood);
    _steel = new CGFappearance(ambSteel,difSteel,specSteel,shininessSteel);
}

myTable::~myTable()
{
    delete(_wood);
    delete(_steel);
}

void myTable::draw() 
{
    // -z
    //  ^         5
    //  | -----------------
    //  | |1             3|
    //  | |               |
    //  --|-------o-------|---> +x   3
    //    |               |
    //    |2             4|
    //    -----------------

    _wood->apply();

    // table top
    glPushMatrix();
    glTranslatef(0.0f, 1.75f + 0.15f + 3.5f / 2, 0.0f);
    glScalef(5.0f, 0.3f, 3.0f);
    _unitCube.draw();
    glPopMatrix();

    _steel->apply();

    // leg 1
    glPushMatrix();
    glTranslatef(-2.2f, 3.5f / 2, -1.2f);
    glScalef(0.3f, 3.5f, 0.3f);
    _unitCube.draw();
    glPopMatrix();

    // leg 2
    glPushMatrix();
    glTranslatef(-2.2f, 3.5f / 2, +1.2f);
    glScalef(0.3f, 3.5f, 0.3f);
    _unitCube.draw();
    glPopMatrix();

    // leg 3
    glPushMatrix();
    glTranslatef(+2.2f, 3.5f / 2, -1.2f);
    glScalef(0.3f, 3.5f, 0.3f);
    _unitCube.draw();
    glPopMatrix();

    // leg 4
    glPushMatrix();
    glTranslatef(+2.2f, 3.5f / 2, +1.2f);
    glScalef(0.3f, 3.5f, 0.3f);
    _unitCube.draw();
    glPopMatrix();

}
