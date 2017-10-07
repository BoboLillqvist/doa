using System;
using System.IO;
using System.Text;
using System.Collections.Generic;

namespace Application
{
    public class PersonList
    {
        public LinkedList<Person> List { get; private set; } = new LinkedList<Person>();

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

        public bool ListToFile(bool isMaleFile)
        {
            FileHandler file = new FileHandler();
            return file.Write(this, isMaleFile);
        }

        public int NumPersons()
        {
            return List.Count;
        }
    }
}
