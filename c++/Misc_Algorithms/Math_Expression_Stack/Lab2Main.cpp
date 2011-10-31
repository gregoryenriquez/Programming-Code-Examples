#include <iostream>
using namespace std;

#include "mathExp.h" 
#include "mathExp.cpp"


int main()
{
	mathExp<int> negTest("(-5)+2");
	cout << negTest.convert();
	cout << "Solution: " << negTest.eval() << endl;

	// 10.2+35mod(7-3)-2.5
	mathExp<int> ex1("3+1*2-(2*(-5)+1)/3");
	cout << endl << ex1.convert();
	cout << endl << "Solution: " << ex1.eval() << endl;
	mathExp<float> ex2 ("3+(++1)*2-(2*1.5+1)/3");
	cout << endl << ex2.convert();
	cout << endl << "Solution: " << ex2.eval() << endl;

	mathExp<float> ex3("10.2+35mod(7-3)-2.5");
	cout << endl << ex3.convert();
	cout << endl << "Solution: " << ex3.eval() << endl;

	cout << endl << "Gregory Enriquez : 003001233" << endl;  // replace with your name and id

	//	cout << ex1 << endl << "convert to: " << ex1.convert << endl;
//	cout << "eval to: " << ex1.eval << endl;

// if your program can not handle ex2, submit ex1 screen shot.  Otherwise, submit screenshot for both

//	cout << ex2 << endl << "convert to: " << ex2.convert << endl;
//	cout << "eval to: " << ex2.eval << endl;

	// add other things you like to show...
	int x;
	cin >> x;
}

