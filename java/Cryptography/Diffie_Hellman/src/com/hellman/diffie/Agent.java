package com.hellman.diffie;

import java.util.*;
import java.math.*;

public class Agent {
	static int p = 23;
	static int g = 5;
	private int local_secret_key = 0; // Xa
	public int local_public_key = 0; // Ya
	public int peer_public_key = 0;  // Yb
	public int mutual_key = 0;
	boolean good_to_go = false;
	int rotate_val;
	int reverse_val;
	
	
	Agent()
	{
		Random generator = new Random();
		local_secret_key = generator.nextInt() % 10;
		local_public_key = calculatePublicKey();
	}
	
	static public void setPG(int temp_p, int temp_g)
	{
		p = temp_p;
		g = temp_g;
	}
	
	public int calculatePublicKey() 
	{
		return (int)( Math.pow(g,local_secret_key) % p );
	}
	
	public void setSecretKey(int key)
	{
		local_secret_key = key;
		resetPublicKey();
	}
	
	public void resetPublicKey()
	{
		local_public_key = calculatePublicKey();
	}
	
	public int getPublic()
	{
		return local_public_key;
	}
	
	public void setPeerKey(int key)
	{
		peer_public_key = key;
	}
	
	public void setMutualKey()
	{
		mutual_key =  (int)(  Math.pow(peer_public_key, local_secret_key) % p );
		print(mutual_key);
		if (mutual_key != 0)
			good_to_go = true;
		setRotateVal();
		setReverseVal();
	}
	
	public int getMutual()
	{
		return mutual_key;
	}
	
	public int getRotateVal()
	{
		return rotate_val;
	}
	public void setRotateVal()
	{
		rotate_val = mutual_key % 10;
	}
	public void setReverseVal()
	{
		int temp = reverse_val / 10;
		temp = temp % 10;
		//print("Reverse val: "+ temp);
		//if (reverse_val == 0)
		//	reverse_val = rotate_val;
	}
	public int getReverseVal()
	{
		return reverse_val;
	}
	public static void print(Object o)
	{
		System.out.println(o);
	}
	
	
}
