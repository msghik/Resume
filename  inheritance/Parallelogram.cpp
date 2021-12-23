#include "Parallelogram.h"



Parallelogram::Parallelogram() 
{
	initialize();
}

Parallelogram::Parallelogram(Point P, int a, int b,double teta){
	initialize();
	this->a = a;
	this->b = b;
	this->teta = teta;
	if (teta != 2*atan(1)) {
		Point p1((P.getX() + a), P.getY());
		Point p2((P.getX() - cos(teta) * b + a), P.getY() - sin(teta) * b);
		Point p3((P.getX() - cos(teta) * b), P.getY() - sin(teta) * b);
		_P[0] = P;
		_P[1] = p1;
		_P[2] = p2;
		_P[3] = p3;
	}
	else {
		Point p1((P.getX() + a), P.getY());
		Point p2(P.getX(), P.getY() - b);
		Point p3((P.getX() + a), P.getY() - b);
		_P[0] = P;
		_P[1] = p1;
		_P[2] = p2;
		_P[3] = p3;
	}
	setSide(4);
}


Parallelogram::~Parallelogram()
{
}

void Parallelogram::setParallelogram(Point P, int a, int b, double teta)
{
	initialize();
	this->a = a;
	this->b = b;
	this->teta = teta;
	if (teta != 2 * atan(1)) {
		Point p1((P.getX() + a), P.getY());
		Point p2((P.getX() - cos(teta) * b + a), P.getY() - sin(teta) * b);
		Point p3((P.getX() - cos(teta) * b), P.getY() - sin(teta) * b);
		_P[0] = P;
		_P[1] = p1;
		_P[2] = p2;
		_P[3] = p3;
	}
	else {
		Point p1((P.getX() + a), P.getY());
		Point p2(P.getX(), P.getY() - b);
		Point p3((P.getX() + a), P.getY() - b);
		_P[0] = P;
		_P[1] = p1;
		_P[2] = p2;
		_P[3] = p3;
	}
	setSide(4);
}


double Parallelogram::getArea()
{
	return a*b*sin(teta);
}

double Parallelogram::getPerimeter()
{
	return 2*(a+b);
}

double Parallelogram::totalAngels()
{
	return 360.0;
}



