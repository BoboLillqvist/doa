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

	int numberOfPersons() //Förutsätter att en person inte dubbellagras i olika listor
	{
		int amount = 0;
		
		for (auto it1 = boys.getList().begin(); it1 != boys.getList().end(); it1++) 
		{
			amount++;
		}

		for (auto it2 = girls.getList().begin(); it2 != girls.getList().end(); it2++) 
		{
			amount++;
		}
		for (auto it3 = couples.getList().begin(); it3 != couples.getList().end(); it3++)
		{
			amount++; 
			amount++;
		}
		return amount;
	}
};