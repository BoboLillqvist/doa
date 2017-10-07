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

        // Auto generated
        public override bool Equals(object obj)
        {
            var table = obj as InterestTable;
            return table != null &&
                   EqualityComparer<LinkedList<string>>.Default.Equals(List, table.List);
        }

        public override int GetHashCode()
        {
            return -2004394551 + EqualityComparer<LinkedList<string>>.Default.GetHashCode(List);
        }

        // Operator overloading
        public static bool operator == (InterestTable lhs, InterestTable rhs)
        {
            // Flag
            bool foundCommon = false;

            foreach (var thisInterest in lhs.List)
            {
                foreach (var otherInterest in rhs.List)
                    if (thisInterest == otherInterest)
                        foundCommon = true;

                if (!foundCommon)
                    return false;

                // Reset flag
                foundCommon = false;
            }

            return false;
        }

        public static bool operator != (InterestTable rhs, InterestTable lhs)
        {
            return rhs != lhs;
        }
    }
}
