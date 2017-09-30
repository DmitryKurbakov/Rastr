#include "BresenhamDrawing.h"

BresenhamDrawing::BresenhamDrawing(System::Windows::Forms::PictureBox^ pictureBox)
{
	this->pictureBox = pictureBox;
	this->fillingStack = gcnew System::Collections::Stack();
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

	////Draw line using the Graphics method with red pen
	//Bitmap^ bitmap = gcnew Bitmap(pictureBox->Image);
	//Graphics^ graphics = Graphics::FromImage(bitmap);

	//Pen^ redPen = gcnew Pen(Color::Red);
	//graphics->DrawLine(redPen, point0->X, point0->Y, point1->X, point1->Y);

	//delete pictureBox->Image;
	//pictureBox->Image = bitmap;

	//Draw line using the Bresenham method with black pen
	BresenhamLine(point0->X, point0->Y, point1->X, point1->Y);
	Draw();

	/*delete bitmap;
	delete graphics;
	delete redPen;*/
}

void BresenhamDrawing::DrawCircle(int x0, int y0, int radius)
{
	BresenhamCircle(x0, y0, radius);
	Draw();
}

void BresenhamDrawing::DrawCircle(Point^ center, int radius)
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
	Draw();

	/*delete bitmap;
	delete graphics;
	delete redPen;*/
}

void BresenhamDrawing::DrawEllipse(int x0, int y0, int width, int height)
{
	BresenhamEllipse(x0, y0, width, height);
	Draw();
}

void BresenhamDrawing::DrawEllipse(Point^ center, int width, int height)
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
	Draw();

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
		while (tmpX <= xright && tmpY >= 0)
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

	bmp->SetPixel(x, y, c);

	Point^ p = gcnew Point(x, y);

	stack->Push(p);

	while (stack->Count > 0)
	{
		p = (Point^)stack->Pop();

		if (!IsBorder(bmp, p->X, p->Y))
		{
			col = bmp->GetPixel(p->X, p->Y);

			if (col.ToArgb() != c.ToArgb() && col.ToArgb() != Color::Blue.ToArgb())
			{
				bmp->SetPixel(p->X, p->Y, c);
			}
		}
		
		if (!IsBorder(bmp, p->X, p->Y + 1))
		{
			col = bmp->GetPixel(p->X, p->Y + 1);

			if (col.ToArgb() != c.ToArgb() && col.ToArgb() != Color::Blue.ToArgb())
			{
				Point^ tempPoint = gcnew Point(p->X, p->Y + 1);
				stack->Push(tempPoint);
				delete tempPoint;
			}
		}
		
		if (!IsBorder(bmp, p->X + 1, p->Y))
		{
			col = bmp->GetPixel(p->X + 1, p->Y);

			if (col.ToArgb() != c.ToArgb() && col.ToArgb() != Color::Blue.ToArgb())
			{
				Point^ tempPoint = gcnew Point(p->X + 1, p->Y);
				stack->Push(tempPoint);
				delete tempPoint;
			}
		}
		
		if (!IsBorder(bmp, p->X, p->Y - 1))
		{
			col = bmp->GetPixel(p->X, p->Y - 1);

			if (col.ToArgb() != c.ToArgb() && col.ToArgb() != Color::Blue.ToArgb())
			{
				Point^ tempPoint = gcnew Point(p->X, p->Y - 1);
				stack->Push(tempPoint);
				delete tempPoint;
			}
		}		

		if (!IsBorder(bmp, p->X, p->Y))
		{
			col = bmp->GetPixel(p->X - 1, p->Y);

			if (col.ToArgb() != c.ToArgb() && col.ToArgb() != Color::Blue.ToArgb())
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

bool BresenhamDrawing::IsBorder(Bitmap^ bmp, int x, int y)
{
	return 
		x <= 0
		|| x >= bmp->Width
		|| y <= 0 
		|| y >= bmp->Height;
}



	


