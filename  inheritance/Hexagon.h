#pragma once
#include"Polygon.h"
#include"Point.h"

class Hexagon:public Polygon
{
public:
	Hexagon();
	Hexagon(Point p1, Point p2, Point p3, Point p4, Point p5 ,Point p6);
	~Hexagon();
};

