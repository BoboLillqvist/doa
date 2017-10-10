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
            // Person info
            int id      = varDejt.DateObj.NumberOfPersons();
            string name = NameTextBox.Text.ToLower();
            int age     = Int32.Parse(AgeTextBox.Text);
            char gender = Char.ToLower(GenderTextBox.Text[0]);

            // Person interests
            string[] Interests = FileHandler.SplitOnNewLine(InterestsTextBox.Text.ToLower().Replace("\r", ""));
            List<string> listOfInterests = new List<string>();

            // Add interest
            foreach (var interest in Interests)
                listOfInterests.Add(interest);

            // Create new person
            Person newPerson = new Person(id, age, name, gender, listOfInterests);

            // Add person to list
            if (gender == 'm')
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
