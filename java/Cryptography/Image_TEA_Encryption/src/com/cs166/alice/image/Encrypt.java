package com.cs166.alice.image;

public class Encrypt {
	byte[] toEncrypt;
	int[] key = {1, 3, 5, 7};
	public long delta = 2654435769l;
	
	Encrypt(byte[] b)
	{
		this.toEncrypt = b;
	}
	public byte[] encryptBytes(byte[] eightBytes)
	{
	
		byte[] cipherText = new byte[8];
		if (eightBytes.length != 8) return null;
		
		byte[] leftBytes = new byte[4];
		byte[] rightBytes = new byte[4];
		
		int left1 = 0, left2 = 0, left3 = 0, left4 = 0;
		int right1 = 0, right2 = 0, right3 = 0, right4 = 0;
		
		long leftSum = 0, rightSum = 0, leftSumTemp = 0, rightSumTemp = 0;
		
		for (int i = 0; i < 4; i++)
		{
			leftBytes[i] = eightBytes[i];
		}
		for (int i = 4; i < 8; i++)
		{
			rightBytes[i-4] = eightBytes[i];
		}
		long sum = 0;
		
		for (int i = 0; i < 32; i++)
		{
			sum = sum + delta;
			left1 = leftBytes[0];
			left2 = leftBytes[1];
			left3 = leftBytes[2];
			left4 = leftBytes[3];
			right1 = rightBytes[0];
			right2 = rightBytes[1];
			right3 = rightBytes[2];
			right4 = rightBytes[3];
			
			leftSum = left4*1 + left3*100 + left2*10000 + left1*1000000;
			rightSum = right4*1 + right3*100 + right2*10000 + right1*1000000;
			leftSumTemp = leftSum;
			rightSumTemp = rightSum;
			
			
			leftSum = leftSum + (((rightSum << 4) + key[0]) ^ (rightSum + sum) ^ (( rightSum >> 5)+ key[1]));
			rightSum = rightSum + (((leftSum << 4) + key[2]) ^ (leftSum + sum) ^ (( leftSum >> 5) + key[3]));
		}
		
		leftBytes[0] = (byte)(leftSum / 1000000);
		leftBytes[1] = (byte)(leftSum / 10000);
		leftBytes[2] = (byte)(leftSum / 100);
		leftBytes[3] = (byte)(leftSum % 100);
		rightBytes[0] = (byte)(rightSum / 1000000);
		rightBytes[1] = (byte)(rightSum / 10000);
		rightBytes[2] = (byte)(rightSum / 100);
		rightBytes[3] = (byte)(rightSum % 100);
		
		for (int i = 0; i < 4; i++)
		{
			cipherText[i] = leftBytes[i];
		}
		for (int i = 4; i < 8; i++)
		{
			cipherText[i] = rightBytes[i-4];
		}
		return cipherText;
	}
	
}
