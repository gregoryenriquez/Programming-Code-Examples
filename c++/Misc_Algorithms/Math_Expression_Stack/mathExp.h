// mathExp.h

#ifndef MATHEXP_H
#define MATHEXP_H

#include <string>
#include <stack>
#include <list>
#include <iostream>
using namespace std;

template <class DataType>
class mathExp
{
public:
	mathExp(string expression);

	list<string> infixToPostfix(string infix_expression);
	DataType evaluate(string postfix_expression);

	// Checks to see if char is an operator (includes prefix ++)
	bool isOperator(char o);
	bool isBinaryOperator(string s);
	bool isUnaryOperator(string s);

	// Run operators
	void runUnary(DataType d, string op);
	void runBinary(DataType d1, DataType d2, string op);

	// Checks to see if char is a number (includes decimal points)
	bool isNumber(char n);

	// Returns true if incoming operator has less priority than top of operator stack
	bool hasLessPriority(string stack_top, string op);

	// Converts infix to postfix and returns a string of the postfix expression
	string convert();

	// Returns contents of a list into a string 
	string listToString(list<string>);

	// Returns priority of operator (i.e. '++', '*', '-', etc)
	int getP(string); 

	DataType eval(list<string> post_fix_expression);
	DataType eval();

	DataType stringToNumber(string);

private:
	string math_expression;
	list<string> postfix;
	stack<string> operators;
	stack<DataType> post_evaluate;

};

#endif