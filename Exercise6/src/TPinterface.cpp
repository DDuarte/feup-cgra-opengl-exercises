#include "TPinterface.h"
#include "LightingScene.h"
#include <iostream>

TPinterface::TPinterface()
{
}

void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'J':
        case 'j':
        {
            ((LightingScene *) scene)->RobotRotateLeft();
            break;
        }
        case 'L':
        case 'l':
        {
            ((LightingScene *) scene)->RobotRotateRight();
            break;
        }
        case 'I':
        case 'i':
        {
            ((LightingScene *) scene)->RobotMoveForward();
            break;
        }
        case 'K':
        case 'k':
        {
            ((LightingScene *) scene)->RobotMoveBackward();
            break;
        }
        case 'o':
        case 'O':
        {
            ((LightingScene *) scene)->RobotMoveUp();
            break;
        }
        case 'p':
        case 'P':
        {
            ((LightingScene *) scene)->RobotMoveDown();
            break;
        }
    }
}

void TPinterface::initGUI()
{
    /*
    // Check CGFinterface.h and GLUI documentation for the types of controls available
    GLUI_Panel *varPanel = addPanel("Group", 1);
    addSpinnerToPanel(varPanel, "Val 1(interface)", 2, &testVar, 1);

    // You could also pass a reference to a variable from the scene class, if public
    addSpinnerToPanel(varPanel, "Val 2(scene)", 2, &(((LightingScene*) scene)->sceneVar), 2);

    */

    GLUI_Panel* lightsPanel = addPanel("Luzes", 1);

    for (int i = 0; i < 5; ++i)
        addCheckboxToPanel(lightsPanel, const_cast<char*>((std::string("Luz ") + std::to_string(i + 1)).c_str()), &((LightingScene*) scene)->lightsSwitcher[i], i + 1);

    GLUI_Panel* clockPanel = addPanel("Relogio", 1);
    addButtonToPanel(clockPanel, "Parar/Reiniciar", 2);
}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
    std::cout << "GUI control id: " << ctrl->user_id << std::endl;
    switch (ctrl->user_id)
    {
        //case 1:
        //{
        //    printf("Light 1 changed: %d\n", ((LightingScene*) scene)->lightsSwitcher[0]);
        //    break;
        //}
        case 2:
        {
            ((LightingScene*)scene)->PauseRebootClock();
            break;
        }
    }
}

