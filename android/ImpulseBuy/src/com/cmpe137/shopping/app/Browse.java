package com.cmpe137.shopping.app;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import android.content.ActivityNotFoundException;


public class Browse extends Activity
{
   Button nearby;
   Button type;
   Button similar;
   Toast toaster;
   
	public void onCreate(Bundle savedInstanceState) 
	{
        super.onCreate(savedInstanceState);
        setContentView(R.layout.browse);
        
        /*nearby = (Button) findViewById(R.id.Nearby);
        nearby.setOnClickListener(new View.OnClickListener()
        {
         
         @Override
         public void onClick(View v)
         {
            startNearby();
            
         }
      	});*/
        
       // type = (Button) findViewById(R.id.Type);
        /*type.setOnClickListener(new View.OnClickListener()
        {
           public void onClick(View v)
           {
              startTypes();
           }
        });
        
        
        similar = (Button) findViewById(R.id.Similar);
        similar.setOnClickListener(new View.OnClickListener()
              {
                 public void onClick(View v)
                 {
                    startSimilar();
                 }
              });*/
      

	}
	
	
	/*protected void startNearby()
	{
	   try
	   {
	      Intent nearby = new Intent(this, SearchNearby.class);
	      startActivity(nearby);
	   }
	   catch (ActivityNotFoundException anfe)
	   {
	      toaster.makeText(this, "Nearby activity not found!", Toast.LENGTH_SHORT).show();
	   }
	}*/
	
	/*protected void startTypes()
	{
	   try
	   {
	      Intent type = new Intent(this, SearchType.class);
	      startActivity(type);
	   }
	   catch (ActivityNotFoundException anfe)
	   {
	      toaster.makeText(this, "Types activity not found!", Toast.LENGTH_SHORT).show();
	   }
	}*/
	
	/*protected void startSimilar()
	{
	   try
	   {
	      Intent similar = new Intent(this, SearchSimilar.class);
	      startActivity(similar);
	   }
	   catch (ActivityNotFoundException anfe)
	   {
	      toaster.makeText(this, "Similar activity not found!", Toast.LENGTH_SHORT).show();
	   }
	}*/
}
