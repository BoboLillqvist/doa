#include "catch.hpp"
#include "../dejt/Person.h"
#include <vector>

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
        REQUIRE(person1.getInterestTable() == person2.getInterestTable());
    }
}