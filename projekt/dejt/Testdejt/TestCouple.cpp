#include "catch.hpp"
#include "../dejt/Person.h"
#include "../dejt/Couple.h"
#include <vector>

TEST_CASE("Test Couple Class")
{
	std::vector<std::string> interests;
	interests.push_back("sport");
	interests.push_back("FILM");
	interests.push_back("Mat");

	std::vector<std::string> interests2;
	interests2.push_back("FILM");
	interests2.push_back("Mat");
	interests2.push_back("sport");

	std::vector<std::string> interests3;
	interests3.push_back("guld");
	interests3.push_back("pengar");
	interests3.push_back("promenader");

	std::vector<std::string> interests4;
	interests4.push_back("guld");
	interests4.push_back("plommon");
	interests4.push_back("promenader");

	Person person1(1, "Bob", 'm', "f", interests);
	Person person2(2, "Klara", 'f', "m", interests2);
	Person person3(1, "Babsan", 'f', "f", interests3);
	Person person4(2, "Jemenia", 'f', "f", interests4);
	Couple couple1(person1, person2);
	Couple couple2;
	couple2.setPersonA(person3);
	couple2.setPersonB(person4);

	SECTION("Test couple1 get")
	{
		REQUIRE(couple1.getPersonA().getInterestTable()==person1.getInterestTable());
		REQUIRE(couple1.getPersonB().getInterestTable() == person2.getInterestTable());
	}

	SECTION("Test couple2 get")
	{
		REQUIRE(couple2.getPersonA().getInterestTable() == person3.getInterestTable());
		REQUIRE(couple2.getPersonB().getInterestTable() == person4.getInterestTable());
	}
}