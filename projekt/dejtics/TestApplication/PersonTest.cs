using Application;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections.Generic;
using System;

namespace Application.Tests
{
    [TestClass()]
    public class PersonTest
    {
        [TestMethod()]
        public void InterestsToStringTest()
        {
            List<string> interests1 = new List<string>();
            interests1.Add("Sport");
            interests1.Add("Mat");
            interests1.Add("Fika");
            interests1.Add("Supa");

            // Create bob and add interests1
            Person bob = new Person();
            bob.AddToInterestTable(interests1);

            // Create mange and add an empty list
            List<string> interests2 = new List<string>();
            Person mange = new Person(0, 39, "mange", 'm', interests2);

            // Test bob
            string bobExpectedStr = "supa,fika,mat,sport";
            Assert.AreEqual(bobExpectedStr, bob.InterestsToString());

            // Test mange
            string expectedStr = "";
            Assert.AreEqual(expectedStr, mange.InterestsToString());
        }

    }
}