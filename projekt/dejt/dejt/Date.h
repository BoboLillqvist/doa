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
};