#include "myTable.h"

myTable::myTable()
{
    angle = rand() % 21 - 10;
    transl = rand() % 1 - 1;
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

    glPushMatrix();
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glTranslatef(transl, 0.0f, transl*0.5f);

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

    glPopMatrix();
}
