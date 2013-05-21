#include "TPinterface.h"
#include "LightingScene.h"
#include <iostream>

void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
    switch (::tolower(key))
    {
        case 'j':
        {
            ((LightingScene *) scene)->RobotRotateLeft();
            break;
        }
        case 'l':
        {
            ((LightingScene *) scene)->RobotRotateRight();
            break;
        }
        case 'i':
        {
            ((LightingScene *) scene)->RobotMoveForward();
            break;
        }
        case 'k':
        {
            ((LightingScene *) scene)->RobotMoveBackward();
            break;
        }
        case 'o':
        {
            ((LightingScene *) scene)->RobotMoveUp();
            break;
        }
        case 'p':
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

    GLUI_Panel* lightsPanel = addPanel("Luzes");

    for (int i = 0; i < 6; ++i)
        addCheckboxToPanel(lightsPanel, const_cast<char*>((std::string("Luz ") + std::to_string(i + 1)).c_str()), &((LightingScene*) scene)->lightsSwitcher[i]);

    addColumn();

    GLUI_Panel* clockPanel = addPanel("Relogio");
    addButtonToPanel(clockPanel, "Parar/Reiniciar", 1);

    addColumn();

    GLUI_Panel* visPanel = addPanel("Visualizacao");
    GLUI_Listbox* lb = addListboxToPanel(visPanel, "Robo", &((LightingScene*) scene)->currentRobotTexture, 2);
    for (int i = 0; i < MAX_ROBOT_TEXTURES; ++i)
        lb->add_item(i, AVAILABLE_ROBOT_TEXTURES[i]);

    GLUI_RadioGroup* rg = addRadioGroupToPanel(visPanel, &((LightingScene*) scene)->drawMode);
    addRadioButtonToGroup(rg, "Textured")->activate(1);
    addRadioButtonToGroup(rg, "Wireframe");
    addRadioButtonToGroup(rg, "Points");

    addColumn();
}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
    std::cout << "GUI control id: " << ctrl->user_id << std::endl;
    switch (ctrl->user_id)
    {
        case 1:
        {
            ((LightingScene*)scene)->PauseRebootClock();
            break;
        }
        case 2:
        {
            int currTex = ((LightingScene*) scene)->currentRobotTexture;
            ((LightingScene*) scene)->robot->SetSkin(currTex);

            break;
        }
    }
}

