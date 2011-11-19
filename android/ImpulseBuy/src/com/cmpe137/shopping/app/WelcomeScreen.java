package com.cmpe137.shopping.app;

import java.util.ArrayList;

import android.app.Activity;
import android.content.ActivityNotFoundException;
import android.content.Intent;
import android.os.Bundle;
import android.speech.RecognizerIntent;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.Toast;

public class WelcomeScreen extends Activity{
	private static final int RECOGNIZER_EXAMPLE = 1001;
	private static final int QRSCANNER_EXAMPLE = 1003;
	private EditText searchBox;
	private Toast toaster;
	private WelcomeScreen welcome = this;
	public void onCreate(Bundle savedInstanceState) {
			
        super.onCreate(savedInstanceState);
        setContentView(R.layout.welcome);
        ImageButton speakButton = (ImageButton) findViewById(R.id.Speak);
        
        speakButton.setOnClickListener(new View.OnClickListener()
        {
			@Override
			public void onClick(View v) {
					// RecognizerIntent prompts for speech and returns text
				try
				{
					Intent intent = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);			
					intent.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM);
					intent.putExtra(RecognizerIntent.EXTRA_PROMPT, "Speak to search!");
					startActivityForResult(intent, RECOGNIZER_EXAMPLE);
				}
				catch (ActivityNotFoundException e)
				{
					toaster.makeText(welcome, "Speech Recognizer not found!\nInstall from Android Market", Toast.LENGTH_LONG).show();
				}
			}
		});
        
        searchBox = (EditText) findViewById(R.id.SearchBox);
        
        Button searchButton = (Button) findViewById(R.id.SearchButton);
        searchButton.setOnClickListener(new View.OnClickListener()
        {	
			@Override
			public void onClick(View v) {
				startSearch();
			}
		});
        
        Button qrButton = (Button) findViewById(R.id.QRButton);
        qrButton.setOnClickListener(new View.OnClickListener()
        {	
			@Override
			public void onClick(View v) {
				startQR();
			}
		});
       
        Button newUserButton = (Button) findViewById(R.id.NewUserButton);
        newUserButton.setOnClickListener(new View.OnClickListener()
        {	
			@Override
			public void onClick(View v) {
				startNewUser();
			}
		});
	      
	        Button loginButton = (Button) findViewById(R.id.LoginButton);
	        loginButton.setOnClickListener(new View.OnClickListener()
	        {	
				@Override
				public void onClick(View v) {
					startLogin();
				}
			});
	    }
		
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data)
	{
		if (requestCode==RECOGNIZER_EXAMPLE && resultCode==RESULT_OK)
		{
			ArrayList<String> result = data.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS);
			if (!result.isEmpty())
				searchBox.setText(result.get(0));
		}
		else if (requestCode==QRSCANNER_EXAMPLE && resultCode==RESULT_OK)
		{
			//Read result from QR Droid (it's stored in la.droid.qr.result)
			String result = data.getExtras().getString(Services.RESULT);
			//toaster.makeText(welcome, result, Toast.LENGTH_LONG).show();
			if (result != null)
				searchBox.setText(result);
		}
		super.onActivityResult(requestCode, resultCode, data);
	}
	private void startSearch()
	{
		Intent search = new Intent(this, Search.class);
		startActivity(search);
	}
	protected void startQR()
    {
		Intent qrscan = new Intent(Services.SCAN);
		try
		{
			startActivityForResult(qrscan, QRSCANNER_EXAMPLE);
		}
		catch (ActivityNotFoundException activity)
		{
			Services.qrDroidRequired(WelcomeScreen.this);
		}
    }
	private void startNewUser()
    {
		Intent newuser = new Intent(this, NewUser.class);
		startActivity(newuser);
    }
	private void startLogin()
	{
		Intent login = new Intent(this, LogIn.class);
		startActivity(login);
	}	
}
