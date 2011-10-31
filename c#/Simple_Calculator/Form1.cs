using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace better_calculator
{
    public partial class Calculator : Form
    {
        static double firstNumber;
        static double secondNumber;
        static char op;

        public Calculator()
        {
            InitializeComponent();
            txtBoxNumber.Text = "Enter a Number";

        }

        private void txtBoxNumber_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void bttnAddition_Click(object sender, EventArgs e)
        {
            if (!(txtBoxNumber.Text == "Enter a Number"))
            {
                getFirst(); // save first number from textbox
                txtBoxNumber.Text = "0";
                op = 'a'; // addition
                lblFirstNumber.Text = firstNumber + " +";
                txtBoxNumber.Focus();
            }
        }

        private void bttnSubtract_Click(object sender, EventArgs e)
        {
            if (!(txtBoxNumber.Text == "Enter a Number"))
            {
                getFirst();
                txtBoxNumber.Text = "0";
                op = 's';
                lblFirstNumber.Text = firstNumber + " -";
                txtBoxNumber.Focus();
            }
        }

        private void bttnFactorial_Click(object sender, EventArgs e)
        {
            if (!(txtBoxNumber.Text == "Enter a Number"))
            {
                getFirst();
                lblFirstNumber.Text = firstNumber + " !";
                op = 'f';
            }
        }

        private void bttnMultiply_Click(object sender, EventArgs e)
        {
            if (!(txtBoxNumber.Text == "Enter a Number"))
            {
                getFirst();
                txtBoxNumber.Text = "0";
                op = 'm';
                lblFirstNumber.Text = firstNumber + " *";
                txtBoxNumber.Focus();
            }
        }

        private void bttnDivide_Click(object sender, EventArgs e)
        {
            if (!(txtBoxNumber.Text == "Enter a Number"))
            {
                getFirst();
                txtBoxNumber.Text = "0";
                op = 'd';
                lblFirstNumber.Text = firstNumber + " /";
                txtBoxNumber.Focus();
            }
        }

        private void bttnEquals_Click(object sender, EventArgs e)
        {
            switch (op)
            {
                case 'a': // addition
                    getSecond();
                    txtBoxNumber.Text = "" + (firstNumber + secondNumber); //string
                    lblFirstNumber.Text = "";
                    break;
                case 's': // subtraction
                    getSecond();
                    txtBoxNumber.Text = "" + (firstNumber - secondNumber);
                    lblFirstNumber.Text = "";
                    break;
                case 'm': // multiply
                    getSecond();
                    txtBoxNumber.Text = "" + (firstNumber * secondNumber);
                    lblFirstNumber.Text = "";
                    break;
                case 'd': // divide
                    getSecond();
                    try
                    {
                        if (secondNumber == 0) throw new DivideByZeroException();
                        txtBoxNumber.Text = "" + (firstNumber / secondNumber);
                    }
                    catch (System.DivideByZeroException dbz)
                    {
                        txtBoxNumber.Text = "ERR: DIV BY ZERO!!!";
                    }
                    lblFirstNumber.Text = "";
                    break;
                case 'f': // factorial
                    if ((int)firstNumber < 0) firstNumber = -firstNumber;

                    int product1 = 1, count1 = (int)firstNumber;

                        for (int i = (int)firstNumber; i > 0; i--)
                        {
                            if (firstNumber == 0)
                            {
                                product1 = 0;
                                break;
                            }
                            product1 = product1*i;
                        }
                    this.txtBoxNumber.Text = "" + product1;
                    lblFirstNumber.Text = "";
                    break;
                default:
                    break;
            }

        }

        private void Calculator_Load(object sender, EventArgs e)
        {

        }

        private void bttnClear_Click(object sender, EventArgs e)
        {
            firstNumber = 0;
            secondNumber = 0;
            txtBoxNumber.Text = "0";
            op = 'c';
            lblFirstNumber.Text = "";
        }
        public void getSecond()
        {
            if (!(txtBoxNumber.Text == ""))
            try 
            {
                secondNumber = System.Convert.ToDouble(txtBoxNumber.Text);
            }
            catch
            {
                string stemp = txtBoxNumber.Text;
                for (int i = 0; i < stemp.Length; i++)
                {
                    if (char.IsLetter(stemp.ElementAt(i)))
                    {
                        stemp = stemp.Remove(i, 1);
                    }
                }
                txtBoxNumber.Text = stemp;
                getSecond();
            }
        }
        public void getFirst()
        {
            if (!(txtBoxNumber.Text == ""))
            try
            {
                firstNumber = System.Convert.ToDouble(txtBoxNumber.Text);
            }
            catch
            {
                string stemp = txtBoxNumber.Text;
                for (int i = 0; i < stemp.Length; i++)
                {
                    if (char.IsLetter(stemp.ElementAt(i)))
                    {
                        stemp = stemp.Remove(i, 1);
                    }
                }
                txtBoxNumber.Text = stemp;
                getFirst();
            }
           
        }

        private void txtBoxNumber_MouseClick(object sender, MouseEventArgs e)
        {
            if (txtBoxNumber.Text == "Enter a Number")
                txtBoxNumber.Text = "";
            if (txtBoxNumber.Text == "0") txtBoxNumber.Text = "";
            if (txtBoxNumber.Text == "ERR: DIV BY ZERO!!!") txtBoxNumber.Text = "";
        }

        private void Calculator_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult r;
            r = MessageBox.Show("Do you really really want to close?",
                                "MyApp",
                                MessageBoxButtons.YesNo,
                                MessageBoxIcon.Question,
                                MessageBoxDefaultButton.Button1);
            if (r == DialogResult.No)
                e.Cancel = true;
        }


        private void Calculator_Activated(object sender, EventArgs e)
        {
            txtBoxNumber.Focus();
        }
     
    }
}
