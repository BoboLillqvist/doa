#include "catch.hpp"
#include "../dejt/Person.h"
#include <vector>
#include <sstream>
#include <iostream>

TEST_CASE("Test Person Class")
{
    std::vector<std::string> interests;
    interests.push_back("sport");
    interests.push_back("FILM");
    interests.push_back("Mat");

    std::vector<std::string> interests2;
    interests2.push_back("FILM");
    interests2.push_back("Mat");
    interests2.push_back("sport");

    Person bob(0, 23, "Bob", 'm', { "male", "female" }, interests);
    Person maja(1, 30, "Maja", 'f', { "male"}, interests2);

    SECTION("Test person interest table")
    {
        REQUIRE(bob.getInterestTable() == maja.getInterestTable());
    }

    SECTION("Test preferencesToString()")
    {
        std::string bobsPreferences = "male,female";
        std::string majasPreferences = "male";
        REQUIRE(bob.preferencesToString() == bobsPreferences);
        REQUIRE(maja.preferencesToString() == majasPreferences);
    }

    SECTION("Test interestsToString()")
    {
        std::string bobsInterests = "mat,film,sport";
        std::string majasInterests = "sport,mat,film";
        REQUIRE(bob.interestsToString() == bobsInterests);
        REQUIRE(maja.interestsToString() == majasInterests);
    }

    SECTION("Test >> operator overload")
    {
        Person bob;

        // Simulate file
        std::string line = "0;20;Bob;m;female,male;kaffe,sport,sprit\n";

        // Add in string stream
        std::istringstream iss(line);

        // Add first line data to person
        iss >> bob;

        SECTION("Test static length data")
        {
            // Test if static data was stored
            REQUIRE(bob.getID() == 0);
            REQUIRE(bob.getAge() == 20);
            REQUIRE(bob.getName() == "Bob");
            REQUIRE(bob.getGender() == 'm');
        }

        SECTION("Test preferences was stored", "[preferences]")
        {
            CHECK(bob.numberOfPreferences() == 2);
            std::string bobPreference[] = { "female", "male" };

            size_t i = 0;
            for (auto pref : bob.getPreferences())
            {
                REQUIRE(pref == bobPreference[i]);
                i++;
            }
        }

        SECTION("Test if interests was stored", "[interests]")
        {
            CHECK(bob.getInterestTable().numberOfInterests() == 3);
            std::string personInterests[] = { "sprit", "sport", "kaffe" };

            size_t i = 0;
            for (auto interest : bob.getInterestTable().getList())
            {
                REQUIRE(interest == personInterests[i]);
                i++;
            }
        }
    }

    SECTION("Test << operator overload")
    {
        std::string bobExampleLine("0;bob;23;m;male,female;mat,film,sport\n");
        std::string majaExampleLine("1;maja;30;f;male;sport,mat,film\n");

        std::stringstream bobLine;
        bobLine << bob;

        std::stringstream majaLine;
        majaLine << maja;

        REQUIRE(bobLine.str() == bobExampleLine);
        REQUIRE(majaLine.str() == majaExampleLine);
    }
}

