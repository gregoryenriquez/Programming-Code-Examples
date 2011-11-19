package com.cmpe137.shopping.app;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class LogIn extends Activity{
	Button logIn;
	TextView forgotPw;
	Toast toaster;
	LogIn loginscreen = this;
	
	public void onCreate(Bundle savedInstanceState) {
	    
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
				toaster.makeText(loginscreen, "...jump to pw recovery", Toast.LENGTH_LONG).show();
			}
		});
	}
	public void startLogin()
    {
    	Intent logIn = new Intent(this, LoggedIn.class);
    	startActivity(logIn);
    }
	
}
