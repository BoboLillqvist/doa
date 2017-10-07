using Application;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections.Generic;
using System;

namespace Application.Tests
{
    [TestClass()]
    public class PersonListTest
    {
        PersonList personList = new PersonList();

        [TestInitialize]
        public void Initialize()
        {
            // Create Bob
            List<string> interests1 = new List<string> {
                "Sport", "Mat", "Fika", "Supa"
            };
            Person bob = new Person(0, 22, "Bob", 'm', interests1);

            // Create Kenneth
            List<string> interests2 = new List<string> {
                "Handboll", "VVS-tekniker", "Iron Maiden", "Katter"
            };
            Person kenneth = new Person(1, 43, "Kenneth", 'm', interests2);

            // Add to person list
            personList.Add(bob);
            personList.Add(kenneth);
        }
    }
}