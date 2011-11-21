package com.cmpe137.shopping.app;

import android.app.Activity;
import android.content.ActivityNotFoundException;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class NewUser extends Activity{
	EditText streetName;
	EditText personName;
	EditText cityName;
	EditText zipCode;
	Button continueButton;
	AutoCompleteTextView stateName;
	Toast toaster;
	public void onCreate(Bundle savedInstanceState) {
		    
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.newuser);
	        streetName = (EditText) findViewById(R.id.StreetName);
	        streetName.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View v) {
					streetName.requestFocus();
				}
			});
	        personName = (EditText) findViewById(R.id.PersonName);
	        personName.setOnClickListener(new View.OnClickListener()
	        {
				@Override
				public void onClick(View v) {
					
					
				}
			});
	        
	        cityName = (EditText) findViewById(R.id.CityName);
	        zipCode = (EditText) findViewById(R.id.ZipCode);
	        
	        stateName = (AutoCompleteTextView) findViewById(R.id.State);
	        initState();
	        
	        stateName.setOnClickListener(new View.OnClickListener() 
	        {	
				@Override
				public void onClick(View v) {
					
					
				}
			});
	
	        continueButton = (Button) findViewById(R.id.NewUserContinue);
	        continueButton.setOnClickListener(new View.OnClickListener() 
	        {
				@Override
				public void onClick(View v) {
					startContinue();
				}
			});
	}
	
	protected void initState()
	{
		 ArrayAdapter<String> adapter = 
	        	new ArrayAdapter<String>(this, R.layout.list_item, STATES);
	        stateName.setAdapter(adapter);
	        stateName.setThreshold(1);
	}
	
	protected void startContinue()
	{
		if (personName.getText().toString().equals("")) 
		{
			toaster.makeText(this, "Enter your name", Toast.LENGTH_SHORT).show();
			return;
		}

		else if (streetName.getText().toString().equals(""))
		{
			toaster.makeText(this, "Enter a street name", Toast.LENGTH_SHORT).show();
			return;
		}
		else if (cityName.getText().toString().equals(""))
		{
			toaster.makeText(this, "Enter a city", Toast.LENGTH_SHORT).show();
			return;
		}
		else if (stateName.getText().toString().equals("")) 
		{
			toaster.makeText(this, "Enter a state", Toast.LENGTH_SHORT).show();
			return;
		}
		else if (zipCode.getText().toString().equals(""))
		{
			toaster.makeText(this, "Enter a zip code", Toast.LENGTH_SHORT).show();
			return;
		}
		
		try {
			Intent continueIntent = new Intent(this, NewUserContinue.class);
			continueIntent.putExtra("personNamePass", personName.getText().toString());
			continueIntent.putExtra("streetNamePass", streetName.getText().toString());
			continueIntent.putExtra("cityNamePass", cityName.getText().toString());
			continueIntent.putExtra("stateNamePass", stateName.getText().toString());
			continueIntent.putExtra("zipCodePass", zipCode.getText().toString());
			startActivity(continueIntent);
		}
		catch (ActivityNotFoundException afne)
		{
			toaster.makeText(this, "Activity not found!", Toast.LENGTH_SHORT).show();
		}
	}
	
	static final String[] STATES = new String[] 
	  {"AL", "AK", "AR", "CA", "CO", "CT", "DE", "FL", "GA", "HI", 
		"ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD", "MA",
		"MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY",
		"NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC", "SD", "TN", "TX",
		"UT", "VT", "VA", "WA", "WV", "WI", "WY"};
}
