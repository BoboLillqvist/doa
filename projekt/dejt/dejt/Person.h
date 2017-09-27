#pragma once
#include "InterestTable.h"
#include <vector>

class Person
{
private:
    size_t id_;
    std::string name_;
    char gender_;
    std::vector<std::string> preferences_;
	InterestTable it_;

public:
    Person() {}

    Person(size_t id, size_t age, std::string name, char gender, std::vector<std::string> preferences, std::vector<std::string> interests)
	{
        id_ = id;
        name_ = name;
        preferences_ = preferences;
        addToInterestTable(interests);
    }

    void addToInterestTable(std::vector<std::string> interests)
    {
        for (auto interest : interests)
            it_.add(interest);
    }

    InterestTable getInterestTable()
    {
        return it_;
    }
};