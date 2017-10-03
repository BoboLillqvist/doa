#include "catch.hpp"
#include "../dejt/Menu.h"
#include <vector> 
#include <iostream>
#include <fstream>

TEST_CASE("Test Menu class")
{
	Menu menu;
	//menu.menySnurra();
	std::vector<std::string> interests3;
	interests3.push_back("guld");
	interests3.push_back("pengar");
	interests3.push_back("promenader");
	Person person3(2, 49, "Babsan", 'f', { "female" }, interests3);
	SECTION("Test menu infoABoutPerson()")
	{
		menu.infoAboutPerson(person3);
	}
	SECTION("Test menu add person")
	{
		//menu.newBoy();
		
		//menu.infoAboutPerson(*menu.getDate().getBoysList().getList().begin());
	}
	//system("pause");

}
