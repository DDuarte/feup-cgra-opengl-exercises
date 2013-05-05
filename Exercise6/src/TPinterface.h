#ifndef TPinterface_H
#define TPinterface_H

#include "CGFinterface.h"
#include "LightingScene.h"

class TPinterface: public CGFinterface
{
public:
    virtual void initGUI() override;
    virtual void processGUI(GLUI_Control *ctrl) override;

    virtual void processKeyboard(unsigned char key, int x, int y) override;
};

#endif
