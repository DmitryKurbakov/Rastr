#include "BresenhamDrawing.h"


BresenhamDrawing::BresenhamDrawing(System::Windows::Forms::PictureBox^ pictureBox)
{
	this->pictureBox = pictureBox;
	geometricObjectList = gcnew System::Collections::Generic::List<GeometricObject^>();
}


BresenhamDrawing::~BresenhamDrawing()
{
	delete temp_bitmap;
}


System::Windows::Forms::PictureBox ^ BresenhamDrawing::getPictureBox()
{
	return this->pictureBox;
}


Bitmap^ BresenhamDrawing::DrawLine(Bitmap^ bmp, Point^ point0, Point^ point1, Color c, bool addToList)
{

	////Draw line using the Graphics method with red pen
	//Bitmap^ bitmap = gcnew Bitmap(pictureBox->Image);
	//Graphics^ graphics = Graphics::FromImage(bitmap);

	//Pen^ redPen = gcnew Pen(Color::Red);
	//graphics->DrawLine(redPen, point0->X, point0->Y, point1->X, point1->Y);

	//delete pictureBox->Image;
	//pictureBox->Image = bitmap;

	//Draw line using the Bresenham method with black pen
	BresenhamLine(point0->X, point0->Y, point1->X, point1->Y);

	if (addToList)
	{
		Line^ line = gcnew Line(c, points);
		line->SetPoint0(point0->X, point0->Y);
		line->SetPoint1(point1->X, point1->Y);
		geometricObjectList->Add(line);
	}	

	return Draw(bmp, c);

	/*delete bitmap;
	delete graphics;
	delete redPen;*/
}


Bitmap^ BresenhamDrawing::DrawCircle(Bitmap^ bmp, Point^ center, int radius, Color c, bool addToList)
{
	//Draw cirle using the Graphics method with red pen
	/*Bitmap^ bitmap = gcnew Bitmap(pictureBox->Image);
	Graphics^ graphics = Graphics::FromImage(bitmap);

	Pen^ redPen = gcnew Pen(Color::Red);
	graphics->DrawEllipse(redPen, center->X - radius, center->Y - radius, radius * 2, radius * 2);

	delete pictureBox->Image;

	pictureBox->Image = bitmap;*/

	//Draw cirle using the Bresenham method with black pen
	BresenhamCircle(center->X, center->Y, radius);

	if (addToList)
	{

		Circle^ circle = gcnew Circle(c);
		circle->SetPoint0(center);
		circle->SetRadius(radius);
		geometricObjectList->Add(circle);

	}
	
	return Draw(bmp, c);

	/*delete bitmap;
	delete graphics;
	delete redPen;*/
}

Bitmap^ BresenhamDrawing::DrawEllipse(Bitmap^ bmp, Point^ center, int width, int height, Color c, bool addToList)
{

	//Draw cirle using the Graphics method with red pen
	/*Bitmap^ bitmap = gcnew Bitmap(pictureBox->Image);
	Graphics^ graphics = Graphics::FromImage(bitmap);

	Pen^ redPen = gcnew Pen(Color::Red);
	graphics->DrawEllipse(redPen, center->X - width, center->Y - height, width * 2, height * 2);

	delete pictureBox->Image;
	pictureBox->Image = bitmap;*/

	//Draw cirle using the Graphics method with green pen
	BresenhamEllipse(center->X, center->Y, width, height);
	
	if (addToList)
	{
		Ellipse^ ellipse = gcnew Ellipse(c);
	ellipse->SetPoint0(center);
	ellipse->SetWidth(width);
	ellipse->SetHeight(height);
	geometricObjectList->Add(ellipse);
	}
	
	return Draw(bmp, c);

	/*delete bitmap;
	delete graphics;
	delete redPen;*/
}

Bitmap^ BresenhamDrawing::LineFillWithSeed(Bitmap^ bm, int x, int y, Color c)
{
	Stack^ pts = gcnew Stack();
	//std::stack<Point> pts;
	Point^ prime = gcnew Point();
	prime->X = x; 
	prime->Y = y;

	pts->Push(prime);
	int argb = bm->GetPixel(x, y).ToArgb();

	while (pts->Count > 0)
	{
		Point^ p = (Point^)pts->Pop();
		bm->SetPixel(p->X, p->Y, c);

		int tmpX = p->X + 1;

		int width = bm->Width;
		int height = bm->Height;

		while (bm->GetPixel(tmpX, p->Y).ToArgb() == argb && tmpX != width - 1)
		{
			bm->SetPixel(tmpX, p->Y, c);
			tmpX += 1;
		}
		int xright = tmpX - 1;

		tmpX = p->X - 1;

		while (bm->GetPixel(tmpX, p->Y).ToArgb() == argb && tmpX != 0)
		{
			bm->SetPixel(tmpX, p->Y, c);
			tmpX -= 1;
		}

		int xleft = tmpX + 1;

		tmpX = xleft;
		int tmpY = p->Y + 1;
		while (tmpX <= xright && tmpY < height)
		{
			bool flag = false;
			while (bm->GetPixel(tmpX, tmpY).ToArgb() == argb && bm->GetPixel(tmpX, tmpY).ToArgb() != c.ToArgb() && tmpX < xright)
			{
				if (!flag) { flag = true; }
				tmpX += 1;
			}

			if (flag)
			{

				if (tmpX == xright && bm->GetPixel(tmpX, tmpY).ToArgb() == argb && bm->GetPixel(tmpX, tmpY).ToArgb() != c.ToArgb())
				{
					Point^ push = gcnew Point(); 
					push->X = tmpX; 
					push->Y = tmpY;
					pts->Push(push);
				}

				else
				{
					Point^ push = gcnew Point(); 
					push->X = tmpX - 1; 
					push->Y = tmpY;
					pts->Push(push);
				}

				flag = false;

			}

			int xin = tmpX;
			while ((bm->GetPixel(tmpX, tmpY).ToArgb() != argb || bm->GetPixel(tmpX, tmpY).ToArgb() == c.ToArgb()) && tmpX < xright)
			{
				tmpX += 1;
			}

			if (tmpX == xin) { tmpX += 1; }
		}

		tmpX = xleft;
		tmpY = p->Y - 1;
		while (tmpX <= xright && tmpY > 0)
		{
			bool flag = false;
			while (bm->GetPixel(tmpX, tmpY).ToArgb() == argb && bm->GetPixel(tmpX, tmpY).ToArgb() != c.ToArgb() && tmpX < xright)
			{
				if (!flag) { flag = true; }
				tmpX += 1;
			}

			if (flag)
			{
				if (tmpX == xright && bm->GetPixel(tmpX, tmpY).ToArgb() == argb && bm->GetPixel(tmpX, tmpY).ToArgb() != c.ToArgb())
				{
					Point^ push = gcnew Point(); 
					push->X = tmpX; 
					push->Y = tmpY;
					pts->Push(push);
				}
				else
				{
					Point^ push = gcnew Point(); 
					push->X = tmpX - 1; 
					push->Y = tmpY;
					pts->Push(push);
				}
				flag = false;
			}

			int xin = tmpX;
			while ((bm->GetPixel(tmpX, tmpY).ToArgb() != argb || bm->GetPixel(tmpX, tmpY).ToArgb() == c.ToArgb()) && tmpX < xright)
			{
				tmpX += 1;
			}

			if (tmpX == xin) { tmpX += 1; }
		}
	}

	return bm;
}

Bitmap ^ BresenhamDrawing::PolygonFill(Bitmap ^ bmp, int x, int y, Color c)
{
	Stack^ stack = gcnew Stack();
	Color col;

	Color argb = bmp->GetPixel(x, y);

	bmp->SetPixel(x, y, c);

	Point^ p = gcnew Point(x, y);

	stack->Push(p);

	while (stack->Count > 0)
	{
		p = (Point^)stack->Pop();

		if (!IsBorder(bmp, p->X, p->Y))
		{
			col = bmp->GetPixel(p->X, p->Y);

			if (col.ToArgb() != c.ToArgb() && col.ToArgb() == argb.ToArgb())
			{
				bmp->SetPixel(p->X, p->Y, c);
			}
		}
		
		if (!IsBorder(bmp, p->X, p->Y + 1))
		{
			col = bmp->GetPixel(p->X, p->Y + 1);

			if (col.ToArgb() != c.ToArgb() && col.ToArgb() == argb.ToArgb())
			{
				Point^ tempPoint = gcnew Point(p->X, p->Y + 1);
				stack->Push(tempPoint);
				delete tempPoint;
			}
		}
		
		if (!IsBorder(bmp, p->X + 1, p->Y))
		{
			col = bmp->GetPixel(p->X + 1, p->Y);

			if (col.ToArgb() != c.ToArgb() && col.ToArgb() == argb.ToArgb())
			{
				Point^ tempPoint = gcnew Point(p->X + 1, p->Y);
				stack->Push(tempPoint);
				delete tempPoint;
			}
		}
		
		if (!IsBorder(bmp, p->X, p->Y - 1))
		{
			col = bmp->GetPixel(p->X, p->Y - 1);

			if (col.ToArgb() != c.ToArgb() && col.ToArgb() == argb.ToArgb())
			{
				Point^ tempPoint = gcnew Point(p->X, p->Y - 1);
				stack->Push(tempPoint);
				delete tempPoint;
			}
		}		

		if (!IsBorder(bmp, p->X, p->Y))
		{
			col = bmp->GetPixel(p->X - 1, p->Y);

			if (col.ToArgb() != c.ToArgb() && col.ToArgb() == argb.ToArgb())
			{
				Point^ tempPoint = gcnew Point(p->X - 1, p->Y);
				stack->Push(tempPoint);
				delete tempPoint;
			}
		}
	}

	delete p;
	return bmp;
}

System::Collections::Generic::List<Line^>^ BresenhamDrawing::Clip(int xL, int yT, int xR, int yB)
{
	System::Collections::Generic::List<Line^>^ lines = gcnew System::Collections::Generic::List<Line^>();

	for each (GeometricObject^ it in geometricObjectList)
	{
		if (it->GetType()->ToString()->CompareTo("Line") == 0)
		{
			Line^ line = gcnew Line(it->color, 
				((Line^)it)->GetPoint0()->X, ((Line^)it)->GetPoint0()->Y,
				((Line^)it)->GetPoint1()->X, ((Line^)it)->GetPoint1()->Y);

			lines->Add(line);
		}
	}

	int inside = 0;
	int left = 1;
	int right = 2;
	int bottom = 4;
	int top = 8;

	for each (Line^ line in lines->ToArray())
	{
		
		int x0 = line->GetPoint0()->X;
		int y0 = line->GetPoint0()->Y;
		int x1 = line->GetPoint1()->X;
		int y1 = line->GetPoint1()->Y;
		
		int outcode0 = ComputeOutCode(xL, yT, xR, yB, x0, y0);
		int outcode1 = ComputeOutCode(xL, yT, xR, yB, x1, y1);
		bool accept = false;


		while (true)
		{
			if ((outcode0 | outcode1) == 0)
			{
				accept = true;
				break;
			}
			else if ((outcode0 & outcode1) != 0)
			{
				lines->Remove(line);
				break;
			}

			else
			{
				float x, y;

				int outCodeOut = (outcode0 != 0) ? outcode0 : outcode1;


				if ((outCodeOut & top) != 0)
				{
					x = x0 + (x1 - x0) * (yT - y0) / (y1 - y0);
					y = yT;
				}
				else if ((outCodeOut & bottom) != 0)
				{
					x = x0 + (x1 - x0) * (yB - y0) / (y1 - y0);
					y = yB;
				}
				else if ((outCodeOut & right) != 0)
				{
					y = y0 + (y1 - y0) * (xR - x0) / (x1 - x0);
					x = xR;
				}
				else if ((outCodeOut & left) != 0)
				{
					y = y0 + (y1 - y0) * (xL - x0) / (x1 - x0);
					x = xL;
				}
				else
				{
					x = NULL;
					y = NULL;
				}


				if (outCodeOut == outcode0)
				{
					line->SetPoint0(x, y);

					x0 = x;
					y0 = y;

					outcode0 = ComputeOutCode(xL, yT, xR, yB, x0, y0);
				}
				else
				{
					line->SetPoint1(x, y);

					x1 = x;
					y1 = y;

					outcode1 = ComputeOutCode(xL, yT, xR, yB, x1, y1);
				}
			}
		}
	}

	return lines;
}


int BresenhamDrawing::ComputeOutCode(int xL, int yT, int xR, int yB, int x, int y)
{
	Byte code = 0;

	if (x < xL)
		code |= 1;
	else if (x > xR)
		code |= 2;
	if (y > yB)
		code |= 4;
	else if (y < yT)
		code |= 8;

	return code;
}



Bitmap^ BresenhamDrawing::Draw(Bitmap^ bmp, Color c)
{
	//temp_bitmap = gcnew Bitmap(pictureBox->Image);

	for (size_t i = 0; i < points->Count; i++)
	{
		if (points[i]->Item1 < bmp->Width && points[i]->Item1 > 0 &&
			points[i]->Item2 < bmp->Height && points[i]->Item2 > 0)
		{
			bmp->SetPixel(points[i]->Item1, points[i]->Item2, c);
		}		
	}

	//delete pictureBox->Image;
	//pictureBox->Image = temp_bitmap;

	points->Clear();

	return bmp;
}

bool BresenhamDrawing::IsBorder(Bitmap^ bmp, int x, int y)
{
	return 
		x <= 0
		|| x >= bmp->Width
		|| y <= 0 
		|| y >= bmp->Height;
}



	


