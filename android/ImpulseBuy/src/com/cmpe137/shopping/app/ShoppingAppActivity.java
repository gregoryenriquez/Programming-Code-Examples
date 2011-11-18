package com.cmpe137.shopping.app;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;


public class ShoppingAppActivity extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
    
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
      
    }
    public boolean onTouchEvent(MotionEvent event)
	{
		startWelcome();
		return true;
	}
    
    protected void startWelcome()
    {
    	Intent search = new Intent(this, WelcomeScreen.class);
		startActivity(search);
    }
    
    @Override
    protected void onStart(){
    	super.onStart();
    }
    
    @Override
    protected void onResume(){
    	super.onResume();
    }
    
    @Override
    protected void onRestart(){
    	super.onRestart();
    }
    
    @Override
    protected void onPause(){
    	super.onPause();
    }
    
    @Override
    protected void onStop(){
    	super.onStop();
    }
    
    @Override
    protected void onDestroy(){
    	super.onDestroy();
    }
    
}