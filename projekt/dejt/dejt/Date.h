#pragma once
#include "PersonList.h"
#include "CoupleList.h"

class Date
{
private:
	PersonList boys;
	PersonList girls;
	CoupleList couples;
public:
	Date()
	{
		
	}

	void match()
	{

	}

	PersonList& getBoysList()
	{
		return boys;
	}

	PersonList& getGirlsList()
	{
		return girls;
	}

	CoupleList& getCouplesList()
	{
		return couples;
	}

	int numberOfCouples()
	{
		int amount = 0;
		for (auto it=couples.getList().begin(); it!= couples.getList().end();it++) 
		{
			amount++;
		}
		return amount;
	}
};