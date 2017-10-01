
//	This class is a controller of MyForm.
//	It performs the function of handlers of some form objects and
//	transfer parametrs to Graphics layer.

#pragma once

#include "BresenhamDrawing.h"

using namespace System::Windows::Forms;
using namespace System;
using namespace System::IO;

ref class ActionsHandlers
{

private:
	
	Form^ clipForm;
	PictureBox^ clipPictureBox;

	//Reference to the Graphics layer object
	BresenhamDrawing^ brezDrawing;

	//Reference to the PictureBox from MyForm
	PictureBox^ pictureBox;

	Color color;

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

	void SetColor(Color c);

	ActionsHandlers(PictureBox^ pictureBox, Color c);
	ActionsHandlers();
	~ActionsHandlers();

	//Point is cursor values relatively pictureBox

	//Line was checked in MyForm by User
	void LinePictureBoxOnClickHandler(Point^ point);

	//Circle was checked in MyForm by User
	void CirclePictureBoxOnClickHandler(Point^ point);

	//Ellipse was checked in MyForm by User
	void EllipsePictureBoxOnClickHandler(Point^ point);

	void LineFillingAreaPictureBoxOnClickHandler(Point^ point);

	void PolygonFillingAreaPictureBoxOnClickHandler(Point^ point);

	void ClippingHandler(Point^ point);

	void RandomButtonClickHandler();

	void getObjectsFormFileClickHandler();
	void OnClosed(System::Object ^sender, System::EventArgs ^e);
};


