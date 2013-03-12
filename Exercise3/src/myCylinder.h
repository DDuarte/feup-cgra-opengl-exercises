#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGF/CGFobject.h"
#include <vector>
#include <cmath>

#define PI       3.14159265358979323846

struct Point
{
	double x;
	double y;
	double z;

	Point(double x, double y, double z): x(x), y(y), z(z){}
};



class myCylinder : public CGFobject {
private:
	int _slices;
	int _stacks;
	std::vector<std::vector<Point> > vec;

public:
	myCylinder(int slices, int stacks/*, bool smooth*/);
	void draw();
};



#endif
