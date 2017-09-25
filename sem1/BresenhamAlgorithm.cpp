#include "BresenhamAlgorithm.h"

BresenhamAlgorithm::BresenhamAlgorithm()
{
	points = gcnew System::Collections::Generic::List<Tuple<int, int>^>();
}


BresenhamAlgorithm::~BresenhamAlgorithm()
{
}

//Realisation of sign function
template <typename T> int sgn(T val)
{
	return (T(0) < val) - (val < T(0));
}

void BresenhamAlgorithm::BresenhamLine(int x0, int y0, int x1, int y1)
{
	bool flag = true;

	int i = 0, 
		s0 = sgn(x1 - x0), 
		s1 = sgn(y1 - y0);

	int
		x = x0, y = y0,
		delta_x = abs(x1 - x0), delta_y = abs(y1 - y0),
		e_mod = 0;

	if (delta_y > delta_x)
	{
		swap(delta_x, delta_y);
	}
	else
	{
		flag = false;
	}

	e_mod = 2 * delta_y - delta_x;

	for (int i = 0; i <= delta_x; i++)
	{
		Tuple<int, int>^ temp_tuple = gcnew Tuple<int, int>(x, y);
		points->Add(temp_tuple);

		delete temp_tuple;

		while (e_mod >= 0)
		{
			if (flag)
			{
				x += s0;
			}
			else
			{
				y += s1;
			}

			e_mod -= 2 * delta_x;
		}

		if (flag)
		{
			y += s1;
		}
		else
		{
			x += s0;
		}

		e_mod += 2 * delta_y;
	}
}



void BresenhamAlgorithm::BresenhamCircle(int x0, int y0, int radius)
{

	int x = 0, y = radius, gap = 0, delta = 2 - 2 * radius;
	while (y >= 0)
	{
		PushPoint(x0 + x, y0 + y);
		PushPoint(x0 + x, y0 - y);
		PushPoint(x0 - x, y0 - y);
		PushPoint(x0 - x, y0 + y);

		gap = 2 * (delta + y) - 1;

		if (delta < 0 && gap <= 0)
		{
			x++;
			delta += 2 * x + 1;
			continue;
		}
		
		gap = 2 * delta - 2 * x - 1;

		if (delta > 0 && gap > 0)
		{
			y--;
			delta -= 2 * y + 1;
			continue;
		}
		x++;
		y--;
		delta += 2 * (x - y) + 2;
		
	}
}

void BresenhamAlgorithm::BresenhamEllipse(int x0, int y0, int x_radius, int y_radius)
{
	int
		x, y,
		x_change, y_change,
		error,
		a_square, b_square,
		stop_x, stop_y;

	a_square = 2 * x_radius * x_radius;
	b_square = 2 * y_radius * y_radius;

	x = x_radius;
	y = 0;

	x_change = y_radius * y_radius * (1 - 2 * x_radius);
	y_change = x_radius * x_radius;

	error = 0;

	stop_x = b_square * x_radius;
	stop_y = 0;

	while (stop_x >= stop_y)
	{
		PutPointsToEllipseSet(x, y, x0, y0);

		y++;
		stop_y += a_square;
		error += y_change;
		y_change += a_square;

		if ((2 * error + x_change) > 0)
		{
			x--;
			stop_x -= b_square;
			error += x_change;
			x_change += b_square;
		}
	}

	x = 0;
	y = y_radius;

	x_change = y_radius * y_radius;
	y_change = x_radius * x_radius * (1 - 2 * y_radius);

	error = 0;

	stop_x = 0;
	stop_y = a_square * y_radius;

	while (stop_x <= stop_y)
	{
		PutPointsToEllipseSet(x, y, x0, y0);

		x++;
		stop_x += b_square;
		error += x_change;
		x_change += b_square;

		if ((2 * error + y_change) > 0)
		{
			y--;
			stop_y -= a_square;
			error += y_change;
			y_change += a_square;
		}
	}
}


void BresenhamAlgorithm::PutPointsToEllipseSet(int x, int y, int x0, int y0)
{
	PushPoint(x0 + x, y0 + y);
	PushPoint(x0 - x, y0 + y);
	PushPoint(x0 - x, y0 - y);
	PushPoint(x0 + x, y0 - y);
}

void BresenhamAlgorithm::PushPoint(int x, int y)
{
	Tuple<int, int>^ temp_tuple = gcnew Tuple<int, int>(x, y);
	points->Add(temp_tuple);

	delete temp_tuple;
}