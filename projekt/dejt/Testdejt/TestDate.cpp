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
	Person person6(5, 30, "Baliou", 'm', { "female" }, interests5);
	Person person7(6, 31, "Karlolina", 'f', { "male" }, interests5);

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
	date.getBoysList().getList().push_front(person6);
	
	date.getCouplesList().getList() = couplelist1.getList();
	date.getGirlsList().getList() = girls.getList();
	date.getGirlsList().getList().push_front(person7);
	SECTION("Test NumberOfCouples")
	{
		REQUIRE(date.numberOfCouples() == 2);
	}

	SECTION("Test number of Persons")
	{
		REQUIRE(date.numberOfPersons() == 7);
	}
	SECTION("Test compare age")
	{
		REQUIRE(date.compareAge(person2, person4));
		REQUIRE_FALSE(date.compareAge(person1, person2));
		REQUIRE_FALSE(date.compareAge(person2, person1));
		REQUIRE(date.compareAge(person1, person1));
		REQUIRE_FALSE(date.compareAge(person4, person5));
		REQUIRE_FALSE(date.compareAge(person5, person4));
	}
	SECTION("Test preferences")
	{
		REQUIRE(date.comparePreferences(person1, person2));
		REQUIRE(date.comparePreferences(person2, person1));
		REQUIRE(date.comparePreferences(person3, person4));
		REQUIRE_FALSE(date.comparePreferences(person1, person3));
	}

	SECTION("Test create couple metoden")
	{
		Date date2;
		date2.createCouple(person4, person5);
		REQUIRE(date2.getCouplesList().getList().begin()->getPersonA().getAge() == 18);
		REQUIRE(date2.getCouplesList().getList().begin()->getPersonB().getAge() == 88);
	}
	SECTION("Test create couple metoden med pekare")
	{
		Date date3;
		Person* favorite2 = &person5;
		date3.createCouple(person4, *favorite2);
		REQUIRE(date3.getCouplesList().getList().begin()->getPersonA().getAge() == 18);
		REQUIRE(date3.getCouplesList().getList().begin()->getPersonB().getAge() == 88);
	}
	SECTION("Test compatibility")
	{
		Person* favorite = nullptr;
		int bestmatch = 0, temp = 0;
		date.compatibility(1, person6, person7, bestmatch, temp, favorite);
		REQUIRE(bestmatch == 3);
		REQUIRE(favorite->getInterestTable() == person7.getInterestTable());
	}
	SECTION("Test create couple metoden med compatibility metoden och pekare")
	{
		Date date4;
		Person* favorite3 = nullptr;
		int bestmatch = 0, temp = 0;
		date4.compatibility(1, person6, person7, bestmatch, temp, favorite3);
		date4.createCouple(person6, *favorite3);
		REQUIRE(date4.getCouplesList().getList().begin()->getPersonA().getAge() == 30);
		REQUIRE(date4.getCouplesList().getList().begin()->getPersonB().getAge() == 31);
	}

}
TEST_CASE("Test date match")
{
	Date date;
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
	Person person6(5, 30, "Baliou", 'm', { "female" }, interests5);
	Person person7(6, 31, "Karlolina", 'f', { "male" }, interests5);

	PersonList boys, girls;
	boys.getList().push_front(person1);
	boys.getList().push_front(person6);
	girls.getList().push_front(person2);
	girls.getList().push_front(person3);
	girls.getList().push_front(person4);
	girls.getList().push_front(person5);
	girls.getList().push_front(person7);
	date.getBoysList().getList() = boys.getList();
	date.getGirlsList().getList() = girls.getList();

	SECTION("Test match")
	{
		date.match();
		REQUIRE(date.numberOfCouples() == 1);
		REQUIRE(date.numberOfPersons() == 9); //7 personer i listorna, 2 dubbellagras i couple så 9 totalt.
		REQUIRE(date.getCouplesList().getList().begin()->getPersonA().getAge() == 30); //Get age är 3435973836...? 
		REQUIRE(date.getCouplesList().getList().begin()->getPersonA().getID() == 5); //ID också?
		REQUIRE(date.getCouplesList().getList().begin()->getPersonB().getAge() == 31);
		REQUIRE(date.getCouplesList().getList().begin()->getPersonB().getInterestTable() == person7.getInterestTable());
		REQUIRE(date.getCouplesList().getList().begin()->getPersonB().getInterestTable() == date.getCouplesList().getList().begin()->getPersonB().getInterestTable());
	}
}