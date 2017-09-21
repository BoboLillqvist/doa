#pragma once
#include <forward_list>
#include "Person.h"

class PersonList
{
private:
    std::forward_list<Person> list;

public:
    PersonList() {}

    std::forward_list<Person>& getList()
    {
        return list;
    }

    void fileToString(std::string fileName)
    {

    }
};
