#include "TPinterface.h"
#include "LightingScene.h"

TPinterface::TPinterface()
{
	testVar=0;
}


void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	// CGFinterface::processKeyboard(key, x, y);

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
}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
	printf ("GUI control id: %d\n  ", ctrl->user_id);
	switch (ctrl->user_id)
	{
		case 1:
		{
			printf("Light 1 changed: %d\n", ((LightingScene*) scene)->lightsSwitcher[0]);
			break;
		}
	}
}

