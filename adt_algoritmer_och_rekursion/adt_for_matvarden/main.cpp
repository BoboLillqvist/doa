//
// Labb 1: ADT för mätvärden
// Örebro Universitet
// Tobias Lans, Bobo Lillqvist
// https://github.com/BoboLillqvist/doa
//
#include <iostream>
#include "interval.h"
using namespace std;

int main()
{
	interval<int> u1(-10, 4);
	interval<int> u2(8, 2);

    cout << "u1: " << u1 << endl;
    cout << "u2: " << u2 << endl;
    cout << "u1 + u2: " << u1 + u2 << endl;
    cout << "u1 - u2: " << u1 - u2 << endl;
    cout << "u1 * u2: " << u1 * u2 << endl;

    system("pause");
	return 0;
}