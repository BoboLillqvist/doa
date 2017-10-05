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

    }
}
