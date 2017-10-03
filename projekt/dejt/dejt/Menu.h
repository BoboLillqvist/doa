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
				printList();
				break;
			case 7: 
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
		std::cout << "6. Print list" << std::endl;
		std::cout << "7. Quit" << std::endl;
	}

	void newGirl()
	{
		newPerson('f');
		system("pause");
		// New person
		// Add person to date.girllist
	}

	void newBoy()
	{
		newPerson('m');
		system("pause");
		// New person
		// Add person to date.girllist
	}

	void newPerson (char gender)
	{
		size_t id, age;
        std::string name, pref, interest;
        std::vector<std::string> preferences, interests;

        // Assign person id based on number of persons in list
		id = date.numberOfPersons();

        // Get person info from user
        std::cout << "Personens namn: "; getchar(); std::getline(std::cin, name);
		std::cout << "Personens ålder: "; std::cin >> age;

        // Get preferences from user
		std::cout << "Vad är personens preferenser?"
                  << "(skriv vilka sorter genus hos partnern personen är intresserad av, en eller flera.)"
            << std::endl << "Tryck enter två gånger i rad för att avsluta" << std::endl; getchar();

		while (std::getline(std::cin, pref))
		{
			bool inList = false;
			if (pref == "")
				break;
            
            // Convert preference to lowercase
			std::transform(pref.begin(), pref.end(), pref.begin(), tolower);

			// Check if interest already in list
			for (auto thisPreference : preferences)
				if (thisPreference == pref)
					inList = true;

            // Add preference
			if (!inList)
				preferences.push_back(pref);
		}

        // Get interests from user
		std::cout << "Vad är personens intressen?" << std::endl
                  << "Tryck enter två gånger i rad för att avlusta" << std::endl;

		while (std::getline(std::cin, interest))
		{
			bool inList = false;
			if (interest == "")
				break;

            // Convert interest to lowercase
			std::transform(interest.begin(), interest.end(), interest.begin(), tolower);

			// Check if interest already in list
			for (auto thisInterest : interests)
				if (thisInterest == interest)
					inList = true;

			if (!inList)
				interests.push_back(interest);
		}

        // Create person
		Person person(id, age, name, gender, preferences, interests);

        // Add to list
		if (gender == 'f')
			date.getGirlsList().getList().push_front(person);
		else if (gender=='m')
			date.getBoysList().getList().push_front(person);

        // Print person
		std::cout << "Info om personen som lades till" << std::endl << std::endl;
		infoAboutPerson(person);
	}

	void infoAboutPerson(Person& person)
	{
		bool firstPref = true, firstInterest = true;
		for (auto pref : person.getPreferences())
			pref;

        // Print info
        std::cout << std::endl
                  << "Person: " << std::endl     << "======================" << std::endl
                  << "ID: "     << std::setw(18) << person.getID()           << std::endl
                  << "Namn: "   << std::setw(16) << person.getName()         << std::endl
                  << "Genus: "  << std::setw(15) << person.getGender()       << std::endl;

	    std::cout << "Preferencer: ";
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

		std::cout << std::endl << "Intressen: ";
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
        if (!date.getBoysList().getList().empty())
            date.getBoysList().listToFile("male.csv");

        if (!date.getGirlsList().getList().empty())
            date.getGirlsList().listToFile("female.csv");

		std::cout << std::endl<< "File saved!" << std::endl;
		system("pause");
	}

	void readFromFile()
	{
        // FIX: Inte två try-catch block?
        try
        {
            date.getBoysList().fileToList("male.csv");
        }
        catch (const std::exception& e)
        {
            e.what();
        }

        try
        {
            date.getGirlsList().fileToList("female.csv");
        }
        catch (const std::exception& e)
        {
            e.what();
        }

		std::cout << std::endl<< "File read!" << std::endl;
		system("pause");
		//Kalla på personlist och eventuellt couplelist read metoder
	}

    void printList()
    {
        // TODO: Gör massa metoder

        std::cout << std::endl;
        std::cout << "------ Boys --------" << std::endl;
        for (auto boy : date.getBoysList().getList())
        {
            std::cout << "[" << boy.getID() << "]" << " " << boy.getName() << ", "
                      << "prefers: " << boy.preferencesToString() << ", "
                      << "interests: " << boy.interestsToString() << std::endl;
        }

        std::cout << std::endl;
        std::cout << "------- Girls --------" << std::endl;

        for (auto girl : date.getGirlsList().getList())
        {
            std::cout << "[" << girl.getID() << "]" << " " << girl.getName() << ", "
                      << "prefers: " << girl.preferencesToString() << ", "
                      << "interests: " << girl.interestsToString() << std::endl;
        }

        std::cout << std::endl;
        std::cout << "------- Couples --------" << std::endl;
        for (auto couple : date.getCouplesList().getList())
        {
            std::cout << couple.getPersonA().getName() << " <--> " << couple.getPersonB().getName() << std::endl;
        }

        system("pause");
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