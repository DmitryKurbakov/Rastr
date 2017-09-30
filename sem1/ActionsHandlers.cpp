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

ActionsHandlers::ActionsHandlers()
{
	throw gcnew System::NotImplementedException();
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

void ActionsHandlers::LineFillingAreaPictureBoxOnClickHandler(Point ^ point)
{
	Bitmap^ bmp = gcnew Bitmap(pictureBox->Image);
	delete pictureBox->Image;
	pictureBox->Image = brezDrawing->LineFillWithSeed(bmp, point->X, point->Y, Color::Green);
}

void ActionsHandlers::PolygonFillingAreaPictureBoxOnClickHandler(Point ^ point)
{
	Bitmap^ bmp = gcnew Bitmap(pictureBox->Image);
	delete pictureBox->Image;
	pictureBox->Image = brezDrawing->PolygonFill(bmp, point->X, point->Y, Color::Green);
}

void ActionsHandlers::RandomButtonClickHandler()
{
	Random^ rnd = gcnew Random();
	int figuresCount = rnd->Next(1, 10);
	
	for (int i = 0; i < figuresCount; i++)
	{
		int	choice = rnd->Next(1, 3);

		if (choice == 1)
		{
			point0->X = rnd->Next(0, pictureBox->Width);
			point0->Y = rnd->Next(0, pictureBox->Height);
			point1->X = rnd->Next(0, pictureBox->Width);
			point1->Y = rnd->Next(0, pictureBox->Height);

			brezDrawing->DrawLine(point0, point1);
		}

		if (choice == 2)
		{
			point0->X = rnd->Next(0, pictureBox->Width);
			point0->Y = rnd->Next(0, pictureBox->Height);
			radius = rnd->Next(0, pictureBox->Height);

			brezDrawing->DrawCircle(point0, radius);
		}

		if (choice == 3)
		{
			point0->X = rnd->Next(0, pictureBox->Width);
			point0->Y = rnd->Next(0, pictureBox->Height);
			width = rnd->Next(0, pictureBox->Height);
			height = rnd->Next(0, pictureBox->Height);

			brezDrawing->DrawEllipse(point0, width, height);
		}
	}
}

void ActionsHandlers::getObjectsFormFileClickHandler()
{
	String^ fileName = "objects.txt";
	try
	{
		Console::WriteLine("trying to open file {0}...", fileName);
		StreamReader^ din = File::OpenText(fileName);

		array<String^>^ objects = din->ReadToEnd()->Split(';');

		String^ figure;
		array<String^>^ values;

		for each (String^ obj in objects)
		{
			figure = obj->Split(':')[0]->ToLower()->Trim();
			values = obj->Split(':')[1]->Split(',');

			if (String::Compare(figure, "line") == 0)
			{
				point0->X = Int32::Parse(values[0]->Trim());
				point0->Y = Int32::Parse(values[1]->Trim());
				point1->X = Int32::Parse(values[2]->Trim());
				point1->Y = Int32::Parse(values[3]->Trim());

				brezDrawing->DrawLine(point0, point1);
			}

			if (String::Compare(figure, "circle") == 0)
			{
				point0->X = Int32::Parse(values[0]->Trim());
				point0->Y = Int32::Parse(values[1]->Trim());
				radius = Int32::Parse(values[2]->Trim());

				brezDrawing->DrawCircle(point0, radius);
			}

			if (String::Compare(figure, "ellipse") == 0)
			{
				point0->X = Int32::Parse(values[0]->Trim());
				point0->Y = Int32::Parse(values[1]->Trim());
				width = Int32::Parse(values[2]->Trim());
				height = Int32::Parse(values[3]->Trim());

				brezDrawing->DrawEllipse(point0, width, height);
			}
		}
		
	}
	catch (Exception^ e)
	{
		if (dynamic_cast<FileNotFoundException^>(e))
			Console::WriteLine("file '{0}' not found", fileName);
		else
			Console::WriteLine("problem reading file '{0}'", fileName);
	}
}




