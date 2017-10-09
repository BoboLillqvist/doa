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
    }
}
