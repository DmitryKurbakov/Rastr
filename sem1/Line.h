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
	void SetPoint0(int x, int y);
	Point^ GetPoint0();

	void SetPoint1(Point^ point1);
	void SetPoint1(int x, int y);
	Point^ GetPoint1();

	Line(Color c);
	Line(Color c, int x0, int y0, int x1, int y1);
	~Line();

};

