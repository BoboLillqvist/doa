#pragma once
#include "InterestTable.h"
#include <vector>

class Person
{
private:
    size_t id_;
    size_t age_;
    std::string name_;
    char gender_;
    std::vector<std::string> preferences_; //Andra till vector av chars istallet? Blir lattare att jamnfora med gender i sa fall.
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

    InterestTable& getInterestTable()
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

    // Friends
    friend std::istream& operator>>(std::istream&, Person& person);
};

inline
std::istream& operator>>(std::istream& is, Person& person)
{
    std::string junk;

    // ID
    is >> person.id_; std::getline(is, junk, ';');

    // Age
    is >> person.age_; std::getline(is, junk, ';');

    // Name
    std::getline(is, person.name_, ';');

    // Gender
    is >> person.gender_; std::getline(is, junk, ';');

    // TODO: Fixa generalisera kod

    // Preferences
    std::string preferences;
    std::getline(is, preferences, ';');
    std::istringstream istream(preferences);
    std::string pref;

    // Read comma separated values and push back in vector
    while (std::getline(istream, pref, ','))
        person.preferences_.push_back(pref);


    // Interests
    std::string interests;
    std::getline(is, interests);
    std::istringstream iss(interests);
    std::string interest;

    // Read comma separated values and push back in vector
    while (std::getline(iss, interest, ','))
        person.it_.add(interest);

    return is;
}

