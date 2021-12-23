#include "FourSquare.h"

FourSquare::FourSquare():Polygon(4)
{
}

FourSquare::FourSquare(Point p1,Point p2,Point p3, Point p4) : Polygon(4) {
	_P[0] = p1;
	_P[1] = p2;
	_P[2] = p3;
	_P[3]= p4;
}



FourSquare::~FourSquare()
{
}
