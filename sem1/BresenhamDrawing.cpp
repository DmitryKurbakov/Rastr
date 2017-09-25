#include "BresenhamDrawing.h"

BresenhamDrawing::BresenhamDrawing(System::Windows::Forms::PictureBox^ pictureBox)
{
	this->pictureBox = pictureBox;
}


BresenhamDrawing::~BresenhamDrawing()
{
	delete temp_bitmap;
}


System::Windows::Forms::PictureBox ^ BresenhamDrawing::getPictureBox()
{
	return this->pictureBox;
}

void BresenhamDrawing::DrawLine(int x0, int y0, int x1, int y1)
{
	BresenhamLine(x0, y0, x1, y1);
	Draw();
}

void BresenhamDrawing::DrawLine(Point^ point0, Point^ point1)
{

	//Draw line using the Graphics method with red pen
	Bitmap^ bitmap = gcnew Bitmap(pictureBox->Image);
	Graphics^ graphics = Graphics::FromImage(bitmap);

	Pen^ redPen = gcnew Pen(Color::Red);
	graphics->DrawLine(redPen, point0->X, point0->Y, point1->X, point1->Y);

	bitmap->SetPixel(point0->X, point0->Y, Color::Black);
	bitmap->SetPixel(point1->X, point1->Y, Color::Black);

	delete pictureBox->Image;
	pictureBox->Image = bitmap;

	//Draw line using the Bresenham method with black pen
	BresenhamLine(point0->X, point0->Y, point1->X, point1->Y);
	Draw();

	delete bitmap;
	delete graphics;
	delete redPen;
}

void BresenhamDrawing::DrawCircle(int x0, int y0, int radius)
{
	BresenhamCircle(x0, y0, radius);
	Draw();
}

void BresenhamDrawing::DrawCircle(Point^ center, int radius)
{
	//Draw cirle using the Graphics method with red pen
	Bitmap^ bitmap = gcnew Bitmap(pictureBox->Image);
	Graphics^ graphics = Graphics::FromImage(bitmap);

	Pen^ redPen = gcnew Pen(Color::Red);
	graphics->DrawEllipse(redPen, center->X - radius, center->Y - radius, radius * 2, radius * 2);

	delete pictureBox->Image;

	bitmap->SetPixel(center->X, center->Y, Color::Black);
	pictureBox->Image = bitmap;

	//Draw cirle using the Bresenham method with black pen
	BresenhamCircle(center->X, center->Y, radius);
	Draw();

	

	delete bitmap;
	delete graphics;
	delete redPen;
}

void BresenhamDrawing::DrawEllipse(int x0, int y0, int width, int height)
{
	BresenhamEllipse(x0, y0, width, height);
	Draw();
}

void BresenhamDrawing::DrawEllipse(Point^ center, int width, int height)
{

	//Draw cirle using the Graphics method with red pen
	Bitmap^ bitmap = gcnew Bitmap(pictureBox->Image);
	Graphics^ graphics = Graphics::FromImage(bitmap);

	Pen^ redPen = gcnew Pen(Color::Red);
	graphics->DrawEllipse(redPen, center->X - width, center->Y - height, width * 2, height * 2);

	bitmap->SetPixel(center->X, center->Y, Color::Black);

	delete pictureBox->Image;
	pictureBox->Image = bitmap;

	//Draw cirle using the Graphics method with green pen
	BresenhamEllipse(center->X, center->Y, width, height);
	Draw();

	delete bitmap;
	delete graphics;
	delete redPen;
}


void BresenhamDrawing::Draw()
{
	temp_bitmap = gcnew Bitmap(pictureBox->Image);

	for (size_t i = 0; i < points->Count; i++)
	{
		if (points[i]->Item1 < temp_bitmap->Width && points[i]->Item1 > 0 &&
			points[i]->Item2 < temp_bitmap->Height && points[i]->Item2 > 0)
		{
			temp_bitmap->SetPixel(points[i]->Item1, points[i]->Item2, Color::Blue);
		}		
	}

	delete pictureBox->Image;
	pictureBox->Image = temp_bitmap;

	points->Clear();

	
}

