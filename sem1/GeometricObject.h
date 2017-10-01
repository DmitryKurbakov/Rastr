#pragma once

using namespace System::Drawing;

ref class GeometricObject
{

protected:
	Color color;


public:
	GeometricObject(Color c);
	GeometricObject();
	~GeometricObject();
};

