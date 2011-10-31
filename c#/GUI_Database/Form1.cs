using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace Lab2
{
    public partial class WindowEnterData : Form
    {
        SqlConnection myConnection;
       
        public WindowEnterData()
        {
            System.Console.Write("HI");
            initializeDatabase();
            InitializeComponent();
            txtBoxLast.Text = "Last Name";
            txtBoxFirst.Text = "First Name";
            txtBoxCity.Text = "City";
            txtBoxPhone.Text = "Phone Number";
            txtBoxStreet.Text = "Street Address";
            txtBoxZip.Text = "Zip Code";
            initComboBox();
            comboBoxState.SelectedIndex = 0;
            loadExistingData();
           
        }

        private void comboBoxState_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void WindowEnterData_Activated(object sender, EventArgs e)
        {
            txtBoxLast.Focus();
        }

        private void txtBoxLast_Leave(object sender, EventArgs e)
        {
            //txtBoxFirst.TabIndex = 0;
        }

        private void txtBoxFirst_Leave(object sender, EventArgs e)
        {
           
        }

        private void txtBoxStreet_Leave(object sender, EventArgs e)
        {
           
        }

        private void txtBoxCity_Leave(object sender, EventArgs e)
        {     
           // comboBoxState.Focus();
        }

        private void comboBoxState_Leave(object sender, EventArgs e)
        {
           // txtBoxZip.Focus();
        }

        private void txtBoxZip_Leave(object sender, EventArgs e)
        {
           // txtBoxPhone.Focus();
        }

        private void txtBoxPhone_Leave(object sender, EventArgs e)
        {
           // bttnSubmit.Focus();
        }

        private void txtBoxPhone_TextChanged(object sender, EventArgs e)
        {

        }


        /*
         * Initializes values into the drop down combo box for states
         */
        private void initComboBox()
        {
            comboBoxState.Items.Add("AL");
            comboBoxState.Items.Add("AK");
            comboBoxState.Items.Add("AZ");
            comboBoxState.Items.Add("AR");
            comboBoxState.Items.Add("CA");
            comboBoxState.Items.Add("CO");
            comboBoxState.Items.Add("CT");
            comboBoxState.Items.Add("DE");
            comboBoxState.Items.Add("DC");
        }

        /*
         * 'Submit' button on GUI
         * Inserts data into database, checks for insertion, if it succeeds adds to listbox
         */
        private void bttnSubmit_Click(object sender, EventArgs e)
        {
          

            // Construct a string sql command to insert a user into the database
            string insertEntry = "";
            
            insertEntry = string.Format("INSERT INTO Records(LastName, FirstName, Address, City, State, Phone, Zip)" +
                                        "VALUES('{0}', '{1}', '{2}', '{3}', '{4}', '{5}', '{6}');", 
                                           txtBoxLast.Text, txtBoxFirst.Text, txtBoxStreet.Text, txtBoxCity.Text,
                                           comboBoxState.Text, txtBoxPhone.Text, txtBoxZip.Text);
            // Send sql string to server
            SqlCommand myCommand;
            myCommand = new SqlCommand();
            myCommand.CommandText = insertEntry;
            myCommand.Connection = myConnection;

            myCommand.BeginExecuteNonQuery();

            SqlCommand checkEntry;

            // Check to make sure insert succeeded and new customer is in database
            string checkString = string.Format("Select * From Records Where LastName = '{0}';", txtBoxLast.Text);
            checkEntry = new SqlCommand();
            checkEntry.CommandText = checkString;
            checkEntry.Connection = myConnection;
            SqlDataReader readThis;
            try 
            {
            readThis = checkEntry.ExecuteReader();

            string printThis = "";
            string tempLast = "", tempFirst = "", tempAddress = "", tempCity = "", tempState = "", tempPhone = "", tempZip = "";
            while (readThis.Read())
            {
                printThis += "Confirmed Inserted Entry: \n";
                printThis += readThis["LastName"].ToString() + "\n";
                printThis += readThis["FirstName"].ToString() + "\n";
                printThis += readThis["Address"].ToString() + "\n";
                printThis += readThis["City"].ToString() + "\n";
                printThis += readThis["State"].ToString() + "\n";
                printThis += readThis["Phone"].ToString() + "\n";
                printThis += readThis["Zip"].ToString();

                tempLast = readThis["LastName"].ToString();
                tempFirst = readThis["FirstName"].ToString();
                tempAddress = readThis["Address"].ToString();
                tempCity = readThis["City"].ToString();
                tempState = readThis["State"].ToString();
                tempPhone = readThis["Phone"].ToString();
                tempZip = readThis["Zip"].ToString();
            }

            // If new customer has successfully been placed into the database, add the customer to the listbox window
            bool exists = false;
            person temp;
            for (int i = 0; i < listBoxRecords.Items.Count; i++)
            {
                temp = (person)listBoxRecords.Items[i];
                if (tempLast == temp.getLast())
                    exists = true;
            }
            
            if (!exists)
                listBoxRecords.Items.Add(new person(tempLast, tempFirst, tempAddress, tempCity, tempState, tempPhone, tempZip));
            }
            catch (System.Data.SqlClient.SqlException ex)
            {
                System.Windows.Forms.MessageBox.Show("Database does not currently exist! Click <Create Database>!");
            }

            //System.Windows.Forms.MessageBox.Show(printThis);
           
        }

        private void listBoxRecords_SelectedIndexChanged(object sender, EventArgs e)
        {
           
        }

        /* Customer/perosn nested class
         * @override ToString() for display purposes
         */
        class person
        {
            public person(string last, string first, string address, string city, string state, string zip, string phone)
            {
                this.last = last;
                this.first = first;
                this.address = address;
                this.city = city;
                this.state = state;
                this.phone = phone;
                this.zip = zip;
            }

            public string getLast()
            {
                return last;
            }

            public override string ToString()
            {
                string temp;

                temp = last + ", " + first + " \t\t\n" +
                       address + "\n" + city + ", " + state + " " + zip +
                       "\n" + phone;

                return temp;
            }

            
            private string last, first, address, city, state, zip, phone;
        }

        private void listBoxRecords_MouseEnter(object sender, EventArgs e)
        {
         
        }

        private void listBoxRecords_DragOver(object sender, DragEventArgs e)
        {

        }


        /* 
         * Remove a customer from the database
         */
        private void bttnDestroy_MouseClick(object sender, MouseEventArgs e)
        {
            string destroyEntry = "";
            string tempLast = "";

            // Save Last Name value of customer selected on the listbox to delete
            if (listBoxRecords.SelectedIndex < listBoxRecords.Items.Count && listBoxRecords.SelectedIndex > 0)
            {
                person temp = (person)listBoxRecords.Items[listBoxRecords.SelectedIndex];
                tempLast = temp.getLast();
            }
          
                

                //System.Windows.Forms.MessageBox.Show(temp.ToString());

                // Construct the sql command string to delete the customer from the database
                destroyEntry = string.Format("DELETE FROM Records WHERE LastName = '{0}';", tempLast);

                SqlCommand myCommand;
                myCommand = new SqlCommand();
                myCommand.CommandText = destroyEntry;
                myCommand.Connection = myConnection;
           

            // If the removal succeeds, also remove the customer element from the listbox
            try
            {
                myCommand.BeginExecuteNonQuery();

                if (listBoxRecords.Items.Count != 0)
                {
                    listBoxRecords.Items.Remove(listBoxRecords.SelectedItem);
                }
                 
            }
            catch
            {

            }
        }

        private void WindowEnterData_Load(object sender, EventArgs e)
        {

        }

        private void toolTipListBoxSelected_Popup(object sender, PopupEventArgs e)
        {
         
        }


        private void listBoxRecords_MouseHover(object sender, EventArgs e)
        {
           
        }

        private void listBoxRecords_MouseMove(object sender, MouseEventArgs e)
        {
            /*
            if (sender is ListBox)
            {

                ListBox listBox = (ListBox)sender;
                Point point = new Point(e.X, e.Y);
                int hoverIndex = listBox.IndexFromPoint(point);
                if (hoverIndex >= 0 && hoverIndex < listBox.Items.Count)
                {
                    toolTipListBoxSelected.SetToolTip(listBox, listBox.Items[hoverIndex].ToString());
                }
            }    
            */
        }

        private void initializeDatabase()
        {
            SqlConnectionStringBuilder bldr = new SqlConnectionStringBuilder();
            bldr.DataSource = "GREG-HP\\SQLEXPRESS1";  //Put your server or server\instance name here.  Likely YourComputerName\SQLExpress
            bldr.InitialCatalog = "cmpe137lab2";  //The database on the server that you want to connect to.
            bldr.IntegratedSecurity = true;
            bldr.AsynchronousProcessing = true;
            bldr.MultipleActiveResultSets = true;

            myConnection = new SqlConnection(bldr.ConnectionString);
            try
            {
                myConnection.Open();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Failed to connect to database");
            }

            string temp = "Connection Properties: " + myConnection.ConnectionString +
                            "\n\nThe database is: " + myConnection.Database +
                            "\n\nThe server source is: " + myConnection.DataSource +
                            "\n\nConnection State: " + myConnection.State.ToString() ;
            MessageBox.Show(temp);
            
            
        }

        private void txtBoxLast_MouseEnter(object sender, EventArgs e)
        {

        }

        private void WindowEnterData_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {

                myConnection.Close();
            }
            catch
            {
            }
        }
       

        private void bttnClearDatabase_Click(object sender, EventArgs e)
        {
            string destroyTable = "DROP TABLE Records;";
            SqlCommand myCommand;
            myCommand = new SqlCommand();
            myCommand.CommandText = destroyTable;
            myCommand.Connection = myConnection;

            
                myCommand.BeginExecuteNonQuery();
            
            while (listBoxRecords.Items.Count != 0)
            {
                listBoxRecords.Items.RemoveAt(0);
            }


        }

        private void bttnCreateDatabase_Click(object sender, EventArgs e)
        {
            string createTable = "CREATE TABLE Records " +
                                "(" +
                                "LastName  VARCHAR(20) PRIMARY KEY," +
                                "FirstName VARCHAR(20), " +
                                "Address   VARCHAR(30), " +
                                "City      VARCHAR(20), " +
                                "State     VARCHAR(20), " +
                                "Phone     VARCHAR(20), " +
                                "Zip       VARCHAR(20) " +
                                ");";
            SqlCommand myCommand;
            myCommand = new SqlCommand();
            myCommand.CommandText = createTable;
            myCommand.Connection = myConnection;

            myCommand.BeginExecuteNonQuery();
        }

        private void bttnDisplayDatabase_Click(object sender, EventArgs e)
        {

            SqlCommand checkEntry;
            string checkString = "Select * From Records;";
            checkEntry = new SqlCommand();
            checkEntry.CommandText = checkString;
            checkEntry.Connection = myConnection;
            SqlDataReader readThis;
            string printThis = "";
            int index = 0;
            
            try
            {
                readThis = checkEntry.ExecuteReader();

                
                //            string tempLast = "", tempFirst = "", tempAddress = "", tempCity = "", tempState = "", tempPhone = "", tempZip = "";
                while (readThis.Read())
                {
                    printThis += "Entry No. " + index++ + "\n";
                    printThis += readThis["LastName"].ToString() + "\t";
                    printThis += readThis["FirstName"].ToString() + "\t";
                    printThis += readThis["Phone"].ToString() + "\n";
                    printThis += readThis["Address"].ToString() + "\t";
                    printThis += readThis["City"].ToString() + ", ";
                    printThis += readThis["State"].ToString() + "\t\t"; 
                    printThis += readThis["Zip"].ToString() + "\n\n";
                    ;
                }
            }
            catch
            {
            }
            System.Windows.Forms.MessageBox.Show(printThis);
           
        }

        private void listBoxRecords_MouseClick(object sender, MouseEventArgs e)
        {
            if (sender is ListBox)
            {

                ListBox listBox = (ListBox)sender;
                Point point = new Point(e.X, e.Y);
                int hoverIndex = listBox.IndexFromPoint(point);
                if (hoverIndex >= 0 && hoverIndex < listBox.Items.Count)
                {
                    toolTipListBoxSelected.SetToolTip(listBox, listBox.Items[hoverIndex].ToString());
                }
            }    
        }

        private void loadExistingData()
        {
            SqlCommand checkEntry;

            string checkString = "Select * From Records;";
            checkEntry = new SqlCommand();
            checkEntry.CommandText = checkString;
            checkEntry.Connection = myConnection;
            SqlDataReader readThis;
            
            
            string tempLast = "", tempFirst = "", tempAddress = "", tempCity = "", tempState = "", tempPhone = "", tempZip = "";

            try
            {
                readThis = checkEntry.ExecuteReader();


               
                while (readThis.Read())
                {
                    
                    tempLast = readThis["LastName"].ToString();
                    tempFirst= readThis["FirstName"].ToString();
                    tempAddress = readThis["Address"].ToString();
                    tempCity = readThis["City"].ToString();
                    tempState = readThis["State"].ToString();
                    tempPhone = readThis["Phone"].ToString();
                    tempZip = readThis["Zip"].ToString();

                    listBoxRecords.Items.Add(new person(tempLast, tempFirst, tempAddress, tempCity, tempState, tempPhone, tempZip));
                }
            }
            catch
            {
            }
        }

        private void bttnUpdate_Click(object sender, EventArgs e)
        {
            string updateEntry = "";

            updateEntry = string.Format("UPDATE Records " +
                                        "SET FirstName = '{1}', Address = '{2}', " + 
                                        "City = '{3}', State = '{4}', Phone = '{5}', Zip = '{6}' " +
                                        "WHERE LastName = '{0}';",
                                           txtBoxLast.Text, txtBoxFirst.Text, txtBoxStreet.Text, txtBoxCity.Text,
                                           comboBoxState.Text, txtBoxPhone.Text, txtBoxZip.Text);
            //System.Windows.Forms.MessageBox.Show(updateEntry);
            SqlCommand myCommand;
            myCommand = new SqlCommand();
            myCommand.CommandText = updateEntry;
            myCommand.Connection = myConnection;

            myCommand.BeginExecuteNonQuery();

            SqlCommand checkEntry;

            string checkString = string.Format("Select * From Records Where LastName = '{0}';", txtBoxLast.Text);
            checkEntry = new SqlCommand();
            checkEntry.CommandText = checkString;
            checkEntry.Connection = myConnection;
            SqlDataReader readThis;
            try
            {
                readThis = checkEntry.ExecuteReader();

                string printThis = "";
                string tempLast = "", tempFirst = "", tempAddress = "", tempCity = "", tempState = "", tempPhone = "", tempZip = "";
                while (readThis.Read())
                {
                    printThis += "Confirmed Changed Entry: \n";
                    printThis += readThis["LastName"].ToString() + "\n";
                    printThis += readThis["FirstName"].ToString() + "\n";
                    printThis += readThis["Address"].ToString() + "\n";
                    printThis += readThis["City"].ToString() + "\n";
                    printThis += readThis["State"].ToString() + "\n";
                    printThis += readThis["Phone"].ToString() + "\n";
                    printThis += readThis["Zip"].ToString();

                    tempLast = readThis["LastName"].ToString();
                    tempFirst = readThis["FirstName"].ToString();
                    tempAddress = readThis["Address"].ToString();
                    tempCity = readThis["City"].ToString();
                    tempState = readThis["State"].ToString();
                    tempPhone = readThis["Phone"].ToString();
                    tempZip = readThis["Zip"].ToString();
                }
                int indexFound = -1;
                person temp;
                for (int i = 0; i < listBoxRecords.Items.Count; i++)
                {
                    temp = (person)listBoxRecords.Items[i];
                    if (tempLast == temp.getLast())
                        indexFound = i;
                }

                if (indexFound != -1)
                    listBoxRecords.Items.RemoveAt(indexFound);
                    listBoxRecords.Items.Add(new person(tempLast, tempFirst, tempAddress, tempCity, tempState, tempPhone, tempZip));
            }
            catch (System.Data.SqlClient.SqlException ex)
            {
                System.Windows.Forms.MessageBox.Show("Database does not currently exist! Click <Create Database>!");
            }

            //System.Windows.Forms.MessageBox.Show(printThis);
        }

    }
}
