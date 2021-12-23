#include"Shape.h"
#include"Point.h"
#include"Polygon.h"
#include"Triangle.h"
#include"FourSquare.h"
#include"Parallelogram.h"
#include"Square.h"
#include"Pentagon.h"
#include"Hexagon.h"
#include<iostream>

using namespace std;

Shape* s;

void Trianglef();
void FourSquaref();
void Pentagonf();
void Hexagonf();
void Moref();

void Operations(Shape*);

int main() {
	cout << "Please Choose the Shape : " << endl;
	cout << "3.Triangle." << endl << "4.FourSquare" <<endl<< "5.Pentagon" <<endl<< "6.Hexagon" <<endl<< "7.For more than these : ";
	int n;
	cin >> n;
	switch(n){
	case 3:Trianglef(); break;
	case 4:FourSquaref(); break;
	case 5: Pentagonf(); break;
	case 6: Hexagonf(); break;
	case 7: Moref(); break;
	}

}

void Trianglef()
{
	Point* p = new Point[3];
	cout << "Please Enter the Points : "<<endl;
	for (int i = 0; i < 3; i++) {
		cin >> p[i];
	}
	Triangle T(p[0], p[1], p[2]);
	s = &T;
	Operations(s);
	delete[]p;
}

void FourSquaref()
{
	Point* p = new Point;
	cout << "Select the type of your FourSquare : " << endl;
	cout << "1.Square , " << "2.Rectangle , " << "3.Parrallelogram , " << "4.None" << endl;
	int n;
	cin >> n;
	if (n == 1) {
		cout << "Please Enter the right up corner Point : ";
		cin >> p[0];
		cout << "And the len of one side : ";
		int a1;
		cin >> a1;
		Square sq(p[0], a1);
		s = &sq;
		Operations(s);
	}
	else if (n == 2) {
		cout << "Please Enter the right up corner Point : ";
		cin >> p[0];
		cout << "And the  sides : ";
		int a2, b2;
		cin >> a2 >> b2;
		Rectangle r(p[0], a2, b2);
		s = &r;
		Operations(s);
	}
	else if (n == 3) {
		cout << "Please Enter the right up corner Point : ";
		cin >> p[0];
		cout << "And the  sides (the last one is tete ) : ";
		int a3, b3;
		double teta;
		cin >> a3 >> b3 >> teta;
		Parallelogram pa(p[0], a3, b3, teta);
		s = &pa;
		Operations(s);
	}
	else if (n == 4) {
		Point* p1 = new Point[4];
		for (int i = 0; i < 4; i++) {
			cin >> p1[i];
		}
		FourSquare fo(p1[0], p1[1], p1[2], p1[3]);
		s = &fo;
		Operations(s);
		delete[]p1;
	}

	
}

void Pentagonf()
{
	cout << "Please Enter the Points :";
	Point* p = new Point[5];
	for (int i = 0; i < 5; i++) {
		cin >> p[i];
	}
	Pentagon pe(p[0], p[1], p[2], p[3], p[4]);
	s = &pe;
	Operations(s);
}

void Hexagonf()
{
	cout << "Please Enter the Points :";
	Point* p = new Point[6];
	for (int i = 0; i < 6; i++) {
		cin >> p[i];
	}
	Hexagon he(p[0], p[1], p[2], p[3], p[4],p[5]);
	s = &he;
	Operations(s);
}

void Moref()
{
	cout << "Please Enter the number of Points : ";
	int n;
	cin >> n;
	Point* p = new Point[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	Polygon po(p, n);
	s = &po;
	Operations(s);
	delete[]p;
}

void Operations(Shape* s) {
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "Please Choose the Operations : ";
		cout << "1.Area" << endl << "2.Perimeter " << endl << "3.Angles" << endl << "4.PictureX" << endl << "5.PictureY" << endl << "6.PictureK" << endl << "7.Transfer" << endl << "8.PictureM" << endl << "9.Gotbi" << endl << "10.Mohadab"<<endl<<"Operation : ";
		int n;
		cin >> n;
		int x;
		Point p;
		switch (n)
		{
		case 1:
			cout << s->getArea();
			break;
		case 2:
			cout<<s->getPerimeter(); break;
		case 3:
			cout<<s->totalAngels(); break;
		case 4:
			s->PictureX(); break;
		case 5:
			s->PictureY(); break;
		case 6:
			cout << "Please Enter the Multify number : ";
			cin >> x;
			s->PictureK(x); break;
		case 7:
			cout << "Please Enter the Piont that you want to Tranfer : ";
			cin >> p;
			s->Transfer(p);
			break;
		case 8:
			s->PictureM(); break;
		case 9:
			s->Ghotbi(); break;
		case 10:
			s->Mohadab(); break;
		default:
			cout << "Error";
			break;
		}
		cout <<endl<< "Do you want to Continue with this Shape (y for YES & n for NO) : ";
		char choose;
		cin >> choose;
		if (choose == 'n') {
			flag = false;
		}
	}

};