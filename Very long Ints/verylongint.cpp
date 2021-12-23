#include<iostream>
#include "verylongint.h"
using namespace std;


istream& operator>>(istream& in, verylongint& v) {
	string Buffer;
	cin >> Buffer;
	int i = 0;
	for (; Buffer[i] != '\0'; i++);
	cout << endl;
	v.len = i;
	v.add = new int[v.len];
	for (int j = 0; j < i; j++) {
		v.add[j] = (int)Buffer[j] - 48;
	}
	return in;
};

ostream& operator<<(ostream& out, verylongint& v) {
	int i = 0;
	if (v.add[0] <= 0) { i = 1; } // when we are adding two verylongints sometimes the first one is gonning to be zero .
	for (; i <= v.len; i++) {
		if (v.add[i] >= 0)
			cout << v.add[i];
	}
	cout << endl;
	int j = 0;
	if (v.add[0] <= 0) { j = 1; }
	for (; j < v.len; j++) {
		cout << v.add[j];
		if (j == 1) {
			cout << ".";
		}
	}
	cout << "E" << v.len - 1;
	return out;
};
verylongint::verylongint(const verylongint& v)
{
	this->len = v.len;
	add = new int[v.len];
	for (int i = 0; i < v.len; i++) {
		this->add[i] = v.add[i];
	}
}

verylongint& verylongint::operator=(const verylongint& v)
{
	this->len = v.len;
	this->add = new int[v.len];
	for (int i = 0; i <= v.len; i++) {
		this->add[i] = v.add[i];
	}
	return *this;
}

int& verylongint::operator[](int index)
{
	return add[index];
}

verylongint verylongint::operator+(verylongint& v)
{
	int* tempb = '\0'; // For easier calculation I created a new array that This one is Bigger one .
	int* tempk = '\0'; // And the smaller one ;
	int* temp = '\0'; // This is the answer one ;
	int i = 0;
	int j = 0;
	int k = 0;
	if (this->len > v.len) {
		k = this->len;
		temp = new int[this->len + 1];
		//Smaller ones len = j & Bigger ones len = i ;

		tempb = new int[this->len];
		for (; i < this->len; i++) {
			tempb[i] = this->add[i];
		}

		tempk = new int[v.len];
		for (; j < v.len; j++) {

			tempk[j] = v.add[j];
		}
	}
	else {
		k = v.len;
		temp = new int[v.len + 1];

		tempb = new int[v.len];
		for (; i < v.len; i++) {
			tempb[i] = v.add[i];
		}
		tempk = new int[this->len];
		for (; j < this->len; j++) {
			tempk[j] = this->add[j];
		}
	}

	for (int h = 0; h <= k; h++) {
		temp[h] = 0;
	}

	int templen = k; // for returning the len of the answer . 
	k++;

	// The Adding Operation . 

	while (j != -1) {
		temp[k] += tempb[i] + tempk[j];
		if (temp[k] >= 10) {
			temp[k - 1]++;
			temp[k] = temp[k] % 10;
		}
		i--; j--; k--;
	}
	//filling the renaining numbers . 

	for (; i != -1; i--, k--) {
		temp[k] += tempb[i];
		if (temp[k] >= 10) {
			temp[k - 1]++;
			temp[k] = temp[k] % 10;
		}
	}

	delete[]tempb;
	delete[]tempk;
	tempb = '\0';
	tempk = '\0';
	return verylongint(temp, templen);
}

verylongint verylongint::operator-(verylongint& v)
{
	int* tempb = '\0'; // For easier calculation I created a new array that This one is Bigger one .
	int* tempk = '\0'; // And the smaller one ;
	int* temp = '\0'; // This is the answer one ;
	int i = 0;
	int j = 0;
	int k = 0;
	bool flag = true;
	if (this->len == v.len) {
		//comparing 
		for (int y = 0; y < this->len && flag; y++) {
			if (this->add[y] < v.add[y]) {
				flag = false;
			}
		}
		if (flag) {
			k = this->len;
			temp = new int[this->len + 1];
			//Smaller ones len = j & Bigger ones len = i ;

			tempb = new int[this->len];
			for (; i < this->len; i++) {
				tempb[i] = this->add[i];
			}

			tempk = new int[v.len];
			for (; j < v.len; j++) {

				tempk[j] = v.add[j];
			}
		}
		else if (!flag) {
			k = v.len;
			temp = new int[v.len + 1];

			tempb = new int[v.len];
			for (; i < v.len; i++) {
				tempb[i] = v.add[i];
			}
			tempk = new int[this->len];
			for (; j < this->len; j++) {
				tempk[j] = this->add[j];
			}
			cout << "-";
		}
	}
	if (this->len > v.len) {
		k = this->len;
		temp = new int[this->len + 1];
		//Smaller ones len = j & Bigger ones len = i ;

		tempb = new int[this->len];
		for (; i < this->len; i++) {
			tempb[i] = this->add[i];
		}

		tempk = new int[v.len];
		for (; j < v.len; j++) {

			tempk[j] = v.add[j];
		}
	}
	else if (this->len < v.len) {
		k = v.len;
		temp = new int[v.len + 1];

		tempb = new int[v.len];
		for (; i < v.len; i++) {
			tempb[i] = v.add[i];
		}
		tempk = new int[this->len];
		for (; j < this->len; j++) {
			tempk[j] = this->add[j];
		}
		cout << "-";
	}

	for (int h = 0; h <= k; h++) {
		temp[h] = 0;
	}

	int templen = k; // for returning the len of the answer . 
	i--; j--;
	// The Adding Operation . 

	while (j != -1) {
		temp[k] += tempb[i] - tempk[j];
		if (temp[k] < 0) {
			temp[k - 1]--;
			temp[k] = temp[k] + 10;
		}
		i--; j--; k--;
	}
	//filling the renaining numbers . 

	for (; i != -1; i--, k--) {
		temp[k] += tempb[i];
		if (temp[k] < 0) {
			temp[k - 1]--;
			temp[k] = temp[k] + 10;
		}
	}


	delete[]tempb;
	delete[]tempk;
	tempb = '\0';
	tempk = '\0';
	return verylongint(temp, templen);
}

