package com.cs166.hw2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class SimpleSubstitution {
	public static char[] swapList;
	public static void main(String[] s) throws IOException
	{
		ArrayList<Score> scoreTable = new ArrayList<Score>();
		String strAlphabet = new String("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		ArrayList<Character> alphabet = new ArrayList<Character>();
		for (int i = 0; i < strAlphabet.length(); i++)
		{
			alphabet.add(strAlphabet.charAt(i));
			Score temp = new Score(strAlphabet.charAt(i), 0);
			scoreTable.add(new Score(strAlphabet.charAt(i), 0));
		}
		
		File fileName;
		if (s.length == 0)
		{
			fileName = new File("cipher.txt");
		}
		else
		{
			fileName = new File(s[0]);
		}

		FileInputStream fileToRead = new FileInputStream(fileName);
		String cipherText = new String();
		while (fileToRead.available() > 0)
		{
			cipherText += (char)fileToRead.read();
		}
		
		System.out.println("Cipher Text: " + cipherText);
		System.out.println("Alphabet: ");
		for (int i = 0; i < 26; i++)
		{
			System.out.print(alphabet.get(i));
		}
		
		for (int i = 0; i < alphabet.size(); i++)
		{
			for (int j = 0; j < cipherText.length(); j++)
			{
				if (alphabet.get(i) == cipherText.charAt(j))
				{
					scoreTable.get(i).IncScore();
				}
			}
		}
		
		println("");
		for (int i = 0; i < scoreTable.size(); i++)
		{
			println(scoreTable.get(i).letter + ": " + scoreTable.get(i).score);
		}
		
		swapList = new char[26];
		println(cipherText);
		while (userGuess(new String(cipherText)));
										// ABCDEFGHIJKLMNOPQRSTUVWXYZ
		//userGuess(new String(cipherText), "PRTVXJBDFHKLNYWUSQOMZIGECA");
		
		System.out.println("");
		
	}	// end main
	
	public static boolean userGuess(String cipherText) throws IOException
	{
		System.out.println("Enter Q to quit.");
		System.out.println("Guess a key to shift the message by: ");
		char quit = 'a';
		
		InputStreamReader input = new InputStreamReader(System.in);	
		BufferedReader reader = new BufferedReader(input);
		
		String keyGuess = reader.readLine();
		//String keyGuess = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
						// ABCDEFGHIJKLMNOPQRSTUVWXYZ
		
		//keyGuess = guess;
		
		if (keyGuess.length() == 1)
			quit = keyGuess.charAt(0);
		
		if (quit == 'Q' || quit == 'q')
			return false;
		
		char[] pAlphabet = new char[26];
		
		for (int i = 0; i < pAlphabet.length; i++)
		{
			pAlphabet[i] = keyGuess.charAt(i);
		}
		
		char[] cipherArray = cipherText.toCharArray();
		
/*		for (int i = 0; i < cipherArray.length; i++)
		{
			print(cipherArray[i]);
		}
	*/	
		
		int index = 0;
		for (int i = 0; i < cipherArray.length-2; i++)
		{
			index = ((int)cipherArray[i]) - 65;
			print(pAlphabet[index]);
		}
		println("");
//		String guess = cipherArray.toString();
	//	System.out.println(guess);
		
		return true;
	}
	
	public static void println(Object o)
	{
		System.out.println(o);
	}
	public static void print(Object o)
	{
		System.out.print(o);
	}
}

