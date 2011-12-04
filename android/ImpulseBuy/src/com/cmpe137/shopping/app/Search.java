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
	        img = (ImageView) findViewById(R.id.img);
	 }
	 
	 public void search() 
	 {
        // || is the concatenation operation in SQLite
		 
        cursor = db.rawQuery("SELECT _id, itemTitle, itemCompany, " +
        		"itemPrice, itemIcon from items WHERE itemTitle || " +
        		"' ' || itemCompany LIKE ?", 
                        new String[]{"%" + searchInput + "%"});
        cursor.moveToFirst();
        /*
        if (cursor == null) 
        {	
        	toaster.makeText(this, "Err: null cursor", Toast.LENGTH_LONG);
        	return;
        }
        if (cursor.isFirst())
        {
        	do
        	{
        		View tempView = (View) findViewById(R.layout.searchresults);
		        int titleIndex = cursor.getColumnIndex("itemTitle");
		        int companyIndex = cursor.getColumnIndex("itemCompany");
		        int priceIndex = cursor.getColumnIndex("itemPrice");
		        int iconIndex = cursor.getColumnIndex("itemIcon");
		        
		        String title, company, price, icon;
		        title = cursor.getString(titleIndex);
		        company = cursor.getString(companyIndex);
		        price = cursor.getString(priceIndex);
		        icon = cursor.getString(iconIndex);
        	} while (cursor.moveToNext());
        }*/
        
        adapter = new SimpleCursorAdapter(
              this, 
              R.layout.searchresults, 
              cursor, 
              new String[] {"itemTitle", "itemCompany", "itemPrice", "itemIcon"}, 
              new int[] {R.id.itemTitle, R.id.itemCompany, R.id.itemPrice, 
            		  getSource()}
              );
         
        setListAdapter(adapter);
	 }
	 
	 public int getSource()
	 {
		 //toaster.makeText(this, cursor.getColumnIndex("itemIcon"), Toast.LENGTH_LONG);
		 /*
		 String temp = cursor.getString(cursor.getColumnIndex("itemIcon"));
		 int id = 0;
		 try {
		 id = getResources().getIdentifier("drawable/" + 
				 temp.substring(0, temp.length()-3), null, getPackageName());
		 }
		 catch (Exception e)
		 {
			 
		 }
		 if (id != 0)
			 img.setImageResource(id);
		 else
			 img.setImageResource(getResources().getIdentifier("drawable/defaulticon", null, getPackageName()));
		 //toaster.makeText(this, temp, Toast.LENGTH_LONG).show();
		 //arrStrTemp.add(temp);
		  * */
		  
		 return R.drawable.defaulticon;
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
