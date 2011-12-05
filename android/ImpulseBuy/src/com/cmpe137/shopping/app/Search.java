package com.cmpe137.shopping.app;

import java.util.ArrayList;

import android.app.ListActivity;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.text.Layout;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;
import android.widget.Toast;


public class Search extends ListActivity
{
   private String searchInput;
   private EditText searchText;
   private SQLiteDatabase db;
   private ListAdapter adapter;
   private Cursor cursor;
   private Cursor cursor2;
   private Toast toaster;
   private Bitmap imgIcon;
   ImageView imageView;
   //private String img;
   ImageView i11=null;
   View convertView;
   ImageView img;
   private String image;
   ArrayList<String> arrStrTemp = new ArrayList<String>();
   int index = 0;
   
   private LayoutInflater mInflater;
      
	 public void onCreate(Bundle savedInstanceState) 
	 {
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.search);

	        Intent getData = getIntent();
	        searchInput = getData.getStringExtra("searchInput");
	        
	        db = (new DatabaseHelper(this)).getWritableDatabase();

	        search();
	      
	 }
	 
	 public void search() 
	 {
        // || is the concatenation operation in SQLite
		 
        cursor = db.rawQuery("SELECT _id, itemTitle, itemCompany, " +
        		"itemPrice, itemIcon from items WHERE itemTitle || " +
        		"' ' || itemCompany LIKE ?", 
                        new String[]{"%" + searchInput + "%"});
        cursor.moveToFirst();
       
        
        adapter = new SimpleCursorAdapter(
              this, 
              R.layout.searchresults, 
              cursor, 
              new String[] {"itemTitle", "itemCompany", "itemPrice", "itemIcon"}, 
              new int[] {R.id.itemTitle, R.id.itemCompany, R.id.itemPrice, 
            		  R.drawable.defaulticon}
              );
         
        setListAdapter(adapter);
	 }
	 
	 public void onListItemClick(ListView parent, View view, int position, long id) {
		 Intent shippingInfo = new Intent(this, ShippingInfo.class);
		 Cursor cursor = (Cursor)adapter.getItem(position);
		 shippingInfo.putExtra("ITEM_ID", cursor.getInt(cursor.getColumnIndex("_id")));
		 shippingInfo.putExtra("ITEM_TITLE", cursor.getString(cursor.getColumnIndex("itemTitle")));
		 shippingInfo.putExtra("ITEM_COMPANY", cursor.getString(cursor.getColumnIndex("itemCompany")));
		 shippingInfo.putExtra("ITEM_PRICE", cursor.getString(cursor.getColumnIndex("itemPrice")));
		 startActivity(shippingInfo);
	 }

}
