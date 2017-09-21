#pragma once
#include "Person.h"

class Couple
{
private:
    Person boy;
    Person girl;

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
