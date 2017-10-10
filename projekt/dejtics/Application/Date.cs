using System;
using System.Collections.Generic;
namespace Application
{
    public class Date
    {
        public PersonList Boys { get; private set; } = new PersonList();
        public PersonList Girls { get; private set; } = new PersonList();
        public CoupleList Couples { get; private set; } = new CoupleList();
        public FileHandler File { get; private set; } = new FileHandler();

        public Date() { }

        public void Match()
        {
            int threshhold = 1;

            foreach (var it1 in Boys.List)
            {
                Person favorite = new Person();
                favorite = null;
                int bestMatch = 0, temp = 0;
                /*
                foreach (var it2 in Boys.List)
                    if (it1.ID != it2.ID)
                        Compatibility(threshhold, it1, it2, bestMatch, temp, favorite);
                */
                foreach (var it3 in Girls.List)
                    if (it1.ID != it3.ID)
                        Compatibility(threshhold, it1, it3, bestMatch, temp, ref favorite);

                if (favorite != null)
                    CreateCouple(it1, favorite);
            }
            /*
            foreach (var it4 in Girls.List)
            {
                Person favorite2 = null;
                int bestMatch2 = 0, temp2 = 0;

                foreach (var it5 in Girls.List)
                    if (it4.ID != it5.ID)
                        Compatibility(threshhold, it4, it5, bestMatch2, temp2, favorite2);

                if (favorite2 != null)
                    CreateCouple(it4, favorite2);
            }
            */
        }

        public void Compatibility(int threshhold, Person personA, Person personB, int bestMatch, int temp, ref Person favorite)
        {
            if ((CompareAge(personA, personB) /*&& ComparePreferences(personA, personB)*/))
            {
                temp = CompareInterests(personA, personB);
                if ((temp >= threshhold) && (temp > bestMatch))
                {
                    favorite = personB;
                    bestMatch = temp;
                }
            }
        }

        public void CreateCouple(Person personA, Person personB)
        {
            bool alreadyInCouple = false;

            foreach (var itc in Couples.List)
            {
                if ((personA.ID == itc.PersonA.ID) || (personB.ID == itc.PersonB.ID) ||
                    (personA.ID == itc.PersonB.ID) || (personB.ID == itc.PersonA.ID))
                {
                    alreadyInCouple = true;
                }
            }

            if (!alreadyInCouple)
            {
                Couple couple1 = new Couple(personA, personB);
                Couples.Add(couple1);
            }
        }

        public bool CompareAge(Person personA, Person personB)
        {
            if (personB.Age > personA.Age)
                if ((((personB.Age) / 2) + 7) > personA.Age)
                    return false;

            if (personB.Age < personA.Age)
                if ((((personB.Age) * 2) - 7) < personA.Age)
                    return false;

            if (personA.Age > personB.Age)
                if ((((personA.Age) / 2) + 7) > personB.Age)
                    return false;

            if (personA.Age < personB.Age)
                if ((((personA.Age) * 2) - 7) < personB.Age)
                    return false;

            return true;
        }

        /*
        bool ComparePreferences(Person personA, Person personB) 
        {

            //Ta den forsta personens preference. Ar den samma av samma gender som preferensen? Kolla sedan om detsamma ar sant for den andra.
            bool matchAtoB = false, matchBtoA = false;
            foreach (var it1 in personA.Preferences)
            {
                if ((it1 == "female") && (personB.Gender == 'f'))
                    matchAtoB = true;
                if ((it1 == "male") && (personB.Gender == 'm'))
                    matchAtoB = true;
            }
            foreach (var it2 in personB.Preferences)
            {
                if ((it2 == "female") && (personA.Gender == 'f'))
                    matchBtoA = true;
                if ((it2 == "male") && (personA.Gender == 'm'))
                    matchBtoA = true;
            }
            if (matchAtoB && matchBtoA)
                return true;
            else
                return false;
                
        }
        */
        public int CompareInterests(Person personA, Person personB)
        {
            return (personA.InterestsTable.NumberOfCommonInterests(personB.InterestsTable));
        }

        public int NumberOfCouples()
        {
            return Couples.List.Count;
        }

        public int NumberOfPersons()
        {
            return (Boys.List.Count + Girls.List.Count);
        }
    }
}
