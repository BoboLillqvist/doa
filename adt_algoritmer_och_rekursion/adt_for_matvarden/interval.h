#pragma once
#include <iostream>
#include <sstream>

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

    T mean()
    {
        return (lower + upper) / 2;
    }

	double absoluteError()
	{

	}

	double relativeError()
	{

	}

    static T max(T set[])
    {
        auto max = set[0];
        for (auto i = 0; i < sizeof(set); i++)
        {
            if (max < set[i])
                max = set[i];
        }
        return max;
    }

    static T min(T set[])
    {
        auto min = set[0];
        for (auto i = 0; i < sizeof(set); i++)
        {
            if (min > set[i])
                min = set[i];
        }
        return min;
    }

	friend interval<T> operator+(const interval<T> &lop, const interval<T> &rop)
	{
        interval<T> m;

        m.lower = lop.lower + rop.lower;
        m.upper = lop.upper + rop.upper;

        return m;
	}

	friend interval<T> operator-(const interval<T> &lop, const interval<T> &rop)
	{
        interval<T> m;

        m.lower = lop.lower - rop.upper;
        m.upper = lop.upper - rop.lower;

        return m;
	}

	friend interval<T> operator*(const interval<T> &lop, const interval<T> &rop)
	{
        interval<T> m;

        T set[] = { lop.lower * rop.lower, lop.lower * rop.upper, lop.upper * rop.lower, lop.upper * rop.upper };

        m.upper = max(set);
        m.lower = min(set);

        return m;
	}

	friend std::ostream& operator<<(std::ostream &out, const interval<T> &rop)
	{
        out << "[" << rop.lower << ", " << rop.upper << "]";
        return out;
	}
};