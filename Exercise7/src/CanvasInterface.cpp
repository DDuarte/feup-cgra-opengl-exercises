#include "CanvasInterface.h"
#include "CanvasScene.h"
#include "CGFapplication.h"

#include "PointTool.h"
#include "LineTool.h"
#include "ClearTool.h"
#include "CircleTool.h"
#include "FillTool.h"

void CanvasInterface::convertCoords(int *x, int *y)
{
	// Converts GLUI coordinate space to viewport/texture coordinate space
	*x=*x-CGFapplication::vpx;
	*y=CGFapplication::height-*y-CGFapplication::vpy;
}

void CanvasInterface::processMouse(int button, int state, int x, int y)
{
	// convert coordinates
	convertCoords(&x, &y);

	// invoke active tool's mouse pressed or mouse released depending on lft button state
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		pressing_left=true;
		tools[activeToolID]->mousePressed(x,y);
	}
	else if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP))
	{
		pressing_left=false;
		tools[activeToolID]->mouseReleased(x,y);
	}
}

void CanvasInterface::processMouseMoved(int x, int y)
{
	// convert coordinates
	convertCoords(&x, &y);

	// if left mouse button is signalled as pressed, invoke active tool's
	if(pressing_left)
		tools[activeToolID]->mouseDragged(x,y);

}

void CanvasInterface::initGUI()
{
	// init Tools
	tools[0]=new PointTool(((CanvasScene*)scene)->canvas);
	tools[1]=new LineTool(((CanvasScene*)scene)->canvas);
    tools[2]=new ClearTool(((CanvasScene*)scene)->canvas);
	tools[3]=new CircleTool(((CanvasScene*)scene)->canvas);
    tools[4]=new FillTool(((CanvasScene*)scene)->canvas);
	// you may add more tools here, provided that you:
	//	 - adjust the value of TOOL_SIZE in the header file 
	//	 - add "includes" to the corresponding tools in the top of this file

	// set default tool
	activeToolID=0;

	// init tools' interface
	GLUI_Panel *varPanel= addPanel("Tools");

	GLUI_RadioGroup *toolRG=addRadioGroupToPanel(varPanel, &activeToolID,-1);
	addRadioButtonToGroup(toolRG,"Point");
	addRadioButtonToGroup(toolRG,"Line");
    addRadioButtonToGroup(toolRG,"Clear");
	addRadioButtonToGroup(toolRG,"Circle");
    addRadioButtonToGroup(toolRG,"Fill");
	// if you add more tools above, you should add a radio button in the same order here

	// select the radio button corresponding to the default tool
	toolRG->set_int_val(activeToolID);
}

void CanvasInterface::processGUI(GLUI_Control *ctrl)
{
}

