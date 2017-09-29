#pragma once
#include "Date.h"
#include <iomanip>

//Kallar på date metoderna
class Menu
{
private:
	Date date;
public:
	Menu()
	{

	}

	void menySnurra()
	{
		bool quitCheck = false;
		while (!quitCheck)
		{
			display();
			int switchCase = 0;
			std::cin >> switchCase;
			switch(switchCase)
			{
			case 1: 
				newGirl();
				break;
			case 2:
				newBoy();
				break;
			case 3:
				saveToFile();
				break;
			case 4: 
				readFromFile();
				break;
			case 5:
				match();
				break;
			case 6: 
				quitCheck = true;
				break;
			default:
				system("pause");
				break;

			}
			//Switch
			//Case 1: Add new girl
			//Case 2: Add new boy
			//Case 3: Save to file
			//Case 4: Read from file
			//Case 5: Match
			// Case 6: Quit
		}
	}
	void display()
	{
		system("clear");
		std::cout << "Main menu:"<<std::endl;
		std::cout << "---------------" << std::endl;
		std::cout << "1. Add new girl" << std::endl;
		std::cout << "2. Add new boy" << std::endl;
		std::cout << "3. Save to file" << std::endl;
		std::cout << "4. Read from file" << std::endl;
		std::cout << "5. Match couples" << std::endl;
		std::cout << "6. Quit" << std::endl;
		
		//Vad som kommer upp på skärmen varje gång menysnurra körs
	}
	void newGirl()
	{
		newPerson('f');
		system("pause");
		//New person
		//Add person to date.girllist
	}

	void newBoy()
	{
		newPerson('m');
		system("pause");
		//New person
		//Add person to date.girllist
	}
	void newPerson (char gender)
	{
		size_t id;
		size_t age;
		std::string name;
		std::vector<std::string> preferences; 
		std::string pref;
		std::vector<std::string> interests;
		std::string interest;

		std::cout << "Vad är personens namn?" << std::endl;
		getchar();
		std::getline(std::cin, name);
		std::cout << "Vad är personens ålder?" << std::endl;
		std::cin >> age;
		std::cout << "Vad är personens preferencer? (skriv vilka sorter genus hos partnern personen är intresserad av, en eller flera.)" << std::endl << "Tryck enter två gånger i rad för att avlusta" << std::endl;;
		getchar();
		while (std::getline(std::cin, pref))
		{
			if (pref == "")
				break;
			bool inList = false;
			std::transform(pref.begin(), pref.end(), pref.begin(), tolower);
			// Check if interest already in list
			for (auto thisPreference : preferences)
				if (thisPreference == pref)
					inList = true;

			if (!inList)
				preferences.push_back(pref);
		}

		std::cout << "Vad är personens intressen?"<< std::endl << "Tryck enter två gånger i rad för att avlusta" << std::endl;;
		getchar();
		while (std::getline(std::cin, interest))
		{
			if (interest == "")
				break;
			bool inList = false;
			std::transform(interest.begin(), interest.end(), interest.begin(), tolower);
			// Check if interest already in list
			for (auto thisInterest : interests)
				if (thisInterest == interest)
					inList = true;

			if (!inList)
				interests.push_back(interest);
		}
		id = date.numberOfPersons();
		Person person(id, age, name, gender, preferences, interests);
		if (gender == 'f')
			date.getGirlsList().getList().push_front(person);
		else if (gender=='m')
			date.getBoysList().getList().push_front(person);
		std::cout << "Info om personen som lades till" << std::endl << std::endl;
		infoAboutPerson(person);
	}
	void infoAboutPerson(Person& person)
	{
		bool firstPref = true,firstInterest=true;
		for(auto pref : person.getPreferences())
		{
			pref;
		}
		std::cout << std::endl <<
			"Person: " << std::endl << "======================" << std::endl <<
			"ID: " << std::setw(18) << person.getID() << std::endl <<
			"Namn: " << std::setw(16) << person.getName() << std::endl <<
			"Genus: " << std::setw(15) << person.getGender() << std::endl <<
			"Preferencer: ";
		for (auto pref : person.getPreferences())
		{
			if (firstPref)
			{
				std::cout << std::setw(9) << pref << std::endl;
				firstPref = false;
			}
			else
			{
				std::cout << std::setw(22) << pref << std::endl;
			}
		}
		std::cout <<std::endl<< "Intressen: ";
		for (auto interest : person.getInterestTable().getList())
		{
			
			if (firstInterest)
			{
				std::cout << std::setw(11) << interest << std::endl;
				firstInterest = false;
			}
			else
			{
				std::cout << std::setw(22) << interest << std::endl;
			}
		}
	}
	void saveToFile()
	{
		std::cout << std::endl<< "File saved!" << std::endl;
		system("pause");
		//Kalla på personlist och eventuellt couplelist save metoder
	}

	void readFromFile()
	{
		std::cout << std::endl<< "File read!" << std::endl;
		system("pause");
		//Kalla på personlist och eventuellt couplelist read metoder
	}

	void match()
	{
		date.match();
		std::cout << std::endl<< "Couples matched!" << std::endl;
		system("pause");
	}
	Date& getDate()
	{
		return date;
	}
};