package com.cmpe137.shopping.app;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.AutoCompleteTextView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class ShippingInfo extends Activity {
	TextView itemTitleView;
	TextView itemCompanyView;
	TextView itemPriceView;
	String itemTitleStr;
	String itemCompanyStr;
	String itemPriceStr;
	EditText streetName;
	EditText personName;
	Button continueButton;
	AutoCompleteTextView state;
	Toast toaster;
	
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.shipping_info);
		
		Intent itemIntent = getIntent();
		itemTitleStr = itemIntent.getStringExtra("ITEM_TITLE");
		itemCompanyStr = itemIntent.getStringExtra("ITEM_COMPANY");
		itemPriceStr = itemIntent.getStringExtra("ITEM_PRICE");
		
		itemTitleView = (TextView) findViewById(R.id.itemTitle);
		itemTitleView.setText(itemTitleStr);
		
		itemCompanyView = (TextView) findViewById(R.id.itemCompany);
		itemCompanyView.setText(itemCompanyStr);
		
		itemPriceView = (TextView) findViewById(R.id.itemPrice);
		itemPriceView.setText(itemPriceStr);
		
	}
}
