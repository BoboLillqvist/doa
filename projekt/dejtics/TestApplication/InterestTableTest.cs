using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Application;

namespace Application.Tests
{
    [TestClass]
    public class InterestTableTest
    {
        InterestTable interestTable1 = new InterestTable();
        InterestTable interestTable2 = new InterestTable();

        [TestMethod]
        public void Add()
        {
            interestTable1.Add("SpoRT"); // +1
            interestTable1.Add("bio");   // +1
            interestTable1.Add("BIO");
            interestTable1.Add("");
            interestTable1.Add("Mat");   // +1
            int addedInterests = 3;

            Assert.AreEqual(addedInterests, interestTable1.NumberOfInterests());
        }

        [TestMethod()]
        public void NumberOfCommonInterestsTest()
        {
            interestTable1.Add("Sport");
            interestTable1.Add("");
            interestTable1.Add("Sprit");
            interestTable1.Add("Dans");

            interestTable2.Add("Vin");
            interestTable2.Add("Dans");
            interestTable2.Add("");
            interestTable2.Add("Sport");
            interestTable2.Add("Film");

            Assert.AreEqual(2, interestTable1.NumberOfCommonInterests(interestTable2));
        }
    }
}