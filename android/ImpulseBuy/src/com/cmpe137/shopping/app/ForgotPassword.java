package com.cmpe137.shopping.app;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class ForgotPassword extends Activity{
	Toast toaster;
	ForgotPassword forgotpasswordscreen;
	Button resetButton;
	boolean flag;
	EditText emailBox;
	public void onCreate(Bundle savedInstanceBundle)
	{
		super.onCreate(savedInstanceBundle);
		setContentView(R.layout.forgotpassword);
		
		resetButton = (Button) findViewById(R.id.ResetPassword);
		resetButton.setOnClickListener(new View.OnClickListener() 
		{
			@Override
			public void onClick(View v) {
				toaster.makeText(ForgotPassword.this, "A new random password has been sent to your email", Toast.LENGTH_SHORT).show();
			}
		});
		
		flag = false;
		Intent tempIntent = getIntent();
		emailBox = (EditText) findViewById(R.id.Email);
		if (!flag)
			emailBox.setText(tempIntent.getStringExtra("email"));
		
	}
	
	@Override
	protected void onResume()
	{
		super.onResume();
		flag = true;
	}
	

}
