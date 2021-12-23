#include "Point.h"



Point::Point()
{
	initialize();
}

Point::Point(double x, double y)
{
	initialize();
	_x = x;
	_y = y;
}


Point::~Point()
{
	initialize();
}

void Point::SetPoint(double x, double y)
{
	initialize();
	_x = x;
	_y = y;
}

double Point::getX()
{
	return _x;
}

double Point::getY()
{
	return _y;
}

ostream& operator<<(ostream& out, Point& p) {
	out << "(";
	out << p.getX() << "," << p.getY();
	out << ")";
	return out;
}

istream& operator>>(istream& in, Point& p) {
	double x, y;
	cout << "Please Enter X :";
	in >> x;
	cout << "And Y : ";
	in >> y;
	p.SetPoint(x, y);
	return in;
}
