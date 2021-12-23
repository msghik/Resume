#include "Rectangle.h"



Rectangle::Rectangle()
{
}

Rectangle::Rectangle(Point p1, int a, int b) : Parallelogram(p1, a, b, 2 * atan(1))
{
	setParallelogram(p1, a, b, 2 * atan(1));
}

Rectangle::~Rectangle()
{
}

double Rectangle::totalAngels()
{
	return 360.0;
}


