#include "FillTool.h"

void FillTool::mousePressed(int x, int y)
{
    canvas->setColor(0);
    drawFill(x,y);
}

void FillTool::mouseDragged(int x, int y)
{
    canvas->setColor(0);
    drawFill(x,y);
}

void FillTool::mouseReleased(int x, int y)
{
}

void FillTool::drawFill(int x, int y)
{
    if (canvas->getPixel(x, y) == 255 && x < 512 && y < 512)
    {
        canvas->setPixel(x, y);
        drawFill(x + 1, y);
        drawFill(x - 1, y);
        drawFill(x, y + 1);
        drawFill(x, y - 1);
    }
}
