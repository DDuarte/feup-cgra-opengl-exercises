#include "CGFobject.h"
#include "Point.h"
#include <functional>
#include <vector>

class myImpostorWall : public CGFobject
{
public:
    myImpostorWall(/*int numDivisions*/);
    virtual void draw() override { draw([](float f) { return f; }, [](float f) { return f; }); }
    void draw(std::function<float(float)> sfunc, std::function<float(float)> tfunc);

private:
    std::vector<Point> _points;
};

