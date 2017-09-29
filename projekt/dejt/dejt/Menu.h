#pragma once
#include "Date.h"

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
		std::cout << "---------" << std::endl;
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
		std::cout << std::endl<<"Girl added!" << std::endl;
		system("pause");
		//New person
		//Add person to date.girllist
	}

	void newBoy()
	{
		std::cout << std::endl<<"Boy added!" << std::endl;
		system("pause");
		//New person
		//Add person to date.girllist
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
};