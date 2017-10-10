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
    public partial class Dejt : System.Windows.Forms.Form
    {
        public Date DateObj { get; private set; } = new Date();

        public Dejt()
        {
            InitializeComponent();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void loadBtn_Click(object sender, EventArgs e)
        {
            PersonList boys = new PersonList();
            PersonList girls = new PersonList();

            boys = DateObj.File.Read(true);
            girls = DateObj.File.Read(false);

            foreach (var boy in boys.GetList())
            {
                DateObj.Boys.Add(boy);
                personListBox.Items.Add(boy.Name + ", " + boy.InterestsToString());
            }

            foreach (var girl in girls.GetList())
            {
                DateObj.Girls.Add(girl);
                personListBox.Items.Add(girl.Name);
            }

        }

        private void matchBtn_Click(object sender, EventArgs e)
        {
            DateObj.Match();

            foreach (var couple in DateObj.Couples.List)
            {
                couplesListBox.Items.Add(couple.PersonA.Name + " <--> " + couple.PersonB.Name);
            }
        }

        private void saveBtn_Click(object sender, EventArgs e)
        {
            // Save boys file
            if (DateObj.Boys.ListToFile(true) && DateObj.Girls.ListToFile(false))
                MessageBox.Show("File saved!");
        }

        private void addNewPersonBtn_Click(object sender, EventArgs e)
        {
            FormAddPerson formAddPerson = new FormAddPerson(this);
            formAddPerson.Show();
        }
        public System.Windows.Forms.ListBox getPersonListBox()
        {
            return personListBox;
    }
    }
}
