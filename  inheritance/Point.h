#pragma once
#include<iostream>
using namespace std;
class Point
{
	friend ostream& operator<<(ostream&, Point&);
	friend istream& operator >>(istream&, Point&);
private:
	double _x;
	double _y;
	void initialize() {
		_x = 0;
		_y = 0;
	}
public:
	Point();
	Point(double x, double y);
	~Point();
	void SetPoint(double x, double y);
	double getX();
	double getY();
};



