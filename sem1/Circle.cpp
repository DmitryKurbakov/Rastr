#include "Circle.h"

void Circle ::SetPoint0(Point ^ point0)
{
	this->point0 = point0;
}

Point ^ Circle::GetPoint0()
{
	return this->point0;
}

void Circle::SetRadius(int radius)
{
	this->radius = radius;
}

int Circle::GetRadius()
{
	return this->radius;
}

Circle::Circle(Color c)
{
	color = c;
}


Circle::~Circle()
{
}
