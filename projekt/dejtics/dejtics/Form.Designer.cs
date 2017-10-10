namespace dejtics
{
    partial class Dejt
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.addNewPersonBtn = new System.Windows.Forms.Button();
            this.matchBtn = new System.Windows.Forms.Button();
            this.saveBtn = new System.Windows.Forms.Button();
            this.loadBtn = new System.Windows.Forms.Button();
            this.personListBox = new System.Windows.Forms.ListBox();
            this.personLable = new System.Windows.Forms.Label();
            this.couplesListBox = new System.Windows.Forms.ListBox();
            this.couplesLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // addNewPersonBtn
            // 
            this.addNewPersonBtn.Location = new System.Drawing.Point(13, 13);
            this.addNewPersonBtn.Name = "addNewPersonBtn";
            this.addNewPersonBtn.Size = new System.Drawing.Size(107, 23);
            this.addNewPersonBtn.TabIndex = 0;
            this.addNewPersonBtn.Text = "+ Add new person";
            this.addNewPersonBtn.UseVisualStyleBackColor = true;
            // 
            // matchBtn
            // 
            this.matchBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.matchBtn.Location = new System.Drawing.Point(343, 8);
            this.matchBtn.Name = "matchBtn";
            this.matchBtn.Size = new System.Drawing.Size(81, 33);
            this.matchBtn.TabIndex = 1;
            this.matchBtn.Text = "Match!";
            this.matchBtn.UseVisualStyleBackColor = true;
            this.matchBtn.Click += new System.EventHandler(this.matchBtn_Click);
            // 
            // saveBtn
            // 
            this.saveBtn.Location = new System.Drawing.Point(697, 13);
            this.saveBtn.Name = "saveBtn";
            this.saveBtn.Size = new System.Drawing.Size(75, 23);
            this.saveBtn.TabIndex = 2;
            this.saveBtn.Text = "Save";
            this.saveBtn.UseVisualStyleBackColor = true;
            this.saveBtn.Click += new System.EventHandler(this.saveBtn_Click);
            // 
            // loadBtn
            // 
            this.loadBtn.Location = new System.Drawing.Point(616, 13);
            this.loadBtn.Name = "loadBtn";
            this.loadBtn.Size = new System.Drawing.Size(75, 23);
            this.loadBtn.TabIndex = 3;
            this.loadBtn.Text = "Load";
            this.loadBtn.UseVisualStyleBackColor = true;
            this.loadBtn.Click += new System.EventHandler(this.loadBtn_Click);
            // 
            // personListBox
            // 
            this.personListBox.FormattingEnabled = true;
            this.personListBox.Location = new System.Drawing.Point(13, 81);
            this.personListBox.Name = "personListBox";
            this.personListBox.Size = new System.Drawing.Size(376, 459);
            this.personListBox.TabIndex = 4;
            this.personListBox.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // personLable
            // 
            this.personLable.AutoSize = true;
            this.personLable.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.personLable.Location = new System.Drawing.Point(10, 62);
            this.personLable.Name = "personLable";
            this.personLable.Size = new System.Drawing.Size(52, 13);
            this.personLable.TabIndex = 5;
            this.personLable.Text = "Persons";
            this.personLable.Click += new System.EventHandler(this.label1_Click);
            // 
            // couplesListBox
            // 
            this.couplesListBox.FormattingEnabled = true;
            this.couplesListBox.Location = new System.Drawing.Point(396, 81);
            this.couplesListBox.Name = "couplesListBox";
            this.couplesListBox.Size = new System.Drawing.Size(376, 459);
            this.couplesListBox.TabIndex = 6;
            // 
            // couplesLabel
            // 
            this.couplesLabel.AutoSize = true;
            this.couplesLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.couplesLabel.Location = new System.Drawing.Point(393, 62);
            this.couplesLabel.Name = "couplesLabel";
            this.couplesLabel.Size = new System.Drawing.Size(52, 13);
            this.couplesLabel.TabIndex = 7;
            this.couplesLabel.Text = "Couples";
            // 
            // Dejt
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 561);
            this.Controls.Add(this.couplesLabel);
            this.Controls.Add(this.couplesListBox);
            this.Controls.Add(this.personLable);
            this.Controls.Add(this.personListBox);
            this.Controls.Add(this.loadBtn);
            this.Controls.Add(this.saveBtn);
            this.Controls.Add(this.matchBtn);
            this.Controls.Add(this.addNewPersonBtn);
            this.Name = "Dejt";
            this.Text = "Form";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button addNewPersonBtn;
        private System.Windows.Forms.Button matchBtn;
        private System.Windows.Forms.Button saveBtn;
        private System.Windows.Forms.Button loadBtn;
        private System.Windows.Forms.ListBox personListBox;
        private System.Windows.Forms.Label personLable;
        private System.Windows.Forms.ListBox couplesListBox;
        private System.Windows.Forms.Label couplesLabel;
    }
}

