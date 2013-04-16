#ifndef MYCLOCKHAND_H
#define MYCLOCKHAND_H

#include "myUnitCube.h"

class myClockHand : public CGFobject
{
private:
    myUnitCube* _cube;
    float _angle;
    float _size;
public:
    myClockHand();
    myClockHand(float n);
    ~myClockHand();
    virtual void draw();
    void incAngle(float inc) { _angle += inc; }
    float getAngle() const {return _angle;}
    void setAngle(float angle) { _angle = angle; }
private:

};


#endif