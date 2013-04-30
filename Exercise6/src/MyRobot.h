#ifndef MYROBOT_H_
#define MYROBOT_H_

#include "CGFobject.h"
#include "Point.h"
#include <vector>

#include "utilities.h"

#define ANGLE_INC 5.0f
#define POS_INC 0.5f

class MyRobot : public CGFobject
{
private:
    std::vector<std::vector<Point>> _vertices;
    int _stacks;

    std::vector<Point> _normals;

    Point _position;
    float _angle;
    float _radAngle;

public:
    MyRobot(int stacks);
    void RotateLeft() { SetAngle(_angle + ANGLE_INC); }
    void RotateRight() { SetAngle(_angle - ANGLE_INC); }
    void MoveForward() { _position.X += POS_INC * sin(_radAngle); _position.Z += POS_INC * cos(_radAngle); }
    void MoveBackward() { _position.X -= POS_INC * sin(_radAngle); _position.Z -= POS_INC * cos(_radAngle); }
    void MoveUp()  { _position.Y += POS_INC; }
    void MoveDown()  { _position.Y -= POS_INC; }

    float GetAngle() const { return _angle; }
    const Point& GetPosition() const { return  _position; }

    void SetAngle(float angle) { _angle = angle; _radAngle = rad(angle); }

    virtual void draw() override;
};

#endif // MYROBOT_H_
