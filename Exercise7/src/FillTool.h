#ifndef _FILLTOOL_H_
#define _FILLTOOL_H_

#include "CanvasTool.h"

class FillTool : public CanvasTool
{
public:
    FillTool(CGFcanvas *cnv):CanvasTool(cnv){};

    virtual void mousePressed(int x, int y);
    virtual void mouseReleased(int x, int y);
    virtual void mouseDragged(int x, int y);

    virtual void drawFill(int x, int y);
};

#endif
