package com.cs151.hw1;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;


public class ReservationSystem implements Serializable{
	public static boolean TESTING = true;
	public static boolean DEMO = !TESTING;

	/** 
	 * Main entry point into the program. Reads in an airplane object if it exists,
	 * otherwise it creates a new one.
	 * @param	args	file name with existing plane object
	 * */
	static public void main (String[] args) throws IOException, ClassNotFoundException
	{
		String fileName;
		Airplane plane = null;
		if (args.length == 1) // read in airplane object
		{
			fileName = args[0];
			File inputFile = new File(fileName);
			if (inputFile.exists())
			{
				if (ReservationSystem.TESTING) System.out.println("File found: reading in object");
				ObjectInputStream in = new ObjectInputStream(new FileInputStream(fileName));
				plane = (Airplane)in.readObject();
				in.close();
				plane.startMenu();
			}
			
			
			
		}
		else if (args.length <= 3)// first program run
		{
			String inputFileName = args[2];
			plane = new Airplane();
			
			if (!TESTING) plane.enterDummyData(inputFileName);
		}
		
		fileName = "airplane.txt";
		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(fileName));
		out.writeObject(plane);
		out.close();
		
	}
}
