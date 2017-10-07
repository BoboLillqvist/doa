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
        [TestMethod()]
        public void WriteTest()
        {
            bool isMaleFile = true;
            Assert.IsTrue(personList.ListToFile(isMaleFile));
        }

    }
}