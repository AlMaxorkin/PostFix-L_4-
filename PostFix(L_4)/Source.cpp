#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	string expr1 = "a+b*c";
	string expr2 = "a+b-c*d";
	string expr3 = "a+b*c-d";
	string expr4 = "(a+b)*c";
	string expr5 = "(a+b*c)/2";
	string expr6 = "(a*(b+c)+d)/2";

	cout << postfix(expr1) << endl;
	cout << postfix(expr2) << endl;
	cout << postfix(expr3) << endl;
	cout << postfix(expr4) << endl;
	cout << postfix(expr5) << endl;
	cout << postfix(expr6) << endl;
	system("pause");
	return 0;
}