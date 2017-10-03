#include "GeometricObject.h"


GeometricObject::GeometricObject(Color c)
{
	this->color = c;
}

GeometricObject::GeometricObject()
{
}


GeometricObject::~GeometricObject()
{
}

void GeometricObject::SetPoints(System::Collections::Generic::List<System::Tuple<int, int>^>^ tuples)
{
	points = gcnew System::Collections::Generic::List<Point>();
	
	for each (System::Tuple<int, int>^ tuple in tuples)
	{
		Point p;
		p.X = tuple->Item1;
		p.Y = tuple->Item2;
		points->Add(p);
	}
}
