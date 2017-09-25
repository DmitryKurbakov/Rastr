
//	This class is a controller of MyForm.
//	It performs the function of handlers of some form objects and
//	transfer parametrs to Graphics layer.

#pragma once

#include "BresenhamDrawing.h"

using namespace System::Windows::Forms;

ref class ActionsHandlers
{

private:
	
	//Reference to the Graphics layer object
	BresenhamDrawing^ brezDrawing;

	//Reference to the PictureBox from MyForm
	PictureBox^ pictureBox;

	//------------------------------------------------------------------
	//Geometric Objects Variables
	//------------------------------------------------------------------
	//Points for drawing which will be trancefered to the Drawing layer
	Point^ point0;
	Point^ point1;

	//Radius of Circle
	int radius;

	//Two radiuses of ellipse
	int width, height;

public:

	bool IsDrawn;

	ActionsHandlers(PictureBox^ pictureBox);
	~ActionsHandlers();

	//Point is cursor values relatively pictureBox

	//Line was checked in MyForm by User
	void LinePictureBoxOnClickHandler(Point^ point);

	//Circle was checked in MyForm by User
	void CirclePictureBoxOnClickHandler(Point^ point);

	//Ellipse was checked in MyForm by User
	void EllipsePictureBoxOnClickHandler(Point^ point);
};


