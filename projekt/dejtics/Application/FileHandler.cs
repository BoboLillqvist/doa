using System;
using System.Text;
using System.Collections.Generic;
using System.IO;

namespace Application
{
    public class FileHandler
    {
        private string[] SplitOnSemicolon(string str)
        {
            string[] values = str.Split(';');
            return values;
        }

        private string[] SplitOnComma(string str)
        {
            string[] values = str.Split(',');
            return values;
        }

        public static string[] SplitOnNewLine(string str)
        {
            string[] values = str.Split('\n');
            return values;
        }

        string GetFullFilepath(bool isMaleFile)
        {
            string filename = isMaleFile ? "male.csv" : "female.csv";

            // Get full file path
            string startupPath = Environment.CurrentDirectory;
            string filePath = startupPath + "\\" + filename;
            return filePath;
        }

        public bool Write(PersonList personList, bool isMaleFile)
        {
            string filePath = GetFullFilepath(isMaleFile);

            StringBuilder output = new StringBuilder();

            // Append each person to the line
            foreach (var person in personList.GetList())
                output.Append(person.ToString());

            try
            {
                using (StreamWriter writer = new StreamWriter(filePath, false))
                {
                    writer.Write(output);
                }
                return true;
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error:" + ex.Message);
                return false;
            }
        }

        public PersonList Read(bool isMaleFile)
        {
            PersonList personList = new PersonList();
            List<string> interestList = new List<string>();

            string[] semicolonValues, userInfo, interests;
            string line, userInfoStr, interestsStr;

            using (StreamReader reader = new StreamReader(GetFullFilepath(isMaleFile)))
            {
                while ((line = reader.ReadLine()) != null)
                {
                    // Parse csv data
                    semicolonValues = SplitOnSemicolon(line);

                    // Separata user info from interests
                    userInfoStr = semicolonValues[0];
                    interestsStr = semicolonValues[1];

                    // Parse and store user info
                    userInfo = SplitOnComma(userInfoStr);
                    int id = Int32.Parse(userInfo[0]);
                    int age = Int32.Parse(userInfo[1]);
                    string name = userInfo[2];
                    char gender = Char.Parse(userInfo[3]);

                    // Parse and store interestrs from string
                    interests = SplitOnComma(interestsStr);
                    foreach (string interest in interests)
                        interestList.Add(interest);

                    // Store person
                    Person person = new Person(id, age, name, gender, interestList);
                    personList.Add(person);

                    interestList.Clear();
                }
            }
            return personList;
        }
    }
}
