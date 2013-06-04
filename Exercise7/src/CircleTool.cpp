#include "CircleTool.h"
#include <cmath>

void CircleTool::mousePressed(int x, int y)
{
	// Reset start coordinates and active (current) coordinates
	sx=x;
	sy=y;
	currx=x;
	curry=y;

	// Activate XOR mode with inverted color to enable rubber-banding
	canvas->setXORMode();
	canvas->setColor(255);

	// Draw first circle (one pixel)
	drawCircle(sx,sy,currx,curry);
}

void CircleTool::mouseDragged(int x, int y)
{
	// Redraw previous circle (in XOR mode, will invert the color of all pixels, effectively erasing it)
	drawCircle(sx,sy,currx,curry);

	// Update current coordinates
	currx=x;
	curry=y;

	// Draw new circle
	drawCircle(sx,sy,currx,curry);
}

void CircleTool::mouseReleased(int x, int y)
{
	// Redraw previous circle to erase it
	drawCircle(sx,sy,currx,curry);

	// Set normal mode and color to draw final circle
	canvas->setNormalMode();
	canvas->setColor(0);

	// draw final circle
	drawCircle(sx,sy,x,y);
}



void CircleTool::drawCircle(int xi, int yi, int xf, int yf)
{
	float r = sqrt( pow(xf - xi , 2) + pow(yf - yi, 2));

	/*
	for(int i = 0 ; i < 512; i++)
	for(int j = 0 ; j < 512; j++)
	if(pow(i - xi, 2) + pow(j - yi, 2) <= pow(r,2))
	canvas->setPixel(i,j);
	Worst Solution Ever!
	*/

	int x = (int)r;
	int y = 0;

	int err = 1 - x;

	while (x >= y)
	{	
		canvas->setPixel(x + xi, y + yi);
		canvas->setPixel(y + xi, x + yi);
		canvas->setPixel(-x + xi, y + yi);
		canvas->setPixel(-y + xi, x + yi);
		canvas->setPixel(-x + xi, -y + yi);
		canvas->setPixel(-y + xi, -x + yi);
		canvas->setPixel(x + xi, -y + yi);
		canvas->setPixel(y + xi, -x + yi);

		y++;

		if (err < 0)
			err += 2 * y + 1;
		else
		{
			x--;
			err += 2 * (y - x) + 1;
		}
	}
}