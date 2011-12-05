package com.cmpe137.shopping.app;

import android.app.Activity;
import android.app.ListActivity;
import android.content.ActivityNotFoundException;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ListAdapter;
import android.widget.SimpleCursorAdapter;
import android.widget.Toast;
public class ItemsByCompany extends ListActivity
{
   String companySelected;
   private SQLiteDatabase db;
   private Cursor cursor;
   private ListAdapter adapter;
   private Toast toaster;
   
   public void onCreate(Bundle savedInstanceState)
   {
      super.onCreate(savedInstanceState);
      setContentView(R.layout.itemsbycompany);
      
      Intent itemIntent = getIntent();
      companySelected = itemIntent.getStringExtra("companySelected");
            
      db = (new DatabaseHelper(this)).getWritableDatabase();
      searchItems();
   }
   
   public void searchItems()
   {
      cursor = db.rawQuery("SELECT _id, itemTitle, itemPrice from items where itemCompany LIKE ?", new String[]{"%" + companySelected + "%"});
      cursor.moveToFirst();
      
      adapter = new SimpleCursorAdapter(
            this,
            R.layout.itemsbycompanyresults,
            cursor,
            new String[]{"itemTitle", "itemPrice"},
            new int[] {R.id.itemTitle, R.id.itemPrice}
            );
      
      setListAdapter(adapter);
   }
   
   

}
