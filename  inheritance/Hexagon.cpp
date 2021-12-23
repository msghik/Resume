#include "Hexagon.h"



Hexagon::Hexagon() :Polygon(6)
{
	_P = new Point[6];
}

Hexagon::Hexagon(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6) : Polygon(6) {
	_P[0] = p1;
	_P[1] = p2;
	_P[2] = p3;
	_P[3] = p4;
	_P[4] = p5;
	_P[5] = p6;
}

Hexagon::~Hexagon()
{
}
