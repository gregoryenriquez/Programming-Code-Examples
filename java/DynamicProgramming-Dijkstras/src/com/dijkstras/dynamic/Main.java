package com.dijkstras.dynamic;

import java.io.*;
import java.lang.*;

public class Main {
	static public void main(String[] s) throws FileNotFoundException, NullPointerException
	{
		GraphTable global_table = new GraphTable(4);
		//global_table.printGraphTable();
		global_table.adjustGraph("graph_final.txt");
		//global_table.printGraphTable();
		global_table.generatePaths();
		//global_table.printGraphTable();
	}
}
