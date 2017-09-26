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

	void setPersonA(Person& person)
	{
		personA = &person;
	}

	void setPersonB(Person& person)
	{
		personB = &person;
	}

    Person& getPersonA()
    {
        return *personA;
    }

    Person& getPersonB()
    {
        return *personB;
    }
};
