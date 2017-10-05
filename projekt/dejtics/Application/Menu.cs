using System;
using System.Collections.Generic;
using System.Text;

namespace Application
{
    class Menu
    {
        public Date Dates { get; private set; } = new Date();
        public Menu() { }
        public void MenySnurra()
        {
            bool quitCheck = false;
            while (!quitCheck)
            {
                int switchCase = 0;
                //Knapptryck på Form1 ska välja switchcase

                switch (switchCase)
                {
                    case 1:
                        NewGirl();
                        break;
                    case 2:
                        NewBoy();
                        break;
                    case 3:
                        SaveToFile();
                        break;
                    case 4:
                        ReadFromFile();
                        break;
                    case 5:
                        Match();
                        break;
                    case 6:
                        PrintList();
                        break;
                    case 7:
                        quitCheck = true;
                        break;
                    default:
                        break;
                }
            }
        }

        public void Display() { }

        void NewGirl()
        {
            NewPerson('f');
            // New person
            // Add person to date.girllist
        }

        void NewBoy()
        {
            NewPerson('m');
            // New person
            // Add person to date.boylist
        }

        void NewPerson(char gender)
        {
            int id, age;
            string name, pref, interest;
            List<string> /*preferences,*/ interests;

            // Assign person id based on number of persons in list
            id = Dates.NumberOfPersons();

            // Get person info from user
            /*
            Console.WriteLine("Personens namn: ");
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
            else if (gender == 'm')
                date.getBoysList().getList().push_front(person);

            // Print person
            std::cout << "Info om personen som lades till" << std::endl << std::endl;
            infoAboutPerson(person);
            */
        }

        void InfoAboutPerson(Person person)
        {
            /*
            bool firstPref = true, firstInterest = true;

            // Print info
            std::cout << std::endl
                      << "Person: " << std::endl << "======================" << std::endl
                      << "ID: " << std::setw(18) << person.getID() << std::endl
                      << "Namn: " << std::setw(16) << person.getName() << std::endl
                      << "Genus: " << std::setw(15) << person.getGender() << std::endl;

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
            */
        }

        void SaveToFile()
        {
            if (Dates.Boys.List.Count!=0)
                Dates.Boys.ListToFile("male.csv");
            if (Dates.Girls.List.Count != 0)
                Dates.Girls.ListToFile("female.csv");
        }

        void ReadFromFile()
        {
            // FIX: Inte två try-catch block?
            try
            {
                Dates.Boys.FileToList("male.csv");
            }
            catch (Exception e)
            {
                //e.what();
            }

            try
            {
                Dates.Girls.FileToList("female.csv");
            }
            catch (Exception e)
            {
                //e.what();
            }

        }

        //Kalla på personlist och eventuellt couplelist read metoder
        void PrintList()
        {
            //Avkommenterat pga cout
            /*
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
            */
        }

        public void Match()
        {
            Dates.Match();
        }
    }
}
