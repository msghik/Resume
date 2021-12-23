#pragma once
#include"Point.h"
#include"Polygon.h"
class Triangle:public Polygon
{
public:
	Triangle();
	Triangle(Point, Point, Point);
	~Triangle();
};

