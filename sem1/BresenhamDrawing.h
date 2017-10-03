
//	This class is a Drawing layer.
//	it includes methods for drawing geometric object in pictture box
//	using Algoritm layer and draw their using the Graphics class

#pragma once

#include "BresenhamAlgorithm.h"
#include "GeometricObject.h"
#include "Line.h"
#include "Circle.h"
#include "Ellipse.h"

using namespace System::Drawing;

ref class BresenhamDrawing :
	public BresenhamAlgorithm
{
private:

	System::Collections::Generic::List<GeometricObject^>^ geometricObjectList;
	System::Collections::Generic::List<GeometricObject^>^ geometricObjectListForPolygonFilling;

	Bitmap^ temp_bitmap;

	//Method of setting pixels on the picture using Algorithm layer
	Bitmap^ Draw(Bitmap^ bmp, Color c);
	Bitmap^ Draw(Bitmap^ bmp, System::Collections::Generic::List<GeometricObject^>^ geometricObjectListForPolygonFilling, Color c);

	bool IsBorder(Bitmap^ bmp, int x, int y);

	//Reference to the PictureBox from MyForm
	System::Windows::Forms::PictureBox^  pictureBox;

	int ComputeOutCode(int xL, int yT, int xR, int yB, int x, int y);

public:

	BresenhamDrawing(System::Windows::Forms::PictureBox^ pictureBox);
	~BresenhamDrawing();
	System::Windows::Forms::PictureBox^ getPictureBox();

	//Draw line in the PictureBox using two methods: Bresenham algorithm and Graphics.DrawLine(...)
	//void DrawLine(int x0, int y0, int x1, int y1);
	Bitmap^ DrawLine(Bitmap^ bmp, Point^ point0, Point^ point1, Color c, bool addToList);

	//Draw circle in the PictureBox using two methods: Bresenham algorithm and Graphics.DrawEllipse(...)
	//void DrawCircle(int x0, int y0, int radius);
	Bitmap^ DrawCircle(Bitmap^ bmp, Point^ center, int radius, Color c, bool addToList);

	//Draw ellipse in the PictureBox using two methods: Bresenham algorithm and Graphics.DrawEllipse(...)
	//void DrawEllipse(int x0, int y0, int width, int height);
	Bitmap^ DrawEllipse(Bitmap^ bmp, Point^ center, int width, int height, Color c, bool addToList);

	Bitmap^ LineFillWithSeed(Bitmap^ bm, int x, int y, Color c);
	Bitmap^ PolygonFill(Bitmap^ bmp, int x, int y, Color c);

	Bitmap^ DrawObjectsByPoints(Bitmap^ inputBitmap, Color back);

	System::Collections::Generic::List<Line^>^ Clip(int x0, int y0, int x1, int y1, bool isColorful);
	System::Collections::Generic::List<Line^>^ GetLines();

	void RemoveUnusedObjects(int x, int y);
};