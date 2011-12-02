package com.cmpe137.shopping.app;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class Update extends Activity{
	EditText name, streetName, cityName, stateName, 
			zipCode, email, newpassword, oldpassword;
	Button update;
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.update);
		
		name = (EditText)findViewById(R.id.Name);
		streetName = (EditText) findViewById(R.id.StreetName);
		cityName = (EditText) findViewById(R.id.CityName);
		zipCode = (EditText) findViewById(R.id.ZipCode);
		email = (EditText) findViewById(R.id.Email);
		newpassword = (EditText) findViewById(R.id.Email);
		oldpassword = (EditText) findViewById(R.id.OldPassword);
		
		update = (Button)findViewById(R.id.UpdateConfirm);
		
		update.setOnClickListener(new View.OnClickListener() 
		{
			
			@Override
			public void onClick(View v) {
				update();
			}
		});
	}
	public void update()
	{
		finish();
	}
}
