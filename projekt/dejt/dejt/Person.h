#pragma once
#include "InterestTable.h"
#include <vector>

class Person
{
private:
    size_t id_;
    std::string name_;
    char gender_;
    std::string preference_;
	InterestTable it_;

public:
    Person() {}

    Person(size_t id, std::string name, char gender, std::string preference, std::vector<std::string> interests)
	{
        id_ = id;
        name_ = name;
        preference_ = preference;
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