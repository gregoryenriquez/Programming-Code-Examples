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
import android.widget.Toast;

public class WelcomeScreen extends Activity{
		private static final int RECOGNIZER_EXAMPLE = 1001;
		private String searchText = "Enter a keword";
		private EditText searchBox;
		private Toast toaster;
		private WelcomeScreen welcome = this;
		public void onCreate(Bundle savedInstanceState) {
		    
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.welcome);
	        Button speakButton = (Button) findViewById(R.id.Speak);
	        
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
						toaster.makeText(welcome, "Speech Recognizer not found!\n Install from market", Toast.LENGTH_LONG).show();
					}
				}
			});
	        
	        searchBox = (EditText) findViewById(R.id.SearchBox);
	        
	    }
		
		@Override
		protected void onActivityResult(int requestCode, int resultCode, Intent data)
		{
			if (requestCode==RECOGNIZER_EXAMPLE && resultCode==RESULT_OK)
			{
				ArrayList<String> result = data.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS);
				searchBox.setText(result.toString());
			}
			super.onActivityResult(requestCode, resultCode, data);
		}
		
		
}
