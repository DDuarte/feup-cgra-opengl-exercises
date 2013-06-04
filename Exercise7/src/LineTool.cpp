#include "LineTool.h"
#include <cmath>

void LineTool::mousePressed(int x, int y)
{
	// Reset start coordinates and active (current) coordinates
	sx=x;
	sy=y;
	currx=x;
	curry=y;

	// Activate XOR mode with inverted color to enable rubber-banding
	canvas->setXORMode();
	canvas->setColor(255);

	// Draw first line (one pixel)
	canvas->setPixel(sx,sy);
}

void LineTool::mouseDragged(int x, int y)
{
	// Redraw previous line (in XOR mode, will invert the color of all pixels, effectively erasing it)
	drawLine(sx,sy,currx,curry);

	// Update current coordinates
	currx=x;
	curry=y;

	// Draw new line
	drawLine(sx,sy,currx,curry);
}

void LineTool::mouseReleased(int x, int y)
{
	// Redraw previous line to erase it
	drawLine(sx,sy,currx,curry);

	// Set normal mode and color to draw final line
	canvas->setNormalMode();
	canvas->setColor(0);

	// draw final line
	drawLine(sx,sy,x,y);
}



void LineTool::drawLine(int xi, int yi, int xf, int yf)
{
	//deltas
	int dx = abs(xf - xi);
	int dy = abs(yf - yi);

	//sinal
	int sx = xi < xf ? 1 : -1;
	int sy = yi < yf ? 1 : -1;

	int err = dx - dy;

	while (xi != xf || yi != yf)
	{
		canvas->setPixel(xi, yi);

		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			xi += sx;
		}

		if (xi == xf && yi == yf)
			canvas->setPixel(xi, yi);

		else if (e2 < dx)
		{
			err += dx;
			yi += sy;
		}
	}
}