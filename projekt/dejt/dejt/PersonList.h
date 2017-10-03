#pragma once
#include "Person.h"
#include <forward_list>
#include <iostream>
#include <fstream> // std::ifstream
#include <sstream>
#include <exception>
#include <vector>

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

    void add(Person person)
    {
        list.push_front(person);
    }

    void fileToList(std::string filename)
    {
        std::string line;
        std::ifstream listFile(filename);

        // Open the file for out operations
        //listFile.open(filename);

        if (!listFile)
            throw std::exception("Could not open file");

        // Read line by line
        while (std::getline(listFile, line, '\n'))
        {
            Person person;
            std::istringstream iss(line);

            iss >> person;

            add(person);
        }

        listFile.close();
    }

    void listToFile(std::string filename)
    {
        std::ofstream listFile;

        // Open file
        listFile.open(filename);

        if (!listFile)
            throw std::exception("Could not open file");

        for (auto person : list)
            listFile << person;
    }

    int numPersons()
    {
        int persons = 0;
        for (auto person : list)
            persons++;

        return persons;
    }
};
