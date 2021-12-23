#include "Polygon.h"



Polygon::Polygon()
{
	initialize();
}
Polygon::Polygon(Point*p, int n) {
	initialize();
	_Side = n;
	_P = new Point[n];
	for (int i = 0; i < n; i++) {
		_P[i] = p[i];
	}
}

Polygon::Polygon(int Side)
{
	initialize();
	_Side = Side;
	_P = new Point[Side];
}





Polygon::~Polygon()
{
	initialize();
}

int Polygon::getSide()
{
	return _Side;
}

void Polygon::getPoints()
{
	Point p;
	for (int i = 0; i < _Side; i++) {
		cin >> p;
		_P[i] = p;
	}
}

double Polygon::getArea()
{
	//Finding Seql :
	double x = 0, y = 0;
	for (int i = 0; i < _Side; i++) {
		x += _P[i].getX();
		y += _P[i].getY();
	}
	Point Seql(x / _Side, y / _Side);

	//After putting them in the right order.
	for (int i = 0; i < _Side-1; i++) {
		for (int j = 0; j < _Side-1; j++) {
			if (atan2(_P[j].getY()-Seql.getY() , _P[j].getX()-Seql.getX()) > atan2(_P[j + 1].getY() - Seql.getY() , _P[j + 1].getX() - Seql.getX())) {
				Point t;
				t =  _P[j + 1];
				_P[j + 1] = _P[j];
				_P[j] = t;
			}
		}
	}

	double Area = 0;
	for (int i = 0; i < _Side; i++) {

		if (i != _Side - 1) {
			Area += 0.5*abs((_P[i + 1].getX() * Seql.getY() - Seql.getX() * _P[i + 1].getY()) - (_P[i].getX() * Seql.getY() - Seql.getX() * _P[i].getY()) + (_P[i].getX() * _P[i + 1].getY() - _P[i + 1].getX() * _P[i].getY()));
		}
		if (i == _Side - 1) {
			Area += 0.5*abs((_P[0].getX() * Seql.getY() - Seql.getX() * _P[0].getY()) - (_P[i].getX() * Seql.getY() - Seql.getX() * _P[i].getY()) + (_P[i].getX() * _P[0].getY() - _P[0].getX() * _P[i].getY()));
		}
	}
	return Area;
}

double Polygon::getPerimeter()
{
	//Finding Seql :
	double x = 0, y = 0;
	for (int i = 0; i < _Side; i++) {
		x += _P[i].getX();
		y += _P[i].getY();
	}
	Point Seql(x / _Side, y / _Side);

	//After putting them in the right order . 
	for (int i = 0; i < _Side - 1; i++) {
		for (int j = 0; j < _Side - 1; j++) {
			if (atan2(_P[j].getY() - Seql.getY(), _P[j].getX() - Seql.getX()) > atan2(_P[j + 1].getY() - Seql.getY(), _P[j + 1].getX() - Seql.getX())) {
				Point t;
				t = _P[j + 1];
				_P[j + 1] = _P[j];
				_P[j] = t;
			}
		}
	}
	double Perimeter = 0;
	for (int i = 0; i < _Side;  i++) {
		if (i != _Side - 1) {
			Perimeter += sqrt(pow(_P[i].getX() - _P[i + 1].getX(), 2) + pow(_P[i].getY() - _P[i + 1].getY(), 2));
		}
		else {
			Perimeter += sqrt(pow(_P[i].getX() - _P[0].getX(), 2) + pow(_P[i].getY() - _P[0].getY(), 2));
		}
	}
	return Perimeter;
}

double Polygon::totalAngels()
{
	return 180.0 * (_Side - 2);
}

void Polygon::PictureX()
{
	for (int i = 0; i < _Side; i++) {
		Point p(_P[i].getX(),-_P[i].getY());
		_P[i] = p;
	}

	cout << "Here are the Points : ";
	for (int i = 0; i < _Side; i++) {
		cout << _P[i];
	}
}

void Polygon::PictureY()
{
	for (int i = 0; i < _Side; i++) {
		Point p(-_P[i].getX(), _P[i].getY());
		_P[i] = p;
	}
	cout << "Here are the Points : ";
	for (int i = 0; i < _Side; i++) {
		cout << _P[i];
	}
}

void Polygon::PictureM()
{
	for (int i = 0; i < _Side; i++) {
		Point p(-_P[i].getX(), -_P[i].getY());
		_P[i] = p;
	}

	cout << "Here are the Points : ";
	for (int i = 0; i < _Side; i++) {
		cout << _P[i];
	}
	cout << endl;
}

void Polygon::PictureK(int k){
	if (k < 0) {
		k = 1 / abs(k);
	}
	for (int i = 0; i < _Side; i++) {
		Point p(k*_P[i].getX(), k*_P[i].getY());
		_P[i] = p;
	}

	cout << "Here are the Points : ";
	for (int i = 0; i < _Side; i++) {
		cout << _P[i];
	}
	cout << endl;
}

void Polygon::Transfer(Point o)
{
	for (int i = 0; i < _Side; i++) {
		Point p(_P[i].getX()+o.getX(), _P[i].getY()+o.getY());
		_P[i] = p;
	}

	cout << "Here are the Points : ";
	for (int i = 0; i < _Side; i++) {
		cout << _P[i];
	}
	cout << endl;
}

void Polygon::Ghotbi()
{
	int min = _P[0].getY();
	int index = 0;
	for (int i = 1; i < _Side; i++) {
		if (_P[i].getY() < min) {
			index = i;
		}
	}

	//Putting them in the right order base on the minimum Y;

	for (int i = 0; i < _Side - 1; i++) {
		for (int j = 0; j < _Side - 1; j++) {
			if (atan2(_P[j].getY() - _P[index].getY(), _P[j].getX() - _P[index].getX()) > atan2(_P[j + 1].getY() - _P[index].getY(), _P[j + 1].getX() - _P[index].getX())) {
				Point t;
				t = _P[j + 1];
				_P[j + 1] = _P[j];
				_P[j] = t;
			}
		}
	}

	cout << "Here are the new orders: ";
	for (int i = 0; i < _Side; i++) {
		cout << _P[i];
	}

	cout << endl;
}

void Polygon::Mohadab()
{
	bool flag=true;
	double Helper= (_P[1].getX() * _P[2].getY() - _P[2].getX() * _P[1].getY()) - (_P[0].getX() * _P[2].getY() - _P[2].getX() * _P[0].getY()) + (_P[0].getX() * _P[1].getY() - _P[1].getX() * _P[0].getY());
	if(Helper>0){
		for (int i = 1; i < _Side - 1; i++) {
			if (i != _Side - 1) {
				Helper=(_P[i + 1].getX() * _P[i + 2].getY() - _P[i + 2].getX() * _P[i + 1].getY()) - (_P[i].getX() * _P[i + 2].getY() - _P[i + 2].getX() * _P[i].getY()) + (_P[i].getX() * _P[i + 1].getY() - _P[i + 1].getX() * _P[i].getY());
				if (Helper < 0) {
					flag = false;
				}
			}
			else if (i == _Side - 1) {
				Helper = (_P[i + 1].getX() * _P[0].getY() - _P[0].getX() * _P[i + 1].getY()) - (_P[i].getX() * _P[0].getY() - _P[0].getX() * _P[i].getY()) + (_P[i].getX() * _P[i + 1].getY() - _P[i + 1].getX() * _P[i].getY());
				if (Helper < 0) {
					flag = false;
				}
			}
		}
		if(flag == true)
			cout << "Chapghard";
		else
		cout << "None";
	}
	else if(Helper<0){
		for (int i = 1; i < _Side - 1; i++) {
			if (i != _Side - 1) {
				Helper = (_P[i + 1].getX() * _P[i + 2].getY() - _P[i + 2].getX() * _P[i + 1].getY()) - (_P[i].getX() * _P[i + 2].getY() - _P[i + 2].getX() * _P[i].getY()) + (_P[i].getX() * _P[i + 1].getY() - _P[i + 1].getX() * _P[i].getY());
				if (Helper > 0) {
					flag = false;
				}
			}
			else if (i == _Side - 1) {
				Helper = (_P[i + 1].getX() * _P[0].getY() - _P[0].getX() * _P[i + 1].getY()) - (_P[i].getX() * _P[0].getY() - _P[0].getX() * _P[i].getY()) + (_P[i].getX() * _P[i + 1].getY() - _P[i + 1].getX() * _P[i].getY());
				if (Helper > 0) {
					flag = false;
				}
			}
		}

		if (flag == true) 
			cout << "Rastgard";
		else
			cout << "None";
		
	}
}
