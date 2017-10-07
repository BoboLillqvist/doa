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

        private string[] SplitOnComma(string str)
        {
            string[] values = str.Split(',');
            return values;
        }

        string GetFullFilepath(bool isMaleFile)
        {
            string filename = isMaleFile ? "male.csv" : "female.csv";

            // Get full file path
            string startupPath = Environment.CurrentDirectory;
            string filePath = startupPath + "\\" + filename;
            return filePath;
        }

    }
}
