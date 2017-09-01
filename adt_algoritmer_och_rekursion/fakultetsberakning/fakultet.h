#pragma once
#include <iostream>
#include <time.h>
long rekursivFakultet(long n)
{
	if (n == 0)
		return 1;
	else
		return n*rekursivFakultet(n - 1);
}

long iterativFakultet(long n)
{
	long product = 1;
	for (long i = 1; i <= n; i++)
		product *= i;
	return product;
}