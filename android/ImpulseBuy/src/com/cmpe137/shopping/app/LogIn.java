package com.cmpe137.shopping.app;

import java.util.ArrayList;

import android.app.Activity;
import android.content.ActivityNotFoundException;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class LogIn extends Activity{
	Button logIn;
	TextView forgotPw;
	Toast toaster;
	LogIn loginscreen = this;
	String[] usernames;
	String[] passwords;
	EditText email;
	EditText password;
	String currentuser = "";
	public void onCreate(Bundle savedInstanceState) {
		usernames = getResources().getStringArray(R.array.loginNames);
		passwords = getResources().getStringArray(R.array.loginPasswords);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.login);
        
        logIn = (Button) findViewById(R.id.ButtonLogIn);
        logIn.setOnClickListener(new View.OnClickListener() 
        {
			@Override
			public void onClick(View v) {
				startLogin();
			}
		});   
        forgotPw = (TextView) findViewById(R.id.ForgotPassword);
        forgotPw.setOnClickListener(new View.OnClickListener() 
        {	
			@Override
			public void onClick(View v) {
				startForgotPassword();
			}
		});
        email = (EditText)findViewById(R.id.Email);
        password = (EditText) findViewById(R.id.Password);
       
	}
	
	public void startForgotPassword()
	{
		try
		{
			Intent forgotpw = new Intent(this, ForgotPassword.class);
			forgotpw.putExtra("email", email.getText().toString());
			startActivity(forgotpw);
		}
		catch (ActivityNotFoundException afne)
		{
			toaster.makeText(this, "Activity not found!", Toast.LENGTH_SHORT).show();
		}
	}
	
	public void startLogin()
    {
		int index = -1;
		for (int i = 0; i < usernames.length; i++)
		{
			if (usernames[i].equals(email.getText().toString()))
			{	index = i;
				currentuser=usernames[i];
			}
		}
		boolean passwordCheck = false;
		if (index == -1)
		{
			toaster.makeText(loginscreen, "Invalid Email", Toast.LENGTH_LONG).show();
			return;
		}
		else if (password.getText().toString().equals(passwords[index]))
			passwordCheck = true;
		
		if (!passwordCheck && index != -1)
		{
			//toaster.makeText(loginscreen, "" + email.getText() + password.getText(), Toast.LENGTH_LONG).show();
			toaster.makeText(loginscreen, "Invalid Email/Password!", Toast.LENGTH_LONG).show();
			return;
		}
		try {
	    	Intent logIn = new Intent(this, LoggedIn.class);
	    	logIn.putExtra("useremail", currentuser);
	    	startActivity(logIn);
		}
		catch (ActivityNotFoundException afne)
		{
			toaster.makeText(this, "Activity not found!", Toast.LENGTH_SHORT).show();
		}
    }
	
}
