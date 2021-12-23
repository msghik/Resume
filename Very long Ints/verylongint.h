#include<iostream>
using namespace std;
class verylongint {
	friend istream& operator>>(istream& in, verylongint& v);
	friend ostream& operator<<(ostream& out, verylongint& v);
private:
	int* add;
	int len;
	void initialize() {
		add = '\0';
		len = 0;
	}
public:
	verylongint() {
		initialize();
	};
	verylongint(const verylongint& v);
	verylongint(int* a, int b) {
		add = a;
		len = b;
	};
	~verylongint() {
		add = '\0';
		len = 0;
	};
	verylongint operator+(verylongint& v);
	verylongint operator-(verylongint& v);
	verylongint& operator=(const verylongint& v);
	int& operator[](int);
};