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

    }
}
