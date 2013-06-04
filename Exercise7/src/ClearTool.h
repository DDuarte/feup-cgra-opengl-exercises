#ifndef _CLEARTOOL_H_
#define _CLEARTOOL_H_

#include "CanvasTool.h"

class ClearTool : public CanvasTool
{
public:
    ClearTool(CGFcanvas *cnv):CanvasTool(cnv){};

    virtual void mousePressed(int x, int y);
    virtual void mouseReleased(int x, int y);
    virtual void mouseDragged(int x, int y);
};

#endif
