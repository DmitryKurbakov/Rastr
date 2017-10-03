#pragma once

using namespace System::Drawing;

ref class GeometricObject
{

public:
	Color color;

	System::Collections::Generic::List<Point>^ points;

public:
	GeometricObject(Color c);
	GeometricObject();
	~GeometricObject();

	void SetPoints(System::Collections::Generic::List<System::Tuple<int, int>^>^ tuples);
};

