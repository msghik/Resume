#pragma once
#include"Parallelogram.h"
#include"Point.h"
class Rectangle:virtual public Parallelogram
{
public:
	Rectangle();
	Rectangle(Point,int,int);
	~Rectangle();
	virtual double totalAngels();
};

