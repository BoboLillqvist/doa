using System;
using System.Text;
using System.Collections.Generic;
using System.IO;

namespace Application
{
    public class FileHandler
    {
        private string[] SplitOnSemicolon(string str)
        {
            string[] values = str.Split(';');
            return values;
        }

    }
}
