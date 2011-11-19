package com.cmpe137.shopping.app;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.Button;
import android.widget.EditText;

public class NewUser extends Activity{
	EditText streetName;
	EditText personName;
	Button continueButton;
	AutoCompleteTextView state;
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
	        
	        state = (AutoCompleteTextView) findViewById(R.id.State);
	        initState();
	        
	        state.setOnClickListener(new View.OnClickListener() 
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
	        state.setAdapter(adapter);
	        state.setThreshold(1);
	}
	
	protected void startContinue()
	{
		Intent continueIntent = new Intent(this, NewUserContinue.class);
		startActivity(continueIntent);
	}
	
	static final String[] STATES = new String[] 
	  {"AL", "AK", "AR", "CA", "CO", "CT", "DE", "FL", "GA", "HI", 
		"ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD", "MA",
		"MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY",
		"NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC", "SD", "TN", "TX",
		"UT", "VT", "VA", "WA", "WV", "WI", "WY"};
}
