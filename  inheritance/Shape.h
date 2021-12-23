#pragma once
#include"Point.h"
class Shape
{
public:
	Shape();
	~Shape();
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	virtual double totalAngels() = 0;
	virtual void PictureX() = 0;
	virtual void PictureY() = 0;
	virtual void PictureK(int)=0;
	virtual void Transfer(Point)=0;
	virtual void PictureM() = 0;
	virtual void getPoints() = 0;
	virtual void Ghotbi() = 0;
	virtual void Mohadab() = 0;

};

