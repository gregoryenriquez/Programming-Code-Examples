package com.cmpe137.shopping.app;

import android.app.Activity;
import android.content.ActivityNotFoundException;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class NewUserContinue extends Activity{
	private Button register;
	Toast toaster;
	public void onCreate(Bundle savedInstanceState) {
	    
        super.onCreate(savedInstanceState);
        setContentView(R.layout.newusercont);
        
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
		boolean check = true;
		
		if (check)
		{
			try {
				Intent register = new Intent(this, LoggedIn.class);
				startActivity(register);
			}
			catch (ActivityNotFoundException afne)
			{
				toaster.makeText(this, "Activity not found!", Toast.LENGTH_SHORT).show();
			}
		}
	}
}
