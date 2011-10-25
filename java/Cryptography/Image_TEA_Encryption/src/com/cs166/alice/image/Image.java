package com.cs166.alice.image;

import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.*;
import java.util.Iterator;

import javax.imageio.ImageIO;
import javax.imageio.ImageReadParam;
import javax.imageio.ImageReader;
import javax.imageio.stream.ImageInputStream;

public class Image {
	String filename;
	byte[] buf;
	public byte[] bytesImage;
	
	Image(String s)
	{
		buf = new byte[1024];
		filename = s;
	}
	
	public void readImage() throws FileNotFoundException
	{
		File file = new File(filename);
		if (file.exists())
		{
			FileInputStream fileIn = new FileInputStream(file);
			ByteArrayOutputStream baos = new ByteArrayOutputStream();
			
			try {
				for (int readNum; (readNum=fileIn.read(buf)) != -1;)
				{
					baos.write(buf, 0, readNum);
					
				}
			}
			catch (IOException e)
			{
				
			}
		bytesImage = baos.toByteArray();
		}
	}
	
	public void createImage(byte[] bytes) throws IOException
	{
		byte[] imageToCreate = bytes;
		ByteArrayInputStream bais = new ByteArrayInputStream(imageToCreate);
		Iterator<?> readers = ImageIO.getImageReadersByFormatName("jpg");
		
		ImageReader reader = (ImageReader) readers.next();
		Object source = bais;
		
		ImageInputStream iis = ImageIO.createImageInputStream(source);
		
		reader.setInput(iis, true);
		ImageReadParam param = reader.getDefaultReadParam();
		
		BufferedImage image = reader.read(0, param);
		
		BufferedImage bufferedImage = new BufferedImage(image.getWidth(null), image.getHeight(null), BufferedImage.TYPE_INT_RGB);
		
		Graphics2D g2 = bufferedImage.createGraphics();
		
		g2.drawImage(image, null, null);
		
		File imageFile = new File("encryptedAlice.jpg");
		ImageIO.write(bufferedImage, "jpg", imageFile);
		
		System.out.println(imageFile.getPath());
		
	}

}
