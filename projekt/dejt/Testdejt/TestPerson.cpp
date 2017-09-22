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

    Person person1(1, "Bob", 'm', {'m', 'f'}, interests);
    Person person2(2, "Jens", 'm', { 'm', 'f' }, interests2);

    SECTION("Test person interest table")
    {
        REQUIRE(person1.getInterestTable() == person2.getInterestTable());
    }
}