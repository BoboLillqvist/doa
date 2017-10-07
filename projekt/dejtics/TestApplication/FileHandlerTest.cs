using Microsoft.VisualStudio.TestTools.UnitTesting;
using Application;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace Application.Tests
{
    [TestClass()]
    public class FileHandlerTest
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

        [TestMethod()]
        public void WriteTest()
        {
            bool isMaleFile = true;
            Assert.IsTrue(personList.ListToFile(isMaleFile));
        }

        [TestMethod()]
        public void ReadTest()
        {
            PersonList persons = new PersonList();
            FileHandler file = new FileHandler();

            bool isMaleFile = true;
            persons = file.Read(isMaleFile);

            // Test if right number of persons was read
            int expectedNumPersons = 2;
            Assert.AreEqual(expectedNumPersons, persons.NumPersons());

            // Get persons
            Person bob = persons.List.ElementAt(0);
            Person kenneth = persons.List.ElementAt(1);

            // Test Bob
            Assert.AreEqual(0, bob.ID);
            Assert.AreEqual(22, bob.Age);
            Assert.AreEqual("bob", bob.Name);
            Assert.AreEqual('m', bob.Gender);
            Assert.IsTrue(bob.InterestsTable.GetList().ElementAt(0).Equals("sport"));
            Assert.IsTrue(bob.InterestsTable.GetList().ElementAt(1).Equals("mat"));
            Assert.IsTrue(bob.InterestsTable.GetList().ElementAt(2).Equals("fika"));
            Assert.IsTrue(bob.InterestsTable.GetList().ElementAt(3).Equals("supa"));

            // Test Kenneth
            Assert.AreEqual(1, kenneth.ID);
            Assert.AreEqual(43, kenneth.Age);
            Assert.AreEqual("kenneth", kenneth.Name);
            Assert.AreEqual('m', kenneth.Gender);
            Assert.IsTrue(kenneth.InterestsTable.GetList().ElementAt(0).Equals("handboll"));
            Assert.IsTrue(kenneth.InterestsTable.GetList().ElementAt(1).Equals("vvs-tekniker"));
            Assert.IsTrue(kenneth.InterestsTable.GetList().ElementAt(2).Equals("iron maiden"));
            Assert.IsTrue(kenneth.InterestsTable.GetList().ElementAt(3).Equals("katter"));
       }
    }
}