//
// Labb 2: Fakultetsber�kning
// �rebro Universitet
// Tobias Lans, Bobo Lillqvist
// https://github.com/BoboLillqvist/doa
//
#include <iostream>
#include <chrono>
#include "Watch.h"
#include "fakultet.h"
#include <iomanip> 
using namespace std;
using namespace Course;
int main()
{
	Course::Watch w;
	w.restart();
	Course::nanoseconds t0,t1;
	cout << "Rekursiv fakultet:\n" << endl;
	for (long i = 1; i < 10; i++)
	{
		long n = i;
		cout << n << "s fakultet �r: " << rekursivFakultet(n) << endl;
	}
	t0 = w.elapsedNs();
	w.restart();
	cout << "Iterativ fakultet:\n" << endl;
	for (long i = 1; i < 10; i++)
	{
		long n = i;
		cout << n << "s fakultet �r: " << iterativFakultet(n) << endl;
	}
	t1 = w.elapsedNs();
	cout <<"\nTid f�r rekursiv fakultet: "<< t0.count() << " ns\nTid f�r iterativ fakultet: " <<t1.count()<<" ns"<< endl;
	system("pause");
	return 0;
}