#include "catch.hpp"
#include "../dejt/PersonList.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio> // std::remove()
using namespace std;

TEST_CASE("Test List Class")
{
    SECTION("Test numPersonss() method")
    {
        Person bob(0, 23, "Bob", 'm', { "male", "female" }, {"sport", "fiske"});
        Person maja(1, 30, "Maja", 'f', { "male" }, {"film", "musik"});

        PersonList persons;
        persons.getList().push_front(bob);
        persons.getList().push_front(maja);

        REQUIRE(persons.numPersons() == 2);
    }

    SECTION("Test reading persons from file")
    {
        PersonList personList;

        // TODO: Gör testet på en testfil som man skapar här
        SECTION("Test opening files")
        {
            // Trying to open wrong file path should throw exception
            REQUIRE_THROWS(personList.fileToList("wrongfilename.csv"));
            REQUIRE_THROWS(personList.fileToList(""));

            // Should NOT throw exception
            REQUIRE_NOTHROW(personList.fileToList("../dejt/male.csv"));

            SECTION("Test if right number of persons was stored")
            {
                REQUIRE(personList.numPersons() == 4);
            }
        }
    }
}