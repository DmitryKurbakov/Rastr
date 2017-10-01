#pragma once
#include "GeometricObject.h"
ref class Circle :
	public GeometricObject
{

private:
	Point^ point0;
	int radius;

public:

	void SetPoint0(Point^ point0);
	Point^ GetPoint0();

	void SetRadius(int radius);
	int GetRadius();

	Circle(Color c);
	~Circle();
};

