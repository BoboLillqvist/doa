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

    }
}
