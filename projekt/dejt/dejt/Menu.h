#pragma once
#include "Date.h"

//Kallar på date metoderna
//Menu körs i main där en menu skapas och menySnurran kallas på automatiskt.
class Menu
{
private:
	Date date;
public:
	Menu()
	{
		menySnurra();
	}

	void menySnurra()
	{
		//While
		display();
		//Switch
		//Case 1: Add new girl
		//Case 2: Add new boy
		//Case 3: Save to file
		//Case 4: Read from file
		//Case 5: Match
		// Case 6: Quit

	}
	void display()
	{
		//Vad som kommer upp på skärmen varje gång menysnurra körs
	}
	void newGirl()
	{
		//New person
		//Add person to date.girllist
	}

	void newBoy()
	{
		//New person
		//Add person to date.girllist
	}

	void saveToFile()
	{
		//Kalla på personlist och eventuellt couplelist save metoder
	}

	void readFromFile()
	{
		//Kalla på personlist och eventuellt couplelist read metoder
	}

	void match()
	{
		date.match();
	}
};