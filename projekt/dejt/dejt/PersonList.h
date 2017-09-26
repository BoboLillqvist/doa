#pragma once
#include <forward_list>
#include <iostream>
#include <fstream> // std::ifstream
#include <sstream>
#include <exception>
#include <vector>
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

    void fileToList(std::string filename)
    {
        std::string line;
        std::ifstream listFile;

        // Open the file for out operations
        listFile.open(filename, std::ios::out);

        if (!listFile)
            throw std::exception("Could not open file");

        // Read line by line
        while (std::getline(listFile, line))
            list.push_front(personFromString(line));

        listFile.close();
    }

    Person personFromString(std::string line)
    {
        // TODO: G�r s�kert att g�ra lite mer elegant
        size_t id;
        std::string name;
        char gender;
        std::string preference;
        std::vector<std::string> interests = { "mat", "k�rv" };

        std::istringstream iss(line);

        iss >> id >> name >> gender >> preference;

        Person person(id, name, gender, preference, interests);
        return person;
    }

    int numPersons()
    {
        int persons = 0;
        for (auto person : list)
            persons++;

        return persons;
    }
};
