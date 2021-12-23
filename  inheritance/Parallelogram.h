#pragma once
#include"FourSquare.h"
#include"Point.h"
#include"math.h"
class Parallelogram:public FourSquare
{
private:
	double a = 0, b = 0;
	double teta;
	void initialize() {
		a = 0;
		b = 0;
		teta = 0;
	}
public:
	Parallelogram();
	Parallelogram(Point,int,int,double);
	~Parallelogram();
	void setParallelogram(Point, int, int, double);
	virtual double getArea();
	virtual double getPerimeter();
	virtual double totalAngels();
};


