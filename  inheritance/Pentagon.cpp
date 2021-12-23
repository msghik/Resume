#include "Pentagon.h"



Pentagon::Pentagon():Polygon(5)
{
	_P = new Point[5];
}

Pentagon::Pentagon(Point p1, Point p2, Point p3, Point p4, Point p5):Polygon(5)
{
	_P[0] = p1;
	_P[1] = p2;
	_P[2] = p3;
	_P[3] = p4;
	_P[4] = p5;
}


Pentagon::~Pentagon()
{
}
