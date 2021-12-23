#pragma once
#include"Rectangle.h"
#include"Diamond.h"
#include"Point.h"

class Square : public Rectangle,public Diamond
{
public:
	Square();
	Square(Point, int);
	~Square();
	virtual double totalAngels();
};

