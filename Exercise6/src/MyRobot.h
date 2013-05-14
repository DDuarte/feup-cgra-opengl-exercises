#ifndef MYROBOT_H_
#define MYROBOT_H_

#include "CGFobject.h"
#include "CGFappearance.h"
#include "Point.h"
#include <vector>

#include "utilities.h"

#define ANGLE_INC 5.0f
#define POS_INC 0.5f

#define MAX_ROBOT_TEXTURES 3
static const char* AVAILABLE_ROBOT_TEXTURES[MAX_ROBOT_TEXTURES] =
{
    "robot1.jpg",
    "robot2.jpg",
    "robot3.jpg"
};

class MyRobot : public CGFobject
{
private:
    std::vector<std::vector<Point>> _vertices;
    std::vector<std::vector<Point>> _normals;
    int _stacks;

    Point _position;
    float _angle;
    float _radAngle;

    CGFappearance* _skins[MAX_ROBOT_TEXTURES];
    int _currentSkin;

public:
    MyRobot(int stacks);
    ~MyRobot();
    void RotateLeft() { SetAngle(_angle + ANGLE_INC); }
    void RotateRight() { SetAngle(_angle - ANGLE_INC); }
    void MoveForward() { _position.X += POS_INC * sin(_radAngle); _position.Z += POS_INC * cos(_radAngle); }
    void MoveBackward() { _position.X -= POS_INC * sin(_radAngle); _position.Z -= POS_INC * cos(_radAngle); }
    void MoveUp()  { _position.Y += POS_INC; }
    void MoveDown()  { _position.Y -= POS_INC; }

    float GetAngle() const { return _angle; }
    const Point& GetPosition() const { return  _position; }

    void SetAngle(float angle) { _angle = angle; _radAngle = rad(angle); }

    void SetSkin(int skin) { _currentSkin = skin; }

    virtual void draw() override;
};

#endif // MYROBOT_H_
