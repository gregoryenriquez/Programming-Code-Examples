package com.cs166.alice.image;

import java.io.FileNotFoundException;
import java.io.IOException;

public class Alice {
	public static void main(String[] args) throws IOException
	{
		String filename = "alice.jpg";
		Image alice = new Image(filename);
		alice.readImage();
		byte[] image = alice.bytesImage; // all image bytes
		byte[] encryptedImage = new byte[image.length];
		
		
		byte[] subset = new byte[8];
		byte[] encryptedSubset = new byte[8];
		Encrypt encrypted = new Encrypt(image);
		
		
		for (int i = 0; i < image.length-1000; i = i + 8)
		{
			subset[i%8] = image[i];
			subset[(i+1)%8] = image[i+1];
			subset[(i+2)%8] = image[i+2];
			subset[(i+3)%8] = image[i+3];
			subset[(i+4)%8] = image[i+4];
			subset[(i+5)%8] = image[i+5];
			subset[(i+6)%8] = image[i+6];
			subset[(i+7)%8] = image[i+7];
			encryptedSubset = encrypted.encryptBytes(subset);
			for (int j = i; j < i+8; j++)
			{
				encryptedImage[j] = encryptedSubset[j%8];
			}
			
		}
		
		alice.createImage(encryptedImage);

		
		//encryptedImage = encrypted.encryptBytes();
		//alice.createImage(encryptedImage);
		
	}
}
