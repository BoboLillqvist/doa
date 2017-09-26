#pragma once
#include "Person.h"

class Couple
{
private:
    Person* personA;
    Person* personB;

public:
    Couple() {}

    Person& getBoy()
    {
        return boy;
    }

    Person& getGirl()
    {
        return girl;
    }
};
