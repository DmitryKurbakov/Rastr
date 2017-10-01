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


