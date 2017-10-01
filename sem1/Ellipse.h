#pragma once
#include "GeometricObject.h"
ref class Ellipse :
	public GeometricObject
{

private:
	Point^ point0;
	int width;
	int height;

public:

	void SetPoint0(Point^ point0);
	Point^ GetPoint0();

	void SetWidth(int width);
	int GetWidth();

	void SetHeight(int height);
	int GetHeight();

	Ellipse(Color c);
	~Ellipse();
};

