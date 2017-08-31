//
// Labb 2: Fakultetsberäkning
// Örebro Universitet
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
	cout << "X är:" << x << endl;
	cout << "Y är:" << y << endl;
	cout << "Z är:" << z << endl;
	x=fakultet(x);
	y = fakultet(y);
	z = fakultet(z);
	cout << "Fakulteten av X är:" << x << endl;
	cout << "Fakulteten av Y är:" << y << endl;
	cout << "Fakulteten av Z är:" << z << endl;
	system("pause");
	return 0;
}