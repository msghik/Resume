#pragma once
#include"Point.h"
#include"Polygon.h"
class FourSquare:public Polygon
{

public:
	FourSquare();
	FourSquare(Point,Point,Point,Point);
	~FourSquare();
};

