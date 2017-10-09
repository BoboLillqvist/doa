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

        private void matchBtn_Click(object sender, EventArgs e)
        {
            DateObj.Match();

            foreach (var couple in DateObj.Couples.List)
            {
                couplesListBox.Items.Add(couple.PersonA.Name + " <--> " + couple.PersonB.Name);
            }
        }
    }
}
