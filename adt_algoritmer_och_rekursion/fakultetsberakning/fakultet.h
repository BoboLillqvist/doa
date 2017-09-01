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
}