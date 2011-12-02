package com.cmpe137.shopping.app;

import android.app.Activity;
import android.content.ActivityNotFoundException;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class NewUserContinue extends Activity{
	private Button register;
	Toast toaster;
	String personName;
	String streetName;
	String cityName;
	String stateName;
	String zipCode;
	EditText personEmail;
	EditText personPassword;
	
	public void onCreate(Bundle savedInstanceState) {
	    
        super.onCreate(savedInstanceState);
        setContentView(R.layout.newusercont);
        
        Intent getData = getIntent();
        personName = getData.getStringExtra("personNamePass");
        streetName = getData.getStringExtra("streetNamePass");
        cityName = getData.getStringExtra("cityNamePass");
        stateName = getData.getStringExtra("stateNamePass");
        zipCode = getData.getStringExtra("zipCodePass");
        
        personEmail = (EditText) findViewById(R.id.PersonEmail);
        personPassword = (EditText) findViewById(R.id.PersonPassword);
        
        register = (Button)findViewById(R.id.Register);
        register.setOnClickListener(new View.OnClickListener() 
        {	
			@Override
			public void onClick(View v) {
				startRegister();
			}
		});
	}
	private void startRegister()
	{
		// check credentials, blah blah
		
		
		if (personEmail.getText().toString().equals(""))
		{
			toaster.makeText(this, "Enter an email", Toast.LENGTH_SHORT).show();
			return;
		}
		else if (personPassword.getText().toString().equals(""))
		{
			toaster.makeText(this, "Enter a password", Toast.LENGTH_SHORT).show();
			return;
		}	
		
		/**
		 * Reserved space to save person registration to database
		 */
		
		try {
			Intent register = new Intent(this, LoggedIn.class);
			register.putExtra("useremail", personEmail.getText().toString());
			startActivity(register);
		}
		catch (ActivityNotFoundException afne)
		{
			toaster.makeText(this, "Activity not found!", Toast.LENGTH_SHORT).show();
		}
		
	}
}
