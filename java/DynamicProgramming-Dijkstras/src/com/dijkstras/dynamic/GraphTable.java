package com.dijkstras.dynamic;

import java.io.File;
import java.lang.*;

import java.io.FileNotFoundException;

import java.security.Timestamp;
import java.sql.Time;
import java.util.Scanner;
import java.util.Timer;

public class GraphTable {
	static public int graph_table[][];
	static public int adjacency_mtx[][];
	static public int path[][];
	static final int infinity = 10000;
	static int totalNodes;
	static final String space = new String(" ");
	static final String tab = new String("\t");
	static final String newline = new String("\n");
	static final int NOT_A_VERTEX = -1;
	static public String dynamicstring = new String("");
	@SuppressWarnings("deprecation")

	

	static public char currentchar = 'a';
	
	GraphTable(int num_of_nodes) throws FileNotFoundException, NullPointerException
	{
	
		totalNodes = num_of_nodes;
		graph_table = new int[num_of_nodes+1][num_of_nodes+1];
		path = new int[num_of_nodes+1][num_of_nodes+1];
		for (int i = 1; i <= num_of_nodes; i++)
		{
			for (int j = 1; j <= num_of_nodes; j++)
			{
				graph_table[i][j] = infinity;
				path[i][j] = NOT_A_VERTEX;
			}
		}
		for (int i = 1; i <= num_of_nodes; i++)
		{
			graph_table[i][i] = 0;
		}
	}
	void adjustGraph(String input_file) throws FileNotFoundException
	{
		File readfile = new File(input_file);
		Scanner readme = new Scanner(readfile);
		
		int from, to, cost;
		while (readme.hasNext())
		{
			if (!readme.hasNextInt())
			{
				readme.next();
			}
			else
			{
				from = readme.nextInt();
				to = readme.nextInt();
				cost = readme.nextInt();
				graph_table[from][to] = cost;
			}		
		}
		adjacency_mtx = graph_table;
	}
	
	public void generatePaths()
	{ 	int d[][] = graph_table;
	   	
	for (int k = 1; k <= totalNodes; k++)
	{
		//currentchar = 'a';
	
		for (int i = 1; i <= totalNodes; i++)
		{
			
			dynamicstring = dynamicstring + currentchar + ',' + "\n";
			for (int j = 1; j <= totalNodes; j++)
			{
				if ( d[i][k] + d[k][j] < d[i][j] )
				{
					d[i][j] = d[i][k] + d[k][j];
					path[i][j] = k;
				}
				dynamicstring = dynamicstring + d[i][j];
				if (j != totalNodes)
					dynamicstring = dynamicstring + ", ";
			}
			dynamicstring = dynamicstring + "\n\n";
			//currentchar++;
		}
		//print(dynamicstring);
		printGraphTable();
	}
	}
	
	public void printGraphTable()
	{
		//println("Graph Table:");
		//println("[ ] = Infinite Cost");
		println(currentchar + ":");
		currentchar++;
		//println("------------------------");
		printTop();
		printRows();
	}
	public void printRows()
	{	char c = 'a';
		for (int i = 1; i <= totalNodes; i++)
		{
			print(space);
			print(c);
			c++;
			print(space);
			for (int j = 1; j <= totalNodes; j++)
			{
				if (graph_table[i][j] == infinity)
				{
					print(tab + "[ ]");
				}
				else
					print(tab + "[" + graph_table[i][j] + "]");
			}
			print(newline);
		}
	}
	public void printTop()
	{
		print("   ");
		char c = 'a';
		for (int i = 1; i <= totalNodes; i++)
		{
			System.out.print(tab + " " + c);
			c++;
		}
		print(newline);
	}
	
	static void println(Object o)
	{
		System.out.println(o);
	}
	static void print(Object o)
	{
		System.out.print(o);
	}
}
