package com.cmpe137.shopping.app;

import android.app.Activity;
import android.app.ListActivity;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.ListAdapter;
import android.widget.SimpleCursorAdapter;
import android.widget.ListView;
import android.widget.Toast;


public class Search extends ListActivity
{
   private String searchInput;
   private EditText searchText;
   private SQLiteDatabase db;
   private ListAdapter adapter;
   private Cursor cursor;
   private Toast toaster;
   
	 public void onCreate(Bundle savedInstanceState) 
	 {
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.search);
	        Intent getData = getIntent();
	        searchInput = getData.getStringExtra("searchInput");
	        
	        toaster.makeText(this, searchInput, Toast.LENGTH_SHORT).show();
	       
	        db = (new DatabaseHelper(this)).getWritableDatabase();
	        search(null);
	 
	 }
	 
    
	 public void search(View view) 
	 {
        // || is the concatenation operation in SQLite
	  
        cursor = db.rawQuery("SELECT _id, firstName, lastName, title FROM employee WHERE firstName || ' ' || lastName LIKE ?", 
                        new String[]{"%" + searchInput + "%"});
        adapter = new SimpleCursorAdapter(
              this, 
              R.layout.searchresults, 
              cursor, 
              new String[] {"firstName", "lastName", "title"}, 
              new int[] {R.id.firstName, R.id.lastName, R.id.title});
      setListAdapter(adapter);
      }
      
}
