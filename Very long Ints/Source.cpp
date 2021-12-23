#include<iostream>
#include<conio.h>
#include "verylongint.h"

using namespace std;


int main() {
	verylongint x, y;
	cout << "Please Enter the First Number : ";
	cin >> x;
	cout << "Please Enter the Second Number : ";
	cin >> y;
	char CJ;
	cout << "Please Choose an Operation (+) or (-)";
	cin >> CJ;
	switch (CJ) {
	case'+': {
		verylongint a;
		a = x + y;
		cout << a;
		break;
	}
	case '-': {
		verylongint a;
		a = x - y;
		cout << a;
		break;
	}
	default: cout << "Error";
	}

}




