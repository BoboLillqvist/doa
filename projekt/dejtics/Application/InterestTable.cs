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

        public int NumberOfCommonInterests(InterestTable otherList)
        {
            int commonCounter = 0;

            // Loop this persons interests
            foreach (var thisInterest in List)
                // Check if current interest is in the other persons interest table
                foreach (var otherInterest in otherList.List)
                    if (thisInterest == otherInterest)
                        commonCounter++;

            return commonCounter;
        }
    }
}
