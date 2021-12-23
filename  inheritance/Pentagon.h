#pragma once
#include"Point.h"
#include"Polygon.h"
class Pentagon:public Polygon
{
public:
	Pentagon();
	Pentagon(Point, Point, Point, Point, Point);
	~Pentagon();
};


