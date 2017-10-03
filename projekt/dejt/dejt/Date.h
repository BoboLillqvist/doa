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
		for (auto &it1 : boys.getList())
		{
			Person* favorite=nullptr;
			int bestMatch = 0, temp=0;
			for (auto &it2 : boys.getList())
			{
				if (it1.getID() != it2.getID())
				{
					compatibility(threshhold, it1, it2, bestMatch, temp, favorite);
				}
			}

			for (auto &it3 : girls.getList())
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

		for (auto &it4 : girls.getList())
		{
			Person* favorite2=nullptr;
			int bestMatch2 = 0, temp2 = 0;

			for (auto &it5 : girls.getList())
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

	void compatibility(int threshhold, Person& personA, Person& personB, int& bestMatch, int& temp, Person*& favorite)
	{
		if ((compareAge(personA, personB) && comparePreferences(personA, personB)))
		{
			temp = compareInterests(personA, personB);
			if ((temp >= threshhold) && (temp > bestMatch))
			{
				favorite = &personB;
				bestMatch = temp;
			}
		}

	}

	void createCouple(Person& personA, Person& personB)
	{
        bool alreadyInCouple = false;
        for (auto &itc : getCouplesList().getList())
        {
            if (
                (personA.getID() == itc.getPersonA().getID()) || (personB.getID() == itc.getPersonB().getID()) ||
                (personA.getID() == itc.getPersonB().getID()) || (personB.getID() == itc.getPersonA().getID())
                )
            {
                alreadyInCouple = true;
            }
        }
        if (!alreadyInCouple)
        {
            Couple couple1(personA, personB);
            couples.add(couple1);
        }

	}

	void removePersonFromList(Person& personA)
	{
		//Todo: removeperson from list
	}

	bool compareAge(Person& personA, Person& personB)
	{
		if (personB.getAge() > personA.getAge())
		{
			if ((((personB.getAge()) / 2) + 7) > personA.getAge())
			{
				return false;
			}
		}
		if (personB.getAge()<personA.getAge())
		{
			if ((((personB.getAge()) * 2) - 7) < personA.getAge())
			{
				return false;
			}
		}
		if (personA.getAge() > personB.getAge())
		{
			if ((((personA.getAge()) / 2) + 7) > personB.getAge())
			{
				return false;
			}
		}
		if (personA.getAge()<personB.getAge())
		{
			if ((((personA.getAge()) * 2) - 7) < personB.getAge())
			{
				return false;
			}
		}
			return true;
	}

	bool comparePreferences(Person& personA, Person& personB)
	{

		//Ta den forsta personens preference. Ar den samma av samma gender som preferensen? Kolla sedan om detsamma ar sant for den andra.
		bool matchAtoB = false, matchBtoA = false;
		for (auto it1 : personA.getPreferences())
		{
			if ((it1 == "female") && (personB.getGender() == 'f'))
				matchAtoB = true;
			if ((it1 == "male") && (personB.getGender() == 'm'))
				matchAtoB = true;
		}
		for (auto it2 : personB.getPreferences())
		{
			if ((it2 == "female") && (personA.getGender() == 'f'))
				matchBtoA = true;
			if ((it2 == "male") && (personA.getGender() == 'm'))
				matchBtoA = true;
		}
		if (matchAtoB && matchBtoA)
			return true;
		else
			return false;
	}

	int compareInterests(Person& personA, Person& personB)
	{
		return (personA.getInterestTable().numberOfCommonInterests(personB.getInterestTable()));
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
		// EXTRA: Andra numberOfPersons
		// sa att den raknar unika persons genom t.ex. ID sa att det inte spelar nagon roll om en person ar lagrad i flera listor. 
		int amount = 0;
		
		for (auto it1 = boys.getList().begin(); it1 != boys.getList().end(); it1++) 
		{
			amount++;
		}

		for (auto it2 = girls.getList().begin(); it2 != girls.getList().end(); it2++) 
		{
			amount++;
		}
		return amount;
	}
};