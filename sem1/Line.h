#pragma once

#include "GeometricObject.h"

#include <limits.h>

ref class Line :
	public GeometricObject
{

private:
	Point^ point0;
	Point^ point1;

public:
	System::Collections::Generic::List<Point>^ points;

	void SetPoint0(Point^ point0);
	void SetPoint0(int x, int y);
	Point^ GetPoint0();

	void SetPoint1(Point^ point1);
	void SetPoint1(int x, int y);
	Point^ GetPoint1();

	Line(Color c, System::Collections::Generic::List<System::Tuple<int, int>^>^ points);
	Line(Color c, int x0, int y0, int x1, int y1);
	~Line();

	void getSubList(int x0, int x1);
};

