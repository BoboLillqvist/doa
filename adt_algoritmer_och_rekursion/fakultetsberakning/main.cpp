//
// Labb 2: Fakultetsber�kning
// �rebro Universitet
// Tobias Lans, Bobo Lillqvist
// https://github.com/BoboLillqvist/doa
//
#include <iostream>
#include "fakultet.h"
using namespace std;

int main()
{
	long x = 5;
	long y = 7;
	long z = 11;
	cout << "X �r:" << x << endl;
	cout << "Y �r:" << y << endl;
	cout << "Z �r:" << z << endl;
	x=fakultet(x);
	y = fakultet(y);
	z = fakultet(z);
	cout << "Fakulteten av X �r:" << x << endl;
	cout << "Fakulteten av Y �r:" << y << endl;
	cout << "Fakulteten av Z �r:" << z << endl;
	system("pause");
	return 0;
}