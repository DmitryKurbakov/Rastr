#include "Line.h"

void Line::SetPoint0(Point ^ point0)
{
	this->point0 = point0;
}

void Line::SetPoint0(int x, int y)
{
	delete point0;
	point0 = gcnew Point(x, y);
}

Point ^ Line::GetPoint0()
{
	return this->point0;
}

void Line::SetPoint1(Point ^ point1)
{
	this->point1 = point1;
}

void Line::SetPoint1(int x, int y)
{
	delete point1;
	point1 = gcnew Point(x, y);
}

Point ^ Line::GetPoint1()
{
	return this->point1;
}


Line::Line(Color c)
{
	color = c;

	/*this->points = gcnew System::Collections::Generic::List<Point>();

	for each (System::Tuple<int, int>^ tuple  in points)
	{
		Point tempPoint;
		tempPoint.X = tuple->Item1;
		tempPoint.Y = tuple->Item2;

		this->points->Add(tempPoint);
	}*/
}

Line::Line(Color c, int x0, int y0, int x1, int y1)
{
	color = c;
	point0 = gcnew Point(x0, y0);
	point1 = gcnew Point(x1, y1);
}


Line::~Line()
{
}

void Line::getSubList(int x0, int x1)
{
	int xBeg = INT_MAX;
	int xEnd = INT_MAX;

	int indexMin;
	int indexMax;

	for (int i = 0; i < this->points->Count; i++)
	{
		int difXMin = System::Math::Abs(this->points[i].X - x0);
		int difXMax = System::Math::Abs(this->points[i].X - x1);

		if (difXMin < xBeg)
		{
			xBeg = difXMin;
			indexMin = i;
		}

		if (difXMax < xEnd)
		{
			xEnd = difXMax;
			indexMax = i;
		}
	}

	points->RemoveRange(0, indexMin + 1);
	indexMax = System::Math::Abs(indexMax - indexMin - 1);
	points->RemoveRange(indexMax, points->Count - indexMax + 1);

	SetPoint0(points[0]);
	SetPoint1(points[points->Count - 1]);
}


