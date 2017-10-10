using System;
using Application;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace dejtics
{
    public partial class FormAddPerson : Form
    {
        public Dejt varDejt;
        public FormAddPerson(Dejt inDejt)
        {
            InitializeComponent();
            varDejt = inDejt;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void AcceptBtn_Click(object sender, EventArgs e)
        {
            
            int ID= varDejt.DateObj.NumberOfPersons();
            string Name = NameTextBox.Text.ToLower();
            int Age = Int32.Parse(AgeTextBox.Text);
            char Gender = Char.ToLower(GenderTextBox.Text[0]);

            string[] Interests = FileHandler.SplitOnNewLine(InterestsTextBox.Text.ToLower());
            List<string> listOfInterests = new List<string>();
            foreach (var interest in Interests)
                listOfInterests.Add(interest);
            Person newPerson = new Person(ID,Age,Name,Gender,listOfInterests);
            if (Gender == 'm')
            {
                varDejt.DateObj.Boys.Add(newPerson);
                varDejt.getPersonListBox().Items.Add(newPerson);
            }
                
            else
            {
                varDejt.DateObj.Girls.Add(newPerson);
                varDejt.getPersonListBox().Items.Add(newPerson);
            }
            Close();
        }

        private void CancelBtn_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
