package com.cmpe130.dijkstras;

import java.util.*;
import java.io.*;

public class Graph{
	/**
	 * Class: Graph
	 */
	static ArrayList<Node> allNodes;
	
	Graph(int node_total, String input_file) throws FileNotFoundException
	{
		/**
		 * Class: Graph
		 * Function: Graph Constructor
		 * @param Total Number of Nodes
		 * @param Name of Input File to Read
		 */
		allNodes = new ArrayList<Node>();
		allNodes.add(Node.zero, null);
		for(int i = 1; i <= node_total; i++)
		{
			Node temp = new Node(i, node_total);
			allNodes.add(i, temp);
		}
		adjustGraph(input_file);
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
				allNodes.get(from).setNode(to, cost);
			}		
		}
		/*
		for (int i = 1; i < allNodes.size(); i++)
		{
			allNodes.get(i).printCosts();
		}*/
	}
	
	public class Node
	{
		/**
		 * Class: Node
		 */
		public static final int infinity = 1000000;
		public static final int zero = 0;
		private int node_num;
		private ArrayList<Integer> toCosts;
		private boolean visited;
		
		Node(int num, int total_nodes)
		{
			/**
			 * Class: Node
			 * Function: Node Constructor
			 * @param Name/Number of Node to Make
			 * @param Total Number of Nodes
			 */
			node_num = num;
			toCosts = new ArrayList<Integer>();
			toCosts.add(zero, zero);
			for (int i = 1; i <= total_nodes;i++)
			{
				toCosts.add(i, infinity);
			}
			toCosts.set(num, 0);
			
		}
		private int getCost(int i)
		{
			return toCosts.get(i).intValue();
		}
		public void setNode(int to, int cost)
		{
			toCosts.set(to, cost);
		}
		public boolean getVisited()
		{
			return visited;
		}
		public void setVisited()
		{
			visited = true;
		}
		public void printCosts()
		{
			//print("For Node: " + node_num);
			for (int i = 1; i < toCosts.size(); i++)
			{
				if (getCost(i) == infinity)
					print("From Node: " + this.node_num + "\t" + "to Node: " + i + "\t" + "Cost: Infinity");
				else
					print("From Node: " + this.node_num + "\t" + "to Node: " + i + "\t" + getCost(i));
			}
			print("-----------------------------------------");
		}
		
	}

	public class RoutingTable
	{
		ArrayList<Path> visitedPaths;
		ArrayList<Path> availablePaths;
		int start_at;
		int current;
		int end_at;
		
		RoutingTable(int start, int end)
		{
			visitedPaths = new ArrayList<Path>();
			availablePaths = new ArrayList<Path>();
			start_at = start;
			current = start;
			end_at = end;
			addAvailable(start, Node.zero);
		}
		
		public void generatePath()
		{
			printSeparator();
			print("******** Generating Path from: " + start_at + " to " + end_at + " ********");
			printSeparator();
			Path temp = getNextShortest();
			while (current != end_at)
			{
				if (temp == null) break;
				print("From Node: " + temp.from + "\t" + "To Node: " + temp.to + "\t" + "Total Cost: " + temp.total);
				visit(temp);
				addAvailable(temp.to, temp.total);
				temp = getNextShortest();
			}
			if (start_at == end_at)
				print("From Node: " + start_at + "\t" + "To Node: " + end_at + "\t" + "Total Cost: " + Node.zero);
			
		}
		
		public void visit(Path p)
		{
			visitedPaths.add(p);
		}
		
		public void addAvailable(int node, int prevCost)
		{
				for (int j = 1; j < Graph.allNodes.get(node).toCosts.size(); j++)
				{
					if (node != j && Graph.allNodes.get(node).toCosts.get(j) != Node.infinity)
					{ // Path(int f, int t, int tc)
						availablePaths.add( new Path(node, j, prevCost + Graph.allNodes.get(node).toCosts.get(j)));
					}
				}
			
			sortAvailable();
			/*
			for (int i = 0; i < availablePaths.size(); i++)
				print(availablePaths.get(i).from + "\t" + availablePaths.get(i).to + "\t" + availablePaths.get(i).total); 
			print("---------------------------------");*/
			current = node;
		}
		public void sortAvailable()
		{
			Collections.sort(availablePaths);
		}
		public Path getNextShortest()
		{
			if (availablePaths.isEmpty())
			{
				print("ERROR: NO PATH AVAILABLE FROM NODE " + start_at + " TO " + end_at);
				return null;
			}
			Path temp = availablePaths.get(0);
			availablePaths.remove(0);
			return temp;
		}
		
	}
	
	static public void print(Object o)
	{
		System.out.println(o);
	}
	
	static public void printSeparator()
	{
		System.out.println("----------------------------------------------");
	}
}
