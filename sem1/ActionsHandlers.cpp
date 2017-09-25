#include "ActionsHandlers.h"


ActionsHandlers::ActionsHandlers(PictureBox^ pictureBox)
{
	brezDrawing = gcnew BresenhamDrawing(pictureBox);

	//The default Values for all geometric objects variables are "-1"
	this->point0 = gcnew Point(-1, -1);
	this->point1 = gcnew Point(-1, -1);
	this->radius = -1;
	this->width = -1; 
	this->height = -1;

	this->pictureBox = pictureBox;

	//Arbitary size
	Bitmap^ bitmap = gcnew Bitmap(1920, 1080);
	this->pictureBox->Image = bitmap;

	IsDrawn = false;
}


ActionsHandlers::~ActionsHandlers()
{
	delete brezDrawing;
	delete point0;
	delete point1;
}


void ActionsHandlers::LinePictureBoxOnClickHandler(Point^ point)
{
	//These Rulls apply to Circle and Ellipse handlers

	//Check if the mouse button wasn't pressed the first time
	if (point0->X == -1 && point0->Y == -1)
	{
		point0->X = point->X;
		point0->Y = point->Y;
	}

	//If it was pressed refresh values for the second point
	else
	{
		point1->X = point->X;
		point1->Y = point->Y;
	}

	//If values of all points were refreshed, transfer their to Drawing Layer 
	if (point0->X != -1 && point0->Y != -1 && point1->X != -1 && point1->Y != -1)
	{
		brezDrawing->DrawLine(point0, point1);

		IsDrawn = true;

		//Return default values of points
		point0->X = -1;
		point0->Y = -1;
		point1->X = -1;
		point1->Y = -1;
	}
}

void ActionsHandlers::CirclePictureBoxOnClickHandler(Point^ point)
{
	if (point0->X == -1 && point0->Y == -1)
	{
		point0->X = point->X;
		point0->Y = point->Y;
	}

	else
	{
		radius = sqrt((point->X - point0->X) * (point->X - point0->X) 
			+ (point->Y - point0->Y) * (point->Y - point0->Y));
	}

	if (point0->X != -1 && point0->Y != -1 && radius != -1)
	{
		brezDrawing->DrawCircle(point0, radius);

		IsDrawn = true;

		point0->X = -1;
		point0->Y = -1;
		radius = -1;
	}
}

void ActionsHandlers::EllipsePictureBoxOnClickHandler(Point^ point)
{
	if (point0->X == -1 && point0->Y == -1)
	{
		point0->X = point->X;
		point0->Y = point->Y;
	}

	else
	{
		if (width == -1)
		{
			width = sqrt((point->X - point0->X) * (point->X - point0->X) 
				+ (point->Y - point0->Y) * (point->Y - point0->Y));
		}
		else
		{
			height = sqrt((point->X - point0->X) * (point->X - point0->X)
				+ (point->Y - point0->Y) * (point->Y - point0->Y));
		}
	}

	if (point0->X != -1 && point0->Y != -1 && width != -1 && height != -1)
	{
		brezDrawing->DrawEllipse(point0, width, height);

		IsDrawn = true;

		point0->X = -1;
		point0->Y = -1;
		width = -1;
		height = -1;
	}
}


