using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Application;

namespace Application.Tests
{
    [TestClass]
    public class TestInterestTable
    {

        [TestMethod]
        public void Add()
        {
            InterestTable it = new InterestTable();

            it.Add("SpoRT"); // +1
            it.Add("bio");   // +1
            it.Add("BIO");
            it.Add("");
            it.Add("Mat");   // +1
            int addedInterests = 3;

            Assert.AreEqual(addedInterests, it.NumberOfInterests());
        }

        [TestMethod()]
        public void NumberOfCommonInterestsTest()
        {
            Assert.Fail();
        }
    }
}