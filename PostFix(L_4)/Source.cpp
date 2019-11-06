#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	string expr = "(a*(b+c)+d)/2";

	cout << postfix(expr) << endl;
	system("pause");
	return 0;
}