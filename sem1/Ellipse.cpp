#include "Ellipse.h"



void Ellipse::SetPoint0(Point ^ point0)
{
	this->point0 = point0;
}

Point ^ Ellipse::GetPoint0()
{
	return this->point0;
}

void Ellipse::SetWidth(int width)
{
	this->width = width;
}

int Ellipse::GetWidth()
{
	return this->width;
}

void Ellipse::SetHeight(int height)
{
	this->height = height;
}

int Ellipse::GetHeight()
{
	return this->height;
}

Ellipse::Ellipse(Color c)
{
	color = c;
}


Ellipse::~Ellipse()
{
}
