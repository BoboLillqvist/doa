#pragma once
#include "InterestTable.h"
#include <sstream>
#include <vector>

typedef std::forward_list<std::string>::iterator interestsIterator;

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
		gender_ = gender;
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
    size_t getID() const
    {
        return id_;
    }

    size_t getAge() const
    {
        return age_;
    }

    std::string getName() const
    {
        return name_;
    }

    char getGender() const
    {
        return gender_;
    }

    std::vector<std::string> getPreferences() const
    {
        return preferences_;
    }

    InterestTable& getInterestTable()
    {
        return it_;
    }

    size_t numberOfPreferences() const
    {
        size_t counter = 0;
        for (auto pref : preferences_)
            counter++;

        return counter;
    }

    std::string preferencesToString() const
    {
        std::stringstream ss;
        for (auto item : preferences_)
        {
            ss << item;
            ss << ((item == preferences_.back()) ? "" : ",");
        }
        
        return ss.str();
    }

    std::string interestsToString()
    {
        std::stringstream ss;
        auto list = it_.getList();
        auto firstElement = list.begin();
        auto lastElement = list.end();

        interestsIterator it = firstElement;
        size_t numOfInterests = it_.numberOfInterests();
        size_t counter = 0;

        for (firstElement, counter; it != lastElement; ++it, counter++)
        {
            ss << *it;
            ss << ((counter <  numOfInterests - 1) ? "," : "");
        }

        return ss.str();
    }

    // Friends
    friend std::istream& operator>>(std::istream& is, Person& person);

    // TODO: Ska egentligen vara const Person& men fattar inte hur man ska göra just nu
    friend std::ostream& operator<<(std::ostream& os, Person& person);
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

inline
std::ostream& operator<<(std::ostream& os, Person& person)
{

    // Transform Bob -> bob
    std::string nameToStore = person.name_;
    std::transform(nameToStore.begin(), nameToStore.end(), nameToStore.begin(), tolower);

    // Append person data to stream
    os << person.id_ << ";"
       << person.age_ << ";"
       << nameToStore << ";"
       << person.gender_ << ";"
       << person.preferencesToString() << ";"
       << person.interestsToString()
       << "\n";

    return os;
}
