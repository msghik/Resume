#include "Triangle.h"



Triangle::Triangle() :Polygon(3)
{
	_P = new Point[3];
}

Triangle::Triangle(Point p1, Point p2 , Point p3 ):Polygon(3)
{
	_P[0] = p1;
	_P[1] = p2;
	_P[2] = p3;
}


Triangle::~Triangle()
{
}

