package com.back.strikes.dijkstras;

import java.lang.*;

public class Path implements Comparable
{
	int total;
	int from;
	int to;
	
	Path(int f, int t, int tc)
	{
		total = tc;
		from = f;
		to = t;		
	}
	public int getTotal()
	{
		return total;
	}
	
	@Override
	public int compareTo(Object p) throws ClassCastException{
		int compare;
		if (this.total < ((Path) p).getTotal())
			compare = -1;
		else if (this.total == ((Path) p).getTotal())
			compare = 0;
		else 
			compare = 1;
		
		return compare;
	}
}
