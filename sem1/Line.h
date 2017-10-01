#pragma once
#include "GeometricObject.h"

ref class Line :
	public GeometricObject
{

private:
	Point^ point0;
	Point^ point1;

public:

	void SetPoint0(Point^ point0);
	Point^ GetPoint0();

	void SetPoint1(Point^ point1);
	Point^ GetPoint1();

	Line(Color c);
	~Line();

};

