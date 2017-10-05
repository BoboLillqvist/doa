using System;
using System.Collections.Generic;

namespace Application
{
    class PersonList
    {
        public LinkedList<Person> List { get; private set; }

        public PersonList()
        {

        }

        public LinkedList<Person> GetList()
        {
            return List;
        }


        void Add(Person person)
        {
            List.AddFirst(person);
        }

        void FileToList()
        {

        }

        void ListToFile()
        {

        }

        int NumPersons()
        {
            return List.Count;
        }
    }
}
