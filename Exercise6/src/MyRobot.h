#ifndef MYROBOT_H_
#define MYROBOT_H_

#include "CGFobject.h"
#include "Point.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define ANGLE_INC 5.0f
#define POS_INC 0.5f

class MyRobot : public CGFobject
{
private:
    Point _position;
    float _angle;
    float _radAngle;

public:
    MyRobot() : _position(10.0f, 0.5f, 8.0f) { SetAngle(200.0f); }
    void RotateLeft() { SetAngle(_angle + ANGLE_INC); }
    void RotateRight() { SetAngle(_angle - ANGLE_INC); }
    void MoveForward() { _position.X += POS_INC * sin(_radAngle); _position.Z += POS_INC * cos(_radAngle); }
    void MoveBackward() { _position.X -= POS_INC * sin(_radAngle); _position.Z -= POS_INC * cos(_radAngle); }

    float GetAngle() const { return _angle; }
    const Point& GetPosition() const { return  _position; }

    void SetAngle(float angle) { _angle = angle; _radAngle = angle * M_PI / 180.0f; }

    virtual void draw() override;
};

#endif // MYROBOT_H_
