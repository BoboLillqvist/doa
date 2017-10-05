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


        public void Add(Person person)
        {
            List.AddFirst(person);
        }

        public void FileToList(string filename)
        {

        }

        public void ListToFile(string filename)
        {

        }

        public int NumPersons()
        {
            return List.Count;
        }
    }
}
