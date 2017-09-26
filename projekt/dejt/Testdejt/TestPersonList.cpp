#include "catch.hpp"
#include "../dejt/PersonList.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

TEST_CASE("Test List Class")
{
    SECTION("Test reading persons from file")
    {
        PersonList personList;

        // TODO: Gör testet på en testfil som man skapar här
        SECTION("Test opening files")
        {
            // Should throw exception
            REQUIRE_THROWS(personList.fileToList("wrongfilename.csv"));
            REQUIRE_THROWS(personList.fileToList(""));

            // Should NOT throw exception
            REQUIRE_NOTHROW(personList.fileToList("../dejt/male.csv"));

            SECTION("Test numPersons() method")
            {
                REQUIRE(personList.numPersons() == 4);
            }
        }

        SECTION("Test the list")
        {
            // TODO: Write test for list
        }
    }
}