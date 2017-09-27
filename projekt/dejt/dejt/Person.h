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
    // Constructors
    Person() {}

    Person(size_t id, size_t age, std::string name, char gender, std::vector<std::string> preferences, std::vector<std::string> interests)
	{
        id_ = id;
        age_ = age;
        name_ = name;
        preferences_ = preferences;
        addToInterestTable(interests);
    }

    // Methods
    void addToInterestTable(std::vector<std::string> interests)
    {
        for (auto interest : interests)
            it_.add(interest);
    }

    // Getters
    size_t getID()
    {
        return id_;
    }

    size_t getAge()
    {
        return age_;
    }

    std::string getName()
    {
        return name_;
    }

    char getGender()
    {
        return gender_;
    }

    std::vector<std::string> getPreferences()
    {
        return preferences_;
    }

    InterestTable getInterestTable()
    {
        return it_;
    }

    size_t numberOfPreferences()
    {
        size_t counter = 0;
        for (auto pref : preferences_)
            counter++;

        return counter;
    }

