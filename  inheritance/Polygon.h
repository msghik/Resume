#pragma once
#include"Point.h"
#include"Shape.h"
#include<math.h>
#include<iostream>
using namespace std;

class Polygon : public Shape
{

protected:
	Point* _P;
private:
	int _Side;
	void initialize() {
		_P = '\0';
		_Side = 0;
	}
public:
	Polygon();
	Polygon(Point*,int);
	Polygon(int Side);
	~Polygon();
	int getSide();
	void setSide(int a) {
		this->_Side = a ;
	}
	virtual void getPoints();
	virtual double getArea();
	virtual double getPerimeter();
	virtual double totalAngels();
	virtual void PictureX();
	virtual void PictureY();
	virtual void PictureM();
	virtual void PictureK(int);
	virtual void Transfer(Point);
	virtual void Ghotbi();
	virtual void Mohadab();


};



