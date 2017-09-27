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
		int threshhold = 1;
		for (auto it1 : boys.getList())
		{
			Person* favorite=nullptr;
			int bestMatch = 0, temp=0;
			for (auto it2 : boys.getList())
			{
				if (it1.getID() != it2.getID())
				{
					compatibility(threshhold, it1, it2, bestMatch, temp, favorite);
				}
			}

			for (auto it3 : girls.getList())
			{
				if (it1.getID() != it3.getID())
				{
					compatibility(threshhold, it1, it3, bestMatch, temp, favorite);
				}
				
			}

			if (favorite != nullptr)
			{
				createCouple(it1, *favorite);
			}
		}

		for (auto it4 : girls.getList())
		{
			Person* favorite2=nullptr;
			int bestMatch2 = 0, temp2 = 0;

			for (auto it5 : girls.getList())
			{
				if (it4.getID() != it5.getID())
				{
					compatibility(threshhold, it4, it5, bestMatch2, temp2, favorite2);
				}
			}

			if (favorite2 != nullptr)
			{
				createCouple(it4, *favorite2);
			}
		}
	}

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