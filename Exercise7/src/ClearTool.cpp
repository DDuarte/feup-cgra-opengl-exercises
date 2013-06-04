#include "ClearTool.h"

void ClearTool::mousePressed(int x, int y)
{
    mouseDragged(x, y);
}

void ClearTool::mouseDragged(int x, int y)
{
    canvas->setColor(255);

    for (int x = 0; x < 512; ++x)
        for (int y = 0; y < 512; ++y)
            canvas->setPixel(x,y);
}

void ClearTool::mouseReleased(int x, int y)
{
}

