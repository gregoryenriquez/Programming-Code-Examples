package com.cs151.hw1;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Queue;
//
//
//  Generated by StarUML(tm) Java Add-In
//
//  @ Project : CS151_HW1
//  @ File Name : EconomyClass.java
//  @ Date : 9/8/2011
//  @ Author : 
//
//




/** */
public class EconomyClass implements Serializable{
	static Seat[][] economySeats;
	public final String seatPattern;
	public final int rowLength;
	public final int numOfRows;
	public boolean created = false;
	public boolean economyFull = false;
	public int economySeatsLeft = 0;

	/** 
	 * EconomyClass constructor.
	 * 
	 * @param	seatPattern	String type with the row pattern composed of (W)indow, (A)isle, and (C)enter
	 * @param	numOfRows	number of rows in the particular compartment
	 * */
	public EconomyClass(String seatPattern, int numOfRows) {
		this.economyFull = false;
		this.created = true;
		this.seatPattern = seatPattern;
		this.rowLength = seatPattern.length();
		this.numOfRows = numOfRows;
		this.economySeats = new Seat[this.numOfRows][this.rowLength];	
		for (int i = 0; i < this.numOfRows; i++)
		{
			for (int j = 0; j < this.rowLength; j++)
			{
				economySeatsLeft++;
				economySeats[i][j] = new Seat(i, (char)(j+65), seatPattern.charAt(j));
			}
		}
	}
	/**
	 * EconomyClass constructor without any initial parameters
	 */
	public EconomyClass()
	{
		this.economySeatsLeft = 0;
		this.economyFull = true;
		this.seatPattern = "";
		this.rowLength = 0;
		this.numOfRows = 0;
	}
	/** 
	 * Returns Seat instance of the first found seat for the request.
	 * 
	 * This searches for the first seat available in the compartment based upon
	 * the seat preference.
	 * 
	 * @param	seatPref	type of seat preference
	 * */
	public Seat findEconomySeat(char seatPref)
	{
		Seat temp;
		for (int i = 0; i < numOfRows; i++)
		{
			for (int j = 0; j < rowLength; j++)
			{
				if (!economySeats[i][j].reserved && economySeats[i][j].seatType == seatPref)
				{
					temp = economySeats[i][j];
					return temp;
				}
			}
		}
		for (int i = 0; i < numOfRows; i++)
		{
			for (int j = 0; j < rowLength; j++)
			{
				if (!economySeats[i][j].reserved)
				{
					temp = economySeats[i][j];
					return temp;
				}
			}
		}
		System.out.println("Economy Class is Full");
		economySeatsLeft--;
		if (economySeatsLeft <= 0)
			economyFull = true;
		return null;
	
	} // end findEconomySeat()
	/** 
	 * Returns number of passengers left from the group who were not seated.
	 * 
	 * This searches for the first open row containing the most seats available for group reservation.
	 * 
	 * @param	num		number of passengers requesting a seat
	 * @param 	names	names of passengers trying to request a seat
	 * */
	public int findEconomyRowForGroup(int num, Queue<String> names)
	{
		if (num > economySeatsLeft) return -1;
		
		int count;
		int highestCount = -1;
		int rowWithMostSeats = -1;
		int startPos = 0;
		for (int i = 0; i < numOfRows; i++)
		{
			count = 0;
			startPos = 0;
			
			for (int j = 0; j < rowLength; j++)
			{
				if (!economySeats[i][j].reserved)
				{
					count++;
					if (count > highestCount)
					{
						highestCount = count;
						rowWithMostSeats = i;
					}
					if (count >= num)
					{
						break;
					}
					
				}
				else
				{
					count = 0;
					startPos = j;
				}
				if (count >= num)
				{
					break;
				}
			}
			if (count >= num)
			{
				break;
			}
		}
		
		Seat temp;
		for (int c = startPos; c < highestCount+startPos; c++)
		{
			if (c+1 > economySeats[rowWithMostSeats].length) break;
			temp = economySeats[rowWithMostSeats][c];
			System.out.println(names.peek() + " has been reserved for seat: " + (temp.rowNum+1) + temp.seatPos);
			if (!names.isEmpty())
				temp.setReserved(names.remove());
		}
		
		economySeatsLeft -= highestCount;
		if (economySeatsLeft <= 0)
			economyFull = true;
		
		return num-highestCount;
	} // end findEconomyRowForGroup()
	/** 
	 * Cancels reservation for a single person on the plane.
	 * */
	public boolean removeSingle(String name)
	{
		for (int i = 0; i < numOfRows; i++)
		{
			for (int j = 0; j < rowLength; j++)
			{
				if (economySeats[i][j].passenger.name.equals(name))
				{
					economySeats[i][j].clearSeat();
					economySeatsLeft++;
					if (economyFull && economySeatsLeft > 0)
					{
						economyFull = false;
					}
					return true;
				}
			}
		}
		return false;
	} // end removeSingle()
	/** 
	 * Cancels a number of passengers based upon names entered
	 * */
	public void removeGroup(Queue<String> names)
	{
		for (int i = 0; i < names.size(); i++)
		{
			if (removeSingle(names.peek())) names.remove();
		}
	}
}