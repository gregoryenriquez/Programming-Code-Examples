package com.hellman.diffie;

public class Encrypt {
	String encoded;
	String string_to_encrypt;
	int rotate;
	int reverse_size;
	
	Encrypt(String s, int r, int size)
	{
		rotate = r;
		reverse_size = size;
		string_to_encrypt = s;
	}
	
	public String encryptString()
	{
		if ( rotate == 0 && reverse_size == 0) return string_to_encrypt;
		char[] temp_arr = new char[string_to_encrypt.length()+1];
		temp_arr = string_to_encrypt.toCharArray();
		
		for (int i = 0; i < string_to_encrypt.length(); i++)
			temp_arr[i] = rotateChar(temp_arr[i]);
		
		String temp_str = new String(temp_arr);
		int i = 0;
		String temp = new String();
		if (reverse_size != 0)
		while ((i + reverse_size)< temp_str.length())
		{
			temp = temp_str.substring(i, i + reverse_size);
			flip(temp);
			if (encoded == null)
				encoded = temp;
			else 
				encoded = encoded + temp;
			i = i + reverse_size;
		}
		if (encoded == null)
			encoded = temp_str.substring(i, temp_str.length());
		else
			encoded = encoded + temp_str.substring(i, temp_str.length());
		return encoded;
	}
	
	public char rotateChar(char c)
	{
		if (c < 65) return c;
		if (c <= 90)
		{
			c = (char) ( (int)c + rotate);
			if (c > 90)
				c -= 26;
			return c;
		}
		if (c < 97) return c;	
		if (c <= 122)
		{
			c = (char) ( (int)c + rotate);
			if (c > 122)
				c -= 26;
			return c;
		}
		return c;
	}
	public String flip(String s)
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
