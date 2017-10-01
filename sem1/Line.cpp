#include "Line.h"

void Line::SetPoint0(Point ^ point0)
{
	this->point0 = point0;
}

Point ^ Line::GetPoint0()
{
	return this->point0;
}

void Line::SetPoint1(Point ^ point1)
{
	this->point1 = point1;
}

Point ^ Line::GetPoint1()
{
	return this->point1;
}


Line::Line(Color c)
{
	color = c;
}


Line::~Line()
{
}


