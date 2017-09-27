#include "catch.hpp"
#include "../dejt/Date.h"
#include <vector> //look at me vector
#include <iostream>
#include <fstream>

TEST_CASE("Test Date Class")
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

	std::vector<std::string> interests5;
	interests5.push_back("päron");
	interests5.push_back("cider");
	interests5.push_back("misär");

    Person person1(0, 32, "Bob", 'm', { "female" }, interests);
    Person person2(1, 22, "Klara", 'f', { "male" }, interests2);
    Person person3(2, 49, "Babsan", 'f', { "female" }, interests3);
    Person person4(3, 18, "Jemenia", 'f', { "female" }, interests4);
    Person person5(4, 88, "Jamalia", 'f', { "male" }, interests5);

	Couple couple1(person1, person2);
	Couple couple2;
	couple2.setPersonA(person3);
	couple2.setPersonB(person4);
	CoupleList couplelist1;
	couplelist1.add(couple1);
	couplelist1.add(couple2);
	PersonList girls;
	girls.getList().push_front(person5);
	Date date;
	date.getCouplesList().getList() = couplelist1.getList();
	date.getGirlsList().getList() = girls.getList();
	SECTION("Test NumberOfCouples")
	{
		REQUIRE(date.numberOfCouples() == 2);
	}

	SECTION("Test number of Persons")
	{
		REQUIRE(date.numberOfPersons() == 5);
	}

}