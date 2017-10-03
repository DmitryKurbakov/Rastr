#include "Circle.h"

void Circle ::SetPoint0(int x, int y)
{
	this->point0 = gcnew Point(x, y);
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
