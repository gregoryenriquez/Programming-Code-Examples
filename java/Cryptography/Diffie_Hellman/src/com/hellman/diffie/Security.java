package com.hellman.diffie;

import javax.swing.*;
import java.lang.*;

public class Security {
	static public void main(String[] s)
	{
		String userinput = JOptionPane.showInputDialog("Change p/g? \n Yes = 1, No = 0\n");
		int selection = Integer.parseInt(userinput);
		int temp_p;
		int temp_g;
		String my_msg = new String("This is my message");
		String bob_msg = new String("Bob's Message That Will Be Sent To Greg");
		print("Starting Strings: ");
		print(my_msg);
		print(bob_msg);
		String my_encrypted_msg = new String();
		String bob_encrypted_msg = new String();
		String my_final_msg = new String();
		String bob_final_msg = new String();
		
		if (selection == 1)
		{
			userinput = JOptionPane.showInputDialog("p value? (must be prime)\n");
			temp_p = Integer.parseInt(userinput);
			userinput = JOptionPane.showInputDialog("g value?\n");
			temp_g = Integer.parseInt(userinput);
			Agent.setPG(temp_p, temp_g);
		}				
		
		Agent me = new Agent();
		Agent bob = new Agent();
		
		
		// edit private / generate public key here
		
		me.setSecretKey(6);
		bob.setSecretKey(7);
		//print(me.getPublic());
		me.setPeerKey(bob.getPublic());
		bob.setPeerKey(me.getPublic());
		
		// end
		
		me.setMutualKey();
		bob.setMutualKey();
		
		print("Greg's mutually shared key: " + me.getMutual());
		print("Bob's mutually shared key: " + bob.getMutual());

		Encrypt my_encrypt = new Encrypt(my_msg, me.getRotateVal(), me.getReverseVal());
		Encrypt bob_encrypt = new Encrypt(bob_msg, bob.getRotateVal(), bob.getReverseVal()); 
		
		my_encrypted_msg = my_encrypt.encryptString();
		bob_encrypted_msg = bob_encrypt.encryptString();
		print("Encrypted Strings:");
		print(my_encrypted_msg);
		print(bob_encrypted_msg);
	
		Decrypt my_decrypt = new Decrypt(my_encrypted_msg, me.getRotateVal(), me.getReverseVal());
		Decrypt bob_decrypt = new Decrypt("Mxkm oy cxutm", bob.getRotateVal(), bob.getReverseVal());
		
		my_final_msg = my_decrypt.decryptString();
		bob_final_msg = bob_decrypt.decryptString();
		
		print("Decrypted Strings: ");
		print(my_final_msg);
		print(bob_final_msg);
	}
	
	public static void print(Object o)
	{
		System.out.println(o);
	}
}
