using System;
using System.Collections.Generic;
using System.Text;

namespace Application
{
    public class Person
    {
        // Datamembers
        public int ID { get; private set; }
        public int Age { get; private set; }
        public string Name { get; private set; }
        public char Gender { get; private set; }

        public InterestTable InterestsTable { get; private set; } = new InterestTable();

        // Constructors
        public Person() {}

        public Person(int id, int age, string name, char gender, List<string> interests)
        {
            ID = id;
            Age = age;
            Name = name;
            Gender = gender;
            AddToInterestTable(interests);
        }

        // Methods
        public void AddToInterestTable(List<string> interests)
        {
            foreach (var interest in interests)
                InterestsTable.Add(interest);
        }

        public string InterestsToString()
        {
            StringBuilder str = new StringBuilder();

            foreach (var interest in InterestsTable.GetList())
            {
                str.Append(interest);
                if (interest != InterestsTable.GetList().Last.Value)
                    str.Append(",");
            }

            return str.ToString();
        }

        override public string ToString()
        {
            StringBuilder str = new StringBuilder();
            str.Append(ID + ",");
            str.Append(Age + ",");
            str.Append(Name.ToLower() + ",");
            str.Append(Gender + ";");
            str.Append(InterestsToString() + ";");
            str.Append("\n");

            return str.ToString();
        }
    }
}
