package com.cs166.hw2;

public class Score {
	
	Score(char l, int s)
	{
		letter = l;
		score = s;
	}
	char letter;
	int score;
	
	public void IncScore()
	{
		score++;
	}
}
