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

    }
}