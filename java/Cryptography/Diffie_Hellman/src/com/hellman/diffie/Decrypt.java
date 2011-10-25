package com.hellman.diffie;

public class Decrypt {
	String decoded;
	String string_to_decrypt;
	int rotate;
	int reverse_size;
	
	Decrypt(String s, int r, int size)
	{
		string_to_decrypt = s;
		rotate = r;
		reverse_size = size;
	}
	
	public String decryptString()
	{
		if ( rotate == 0 && reverse_size == 0) return string_to_decrypt;
		char[] temp_arr = new char[string_to_decrypt.length()+1];
		temp_arr = string_to_decrypt.toCharArray();
		
		for (int i = 0; i < string_to_decrypt.length(); i++)
			temp_arr[i] = unRotateChar(temp_arr[i]);
		
		String temp_str = new String(temp_arr);
		int i = 0;
		String temp = new String();
		if (reverse_size != 0)
		while ((i+reverse_size) < temp_str.length())
		{
			temp = temp_str.substring(i, i + reverse_size);
			unFlip(temp);
			if (decoded == null)
				decoded = temp;
			else 
				decoded = decoded + temp;
			i = i + reverse_size;
		}
		if (decoded == null)
			decoded = temp_str.substring(i, temp_str.length());
		else
			decoded = decoded + temp_str.substring(i, temp_str.length());
		return decoded;
	}
	
	public char unRotateChar(char c)
	{
		if (c < 65) return c;
		if (c <= 90)
		{
			c = (char) ( (int)c - rotate);
			if (c < 65)
				c += 26;
			return c;
		}
		if (c < 97) return c;	
		if (c <= 122)
		{
			c = (char) ( (int)c - rotate);
			if (c < 97)
				c += 26;
			return c;
		}
		return c;
	}
	public String unFlip(String s)
	{
		char[] temp_arr = new char[s.length()+1];
		temp_arr = s.toCharArray();
		
		char[] temp_rev = new char[s.length()+1];
		int j = s.length()-1;
		for (int i = 0; i < s.length()-1; i++)
		{
			temp_rev[i] = temp_arr[j];
			j--;
		}
		s = new String(temp_rev);
		
		return s;
	}
}
