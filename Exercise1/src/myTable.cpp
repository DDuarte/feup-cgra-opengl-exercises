#include "myTable.h"

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

    // table top
    glPushMatrix();
    glTranslatef(0.0f, 1.75f + 0.15f + 3.5f / 2, 0.0f);
    glScalef(5.0f, 0.3f, 3.0f);
    _unitCube.draw();
    glPopMatrix();

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
