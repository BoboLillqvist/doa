using System;
using System.Collections.Generic;

namespace Application
{
    public class InterestTable
    {
        // Datamembers
        private LinkedList<string> List = new LinkedList<string>();

        // Constructor
        public InterestTable() { }

        // Getters
        public LinkedList<string> GetList()
        {
            return List;
        }

        // Methods
        public void Add(string interest)
        {
            interest = interest.ToLower();

            if (!List.Contains(interest) && interest != "")
                List.AddFirst(interest);
        }

        public int NumberOfInterests()
        {
            return List.Count;
        }

    }
}
