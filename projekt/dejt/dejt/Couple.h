#pragma once
#include "Person.h"

class Couple
{
private:
    Person* personA;
    Person* personB;

public:
    Couple() {}
	Couple(Person& persona,Person& personb) 
	{
		setPersonA(persona);
		setPersonB(personb);
	}

    Person& getBoy()
    {
        return boy;
    }

    Person& getGirl()
    {
        return girl;
    }
};
