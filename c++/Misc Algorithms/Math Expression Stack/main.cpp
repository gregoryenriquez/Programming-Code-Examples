// main.cpp

#include <iostream>
#include <time.h>
using namespace std;
#include "mathExp.h"
#include "member.h"
#include "AVLstudentDB.h"
#include "mathExp.cpp"


int main()
{
		cout << "Gregory Enriquez: ID 003001233" << endl;
		
		mathExp<float> ex3("10.2+36mod(7-2)*1.3-4.5");
		time_t now = time(NULL);
		cout << "BEGIN: " << ctime(&now) << endl;
		cout << "ex3 postfix is " << ex3.postfix() << " evaluate to: " << ex3.eval() << endl;

		// use exam.txt ;

		AVLstudentDB examDB("exam.txt");
		cout << endl << "List DB preorder" << endl;
		examDB.preorder();
		cout << "Insert a new student facebook" << endl;
		examDB.insert(ex3.eval(), "facebook");
		cout << endl << "List DB postorder after insert" << endl;
		examDB.postorder();
		now = time(NULL);
		cout << "ALL DONE: " << ctime(&now) << endl;

		int finish;
		cin >> finish;
		return 0;
}