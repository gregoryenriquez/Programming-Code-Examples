// mathExp.cpp

#include "mathExp.h"
#include <cctype>
#include <stack>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

template <class DataType>
mathExp<DataType>::mathExp(string expression)
{
	math_expression = expression;
}

template <class DataType>
list<string> mathExp<DataType>::infixToPostfix(string infix_expression)
{
	stack<string> op_stack;
	list<string> postfix;
	string exp = infix_expression;
	size_t left = 0, right = 0;

	string temp = "";

	while ( right != exp.size() )
	{
		temp = "";
		left = right;
		if ( exp[right] == ' ' || exp[right] == '\t' )
		{
			right++;
			
		}

		else if ( isNumber( exp[right] ) )
		{
			while ( isNumber( exp[right] ) )
			{
				right++;
				if ( right == exp.size() )
					break;
			}
			

		temp = exp.substr(left, right - left);
		postfix.push_back(temp);
		}

		else if ( exp[right] == '(' )
		{
			string temp = "(";
			op_stack.push( temp );
			right++;
			if (exp[right] == '-')
			{	
				string temp = "n";
				op_stack.push(temp);
				right++;
			}
			
		}

		else if ( exp[right] == ')' )
		{ // pop all ops from stack to postfix list
			while ( op_stack.top() != "(" )
			{
				postfix.push_back(op_stack.top());
				op_stack.pop();
			}
			op_stack.pop();
			right++;
		}

		else if ( isOperator( exp[right] ) )
		{
			while ( isOperator(exp[right]) )
			{
				right++;
			}
			temp = exp.substr(left, right - left);

			if (op_stack.empty()) 
				op_stack.push(temp);

			else if ( hasLessPriority(op_stack.top(), temp) )
			{
				postfix.push_back(op_stack.top());
				op_stack.pop();
				op_stack.push(temp);
			}

			else
			{
				op_stack.push(temp);
			}
		}

		else;

	}
	while ( !op_stack.empty() )
	{
		postfix.push_back(op_stack.top());
		op_stack.pop();
	}
	this->postfix = postfix;
	return postfix;
}


template <class DataType>
bool mathExp<DataType>::isOperator(char o)
{
	if (o == '+' || o == '-' || o == '*' || o == '/' || o == 'm' || o == 'o' || o == 'd' ) 
		return true;
	else 
		return false;
}

template <class DataType>
bool mathExp<DataType>::isNumber(char n)
{
	if ( isdigit(n) || n == '.') 
		return true;
	else 
		return false;
}

template <class DataType>
bool mathExp<DataType>::hasLessPriority(string stack_top, string op)
{
	if ( getP(stack_top) > getP(op) )
		return true;

	else 
		return false;
}

template <class DataType>
int mathExp<DataType>::getP(string s)
{
	if (s == "++" || s == "--" || s == "n")
	{
		return 3;
	}
	else if (s == "*" || s == "/" || s == "%" || s == "mod" )
	{
		return 2;
	}
	else if (s == "+" || s == "-")
	{
		return 1;
	}
	return 0;
}

template <class DataType>
string mathExp<DataType>::convert()
{
	return listToString( infixToPostfix(math_expression) );	
}

template <class DataType>
string mathExp<DataType>::listToString(list<string> l)
{
	string temp;
	list<string>::iterator it;
	for ( it= l.begin(); it != l.end(); it++)
	{
		temp.append(*it);
	}
	return temp;
}


template <class DataType>
DataType mathExp<DataType>::stringToNumber(string s)
{
	char* cstr;
	cstr = new char[s.size() + 1];
	strcpy(cstr, s.c_str());
	float temp = atof(cstr);
	return (DataType)temp;
}

template <class DataType>
DataType mathExp<DataType>::eval()
{
	return eval(postfix);
}

template <class DataType>
DataType mathExp<DataType>::eval(list<string> post_fix_expression)
{
	if (post_fix_expression.empty()) return 0;
	list<string> expList = post_fix_expression;
	string temp;
	list<string>::iterator it;
	it = expList.begin();
	DataType first_num;
	DataType second_num;
	string function = "";

	while ( it != expList.end() )
	{
		first_num = 0;
		second_num = 0;
		function = "";
		if ( isUnaryOperator(*it) )
		{
			function = *it;
			it++;
			first_num = post_evaluate.top();
			post_evaluate.pop();
			runUnary(first_num, function);		
		}

		else if ( isBinaryOperator(*it) )
		{
			function = *it;
			it++;
			second_num = post_evaluate.top();
			post_evaluate.pop();
			first_num = post_evaluate.top();
			post_evaluate.pop();
			runBinary(first_num, second_num, function);
		}

		else 
		{
			post_evaluate.push( stringToNumber(*it) );
			it++;
		}
	}
	return post_evaluate.top();
}

template <class DataType>
bool mathExp<DataType>::isBinaryOperator(string s)
{
	if (s == "+" || s == "-" || s == "*" || s == "/" || s == "%" || s == "mod") 
		return true;
	else 
		return false;
}

template <class DataType>
bool mathExp<DataType>::isUnaryOperator(string s)
{
	if (s == "++" || s == "--" || s == "n")
		return true;
	else
		return false;
}

template <class DataType>
void mathExp<DataType>::runUnary(DataType d, string op)
{
	if (op == "++")
	{
		d++;
		post_evaluate.push(d);
	}
	else if (op == "--")
	{
		d--;
		post_evaluate.push(d);
	}
	else if (op == "n")
	{
		d = 0 - d;
		post_evaluate.push(d);
	}
}

template <class DataType>
void mathExp<DataType>::runBinary(DataType d1, DataType d2, string op)
{
	if (op == "+")
	{
		d1 = d1+d2;
		post_evaluate.push(d1);
	}
	else if (op == "-")
	{
		d1 = d1-d2;
		post_evaluate.push(d1);
	}
	else if (op == "*")
	{
		d1 = d1*d2;
		post_evaluate.push(d1);
	}
	else if (op == "/")
	{
		d1 = d1 / d2;
		post_evaluate.push(d1);
	}
	else if (op == "%")
	{
		d1 = fmod((float)d1, (float)d2);
		post_evaluate.push(d1);
	}
	else if (op == "mod")
	{
		d1 = fmod((float)d1, (float)d2);
		post_evaluate.push(d1);
	}
}


