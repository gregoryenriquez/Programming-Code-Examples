namespace better_calculator
{
    partial class Calculator
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
            this.bttnAddition = new System.Windows.Forms.Button();
            this.bttnSubtract = new System.Windows.Forms.Button();
            this.bttnMultiply = new System.Windows.Forms.Button();
            this.bttnDivide = new System.Windows.Forms.Button();
            this.bttnEquals = new System.Windows.Forms.Button();
            this.bttnFactorial = new System.Windows.Forms.Button();
            this.txtBoxNumber = new System.Windows.Forms.TextBox();
            this.bttnClear = new System.Windows.Forms.Button();
            this.lblFirstNumber = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // bttnAddition
            // 
            this.bttnAddition.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bttnAddition.Location = new System.Drawing.Point(12, 38);
            this.bttnAddition.Name = "bttnAddition";
            this.bttnAddition.Size = new System.Drawing.Size(56, 54);
            this.bttnAddition.TabIndex = 0;
            this.bttnAddition.Text = "+";
            this.bttnAddition.UseVisualStyleBackColor = true;
            this.bttnAddition.Click += new System.EventHandler(this.bttnAddition_Click);
            // 
            // bttnSubtract
            // 
            this.bttnSubtract.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F);
            this.bttnSubtract.Location = new System.Drawing.Point(74, 38);
            this.bttnSubtract.Name = "bttnSubtract";
            this.bttnSubtract.Size = new System.Drawing.Size(54, 54);
            this.bttnSubtract.TabIndex = 1;
            this.bttnSubtract.Text = "-";
            this.bttnSubtract.UseVisualStyleBackColor = true;
            this.bttnSubtract.Click += new System.EventHandler(this.bttnSubtract_Click);
            // 
            // bttnMultiply
            // 
            this.bttnMultiply.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F);
            this.bttnMultiply.Location = new System.Drawing.Point(12, 98);
            this.bttnMultiply.Name = "bttnMultiply";
            this.bttnMultiply.Size = new System.Drawing.Size(56, 54);
            this.bttnMultiply.TabIndex = 2;
            this.bttnMultiply.Text = "*";
            this.bttnMultiply.UseVisualStyleBackColor = true;
            this.bttnMultiply.Click += new System.EventHandler(this.bttnMultiply_Click);
            // 
            // bttnDivide
            // 
            this.bttnDivide.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F);
            this.bttnDivide.Location = new System.Drawing.Point(75, 99);
            this.bttnDivide.Name = "bttnDivide";
            this.bttnDivide.Size = new System.Drawing.Size(53, 53);
            this.bttnDivide.TabIndex = 3;
            this.bttnDivide.Text = "/";
            this.bttnDivide.UseVisualStyleBackColor = true;
            this.bttnDivide.Click += new System.EventHandler(this.bttnDivide_Click);
            // 
            // bttnEquals
            // 
            this.bttnEquals.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bttnEquals.Location = new System.Drawing.Point(74, 158);
            this.bttnEquals.Name = "bttnEquals";
            this.bttnEquals.Size = new System.Drawing.Size(128, 53);
            this.bttnEquals.TabIndex = 4;
            this.bttnEquals.Text = "=";
            this.bttnEquals.UseVisualStyleBackColor = true;
            this.bttnEquals.Click += new System.EventHandler(this.bttnEquals_Click);
            // 
            // bttnFactorial
            // 
            this.bttnFactorial.Font = new System.Drawing.Font("Microsoft Sans Serif", 48F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bttnFactorial.Location = new System.Drawing.Point(134, 38);
            this.bttnFactorial.Name = "bttnFactorial";
            this.bttnFactorial.Size = new System.Drawing.Size(68, 114);
            this.bttnFactorial.TabIndex = 5;
            this.bttnFactorial.Text = "!";
            this.bttnFactorial.UseVisualStyleBackColor = true;
            this.bttnFactorial.Click += new System.EventHandler(this.bttnFactorial_Click);
            // 
            // txtBoxNumber
            // 
            this.txtBoxNumber.Location = new System.Drawing.Point(12, 12);
            this.txtBoxNumber.Name = "txtBoxNumber";
            this.txtBoxNumber.Size = new System.Drawing.Size(190, 20);
            this.txtBoxNumber.TabIndex = 6;
            this.txtBoxNumber.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.txtBoxNumber.MouseClick += new System.Windows.Forms.MouseEventHandler(this.txtBoxNumber_MouseClick);
            this.txtBoxNumber.TextChanged += new System.EventHandler(this.txtBoxNumber_TextChanged);
            // 
            // bttnClear
            // 
            this.bttnClear.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bttnClear.Location = new System.Drawing.Point(12, 159);
            this.bttnClear.Name = "bttnClear";
            this.bttnClear.Size = new System.Drawing.Size(56, 50);
            this.bttnClear.TabIndex = 7;
            this.bttnClear.Text = "CLR";
            this.bttnClear.UseVisualStyleBackColor = true;
            this.bttnClear.Click += new System.EventHandler(this.bttnClear_Click);
            // 
            // lblFirstNumber
            // 
            this.lblFirstNumber.AutoSize = true;
            this.lblFirstNumber.Location = new System.Drawing.Point(37, 15);
            this.lblFirstNumber.Name = "lblFirstNumber";
            this.lblFirstNumber.Size = new System.Drawing.Size(0, 13);
            this.lblFirstNumber.TabIndex = 8;
            // 
            // Calculator
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(212, 221);
            this.Controls.Add(this.lblFirstNumber);
            this.Controls.Add(this.bttnClear);
            this.Controls.Add(this.txtBoxNumber);
            this.Controls.Add(this.bttnFactorial);
            this.Controls.Add(this.bttnEquals);
            this.Controls.Add(this.bttnDivide);
            this.Controls.Add(this.bttnMultiply);
            this.Controls.Add(this.bttnSubtract);
            this.Controls.Add(this.bttnAddition);
            this.MaximizeBox = false;
            this.Name = "Calculator";
            this.Text = "MEGA CALC";
            this.Activated += new System.EventHandler(this.Calculator_Activated);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Calculator_FormClosing);
            this.Load += new System.EventHandler(this.Calculator_Load);
            
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button bttnAddition;
        private System.Windows.Forms.Button bttnSubtract;
        private System.Windows.Forms.Button bttnMultiply;
        private System.Windows.Forms.Button bttnDivide;
        private System.Windows.Forms.Button bttnEquals;
        private System.Windows.Forms.Button bttnFactorial;
        private System.Windows.Forms.TextBox txtBoxNumber;
        private System.Windows.Forms.Button bttnClear;
        private System.Windows.Forms.Label lblFirstNumber;
    }
}

