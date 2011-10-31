namespace Lab2
{
    partial class WindowEnterData
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
            this.components = new System.ComponentModel.Container();
            this.listBoxRecords = new System.Windows.Forms.ListBox();
            this.txtBoxLast = new System.Windows.Forms.TextBox();
            this.bttnSubmit = new System.Windows.Forms.Button();
            this.txtBoxFirst = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.txtBoxStreet = new System.Windows.Forms.TextBox();
            this.txtBoxCity = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.comboBoxState = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.txtBoxPhone = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.bttnDestroy = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.txtBoxZip = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.toolTipListBoxSelected = new System.Windows.Forms.ToolTip(this.components);
            this.bttnClearDatabase = new System.Windows.Forms.Button();
            this.bttnCreateDatabase = new System.Windows.Forms.Button();
            this.bttnDisplayDatabase = new System.Windows.Forms.Button();
            this.bttnUpdate = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // listBoxRecords
            // 
            this.listBoxRecords.FormattingEnabled = true;
            this.listBoxRecords.Location = new System.Drawing.Point(465, 38);
            this.listBoxRecords.Name = "listBoxRecords";
            this.listBoxRecords.Size = new System.Drawing.Size(120, 212);
            this.listBoxRecords.TabIndex = 13;
            this.listBoxRecords.MouseClick += new System.Windows.Forms.MouseEventHandler(this.listBoxRecords_MouseClick);
            this.listBoxRecords.SelectedIndexChanged += new System.EventHandler(this.listBoxRecords_SelectedIndexChanged);
            this.listBoxRecords.DragOver += new System.Windows.Forms.DragEventHandler(this.listBoxRecords_DragOver);
            this.listBoxRecords.MouseEnter += new System.EventHandler(this.listBoxRecords_MouseEnter);
            this.listBoxRecords.MouseHover += new System.EventHandler(this.listBoxRecords_MouseHover);
            this.listBoxRecords.MouseMove += new System.Windows.Forms.MouseEventHandler(this.listBoxRecords_MouseMove);
            // 
            // txtBoxLast
            // 
            this.txtBoxLast.Location = new System.Drawing.Point(54, 57);
            this.txtBoxLast.Name = "txtBoxLast";
            this.txtBoxLast.Size = new System.Drawing.Size(147, 20);
            this.txtBoxLast.TabIndex = 0;
            this.txtBoxLast.Leave += new System.EventHandler(this.txtBoxLast_Leave);
            this.txtBoxLast.MouseEnter += new System.EventHandler(this.txtBoxLast_MouseEnter);
            // 
            // bttnSubmit
            // 
            this.bttnSubmit.Location = new System.Drawing.Point(191, 177);
            this.bttnSubmit.Name = "bttnSubmit";
            this.bttnSubmit.Size = new System.Drawing.Size(75, 23);
            this.bttnSubmit.TabIndex = 7;
            this.bttnSubmit.Text = "Submit !";
            this.bttnSubmit.UseVisualStyleBackColor = true;
            this.bttnSubmit.Click += new System.EventHandler(this.bttnSubmit_Click);
            // 
            // txtBoxFirst
            // 
            this.txtBoxFirst.Location = new System.Drawing.Point(255, 57);
            this.txtBoxFirst.Name = "txtBoxFirst";
            this.txtBoxFirst.Size = new System.Drawing.Size(147, 20);
            this.txtBoxFirst.TabIndex = 1;
            this.txtBoxFirst.Leave += new System.EventHandler(this.txtBoxFirst_Leave);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 60);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(27, 13);
            this.label1.TabIndex = 100;
            this.label1.Text = "Last";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(207, 60);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(26, 13);
            this.label2.TabIndex = 100;
            this.label2.Text = "First";
            // 
            // txtBoxStreet
            // 
            this.txtBoxStreet.Location = new System.Drawing.Point(54, 100);
            this.txtBoxStreet.Name = "txtBoxStreet";
            this.txtBoxStreet.Size = new System.Drawing.Size(147, 20);
            this.txtBoxStreet.TabIndex = 2;
            this.txtBoxStreet.Leave += new System.EventHandler(this.txtBoxStreet_Leave);
            // 
            // txtBoxCity
            // 
            this.txtBoxCity.Location = new System.Drawing.Point(255, 100);
            this.txtBoxCity.Name = "txtBoxCity";
            this.txtBoxCity.Size = new System.Drawing.Size(147, 20);
            this.txtBoxCity.TabIndex = 3;
            this.txtBoxCity.Leave += new System.EventHandler(this.txtBoxCity_Leave);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 103);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(35, 13);
            this.label3.TabIndex = 100;
            this.label3.Text = "Street";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(207, 103);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(24, 13);
            this.label4.TabIndex = 100;
            this.label4.Text = "City";
            // 
            // comboBoxState
            // 
            this.comboBoxState.FormattingEnabled = true;
            this.comboBoxState.Location = new System.Drawing.Point(54, 141);
            this.comboBoxState.Name = "comboBoxState";
            this.comboBoxState.Size = new System.Drawing.Size(46, 21);
            this.comboBoxState.TabIndex = 4;
            this.comboBoxState.SelectedIndexChanged += new System.EventHandler(this.comboBoxState_SelectedIndexChanged);
            this.comboBoxState.Leave += new System.EventHandler(this.comboBoxState_Leave);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(12, 144);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(32, 13);
            this.label5.TabIndex = 100;
            this.label5.Text = "State";
            // 
            // txtBoxPhone
            // 
            this.txtBoxPhone.Location = new System.Drawing.Point(255, 141);
            this.txtBoxPhone.Name = "txtBoxPhone";
            this.txtBoxPhone.Size = new System.Drawing.Size(147, 20);
            this.txtBoxPhone.TabIndex = 6;
            this.txtBoxPhone.TextChanged += new System.EventHandler(this.txtBoxPhone_TextChanged);
            this.txtBoxPhone.Leave += new System.EventHandler(this.txtBoxPhone_Leave);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(207, 144);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(38, 13);
            this.label6.TabIndex = 100;
            this.label6.Text = "Phone";
            // 
            // bttnDestroy
            // 
            this.bttnDestroy.Location = new System.Drawing.Point(465, 256);
            this.bttnDestroy.Name = "bttnDestroy";
            this.bttnDestroy.Size = new System.Drawing.Size(120, 23);
            this.bttnDestroy.TabIndex = 12;
            this.bttnDestroy.Text = "Destroy !";
            this.bttnDestroy.UseVisualStyleBackColor = true;
            this.bttnDestroy.MouseClick += new System.Windows.Forms.MouseEventHandler(this.bttnDestroy_MouseClick);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(135, 12);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(208, 16);
            this.label7.TabIndex = 15;
            this.label7.Text = "Customer Records Database";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(462, 12);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(94, 13);
            this.label8.TabIndex = 14;
            this.label8.Text = "Customer Records";
            // 
            // txtBoxZip
            // 
            this.txtBoxZip.Location = new System.Drawing.Point(138, 141);
            this.txtBoxZip.Name = "txtBoxZip";
            this.txtBoxZip.Size = new System.Drawing.Size(63, 20);
            this.txtBoxZip.TabIndex = 5;
            this.txtBoxZip.Leave += new System.EventHandler(this.txtBoxZip_Leave);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(110, 144);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(22, 13);
            this.label9.TabIndex = 100;
            this.label9.Text = "Zip";
            // 
            // toolTipListBoxSelected
            // 
            this.toolTipListBoxSelected.AutoPopDelay = 5000;
            this.toolTipListBoxSelected.InitialDelay = 500;
            this.toolTipListBoxSelected.ReshowDelay = 10000;
            this.toolTipListBoxSelected.Popup += new System.Windows.Forms.PopupEventHandler(this.toolTipListBoxSelected_Popup);
            // 
            // bttnClearDatabase
            // 
            this.bttnClearDatabase.Location = new System.Drawing.Point(339, 256);
            this.bttnClearDatabase.Name = "bttnClearDatabase";
            this.bttnClearDatabase.Size = new System.Drawing.Size(120, 23);
            this.bttnClearDatabase.TabIndex = 11;
            this.bttnClearDatabase.Text = "Destroy Database!";
            this.bttnClearDatabase.UseVisualStyleBackColor = true;
            this.bttnClearDatabase.Click += new System.EventHandler(this.bttnClearDatabase_Click);
            // 
            // bttnCreateDatabase
            // 
            this.bttnCreateDatabase.Location = new System.Drawing.Point(339, 227);
            this.bttnCreateDatabase.Name = "bttnCreateDatabase";
            this.bttnCreateDatabase.Size = new System.Drawing.Size(120, 23);
            this.bttnCreateDatabase.TabIndex = 9;
            this.bttnCreateDatabase.Text = "Create Database";
            this.bttnCreateDatabase.UseVisualStyleBackColor = true;
            this.bttnCreateDatabase.Click += new System.EventHandler(this.bttnCreateDatabase_Click);
            // 
            // bttnDisplayDatabase
            // 
            this.bttnDisplayDatabase.Location = new System.Drawing.Point(213, 256);
            this.bttnDisplayDatabase.Name = "bttnDisplayDatabase";
            this.bttnDisplayDatabase.Size = new System.Drawing.Size(120, 23);
            this.bttnDisplayDatabase.TabIndex = 10;
            this.bttnDisplayDatabase.Text = "Display Database";
            this.bttnDisplayDatabase.UseVisualStyleBackColor = true;
            this.bttnDisplayDatabase.Click += new System.EventHandler(this.bttnDisplayDatabase_Click);
            // 
            // bttnUpdate
            // 
            this.bttnUpdate.Location = new System.Drawing.Point(15, 256);
            this.bttnUpdate.Name = "bttnUpdate";
            this.bttnUpdate.Size = new System.Drawing.Size(75, 23);
            this.bttnUpdate.TabIndex = 8;
            this.bttnUpdate.Text = "Update !";
            this.bttnUpdate.UseVisualStyleBackColor = true;
            this.bttnUpdate.Click += new System.EventHandler(this.bttnUpdate_Click);
            // 
            // WindowEnterData
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(597, 285);
            this.Controls.Add(this.bttnUpdate);
            this.Controls.Add(this.bttnDisplayDatabase);
            this.Controls.Add(this.bttnCreateDatabase);
            this.Controls.Add(this.bttnClearDatabase);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.txtBoxZip);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.bttnDestroy);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.txtBoxPhone);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.comboBoxState);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txtBoxCity);
            this.Controls.Add(this.txtBoxStreet);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtBoxFirst);
            this.Controls.Add(this.bttnSubmit);
            this.Controls.Add(this.txtBoxLast);
            this.Controls.Add(this.listBoxRecords);
            this.Name = "WindowEnterData";
            this.Text = "Customer Records Database";
            this.Activated += new System.EventHandler(this.WindowEnterData_Activated);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.WindowEnterData_FormClosing);
            this.Load += new System.EventHandler(this.WindowEnterData_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBoxRecords;
        private System.Windows.Forms.TextBox txtBoxLast;
        private System.Windows.Forms.Button bttnSubmit;
        private System.Windows.Forms.TextBox txtBoxFirst;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtBoxStreet;
        private System.Windows.Forms.TextBox txtBoxCity;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox comboBoxState;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtBoxPhone;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button bttnDestroy;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox txtBoxZip;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.ToolTip toolTipListBoxSelected;
        private System.Windows.Forms.Button bttnClearDatabase;
        private System.Windows.Forms.Button bttnCreateDatabase;
        private System.Windows.Forms.Button bttnDisplayDatabase;
        private System.Windows.Forms.Button bttnUpdate;
    }
}

