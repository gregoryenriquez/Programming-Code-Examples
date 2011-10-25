package com.cmpe130.dijkstras;

import java.io.*;

public class Main {

	static public void main(String[] S) throws FileNotFoundException
	{
		Graph dijkstras = new Graph(7, "graph.txt");
		Graph.RoutingTable Route1 = dijkstras.new RoutingTable(1, 7);
		Route1.generatePath();
		
		for (int i = 1; i <= 7; i++)
		{
			for (int j = 1; j <= 7; j++)
			{
				Route1 = dijkstras.new RoutingTable(i, j);
				Route1.generatePath();
			}
		}
	}
	
}
