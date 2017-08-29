#pragma once
#include <iostream>

template <class T>
class interval
{
private:
	T upper;
	T lower;

public:
	interval(void)
	{
		lower = upper = 0;
	}

	interval(T mean, double procent)
	{
		lower = (T)(mean - mean * procent / 100);
		upper = (T)(mean + mean * procent / 100);
	}
};