#include "Stack.h"

using namespace std;

Stack::Stack() 
{
	tail = NULL;
	head = NULL;
	size = 0;
}

Stack::~Stack()
{
	for(int i = 0; i < size; i++)
	{
		pop();
	}
}

void Stack::push(char val)
{
	Node* Temp;	
	Temp = new Node;
	Temp->data = val;
	if (tail == NULL)
	{
		tail = Temp;
	}
	else
	{
		Temp->next = tail;
		tail = Temp;
	}
	size++;
}

char Stack::top()
{
	if (size == 0)
		return 0;
	else
		return tail->data;
}

void Stack::pop()
{
	Node* delptr = tail;	
	tail = tail->next;
	delete delptr;
	size--;
}

string postfix(string str)
{
	string res = "";
	Stack stack;
	for (int i = 0; i < strlen(str.c_str()); i++)
	{
		if (isalnum(str[i]))
			res += str[i];
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (stack.getSize() == 0 || stack.top() == '(')
				stack.push(str[i]);
			else if ((str[i] == '*' || str[i] == '/') && (stack.top() == '+' || stack.top() == '-') 
				||  (str[i] == '+' || str[i] == '-') && (stack.top() == '+' || stack.top() == '-'))
				stack.push(str[i]);
			else if ((str[i] == '+' || str[i] == '-') && (stack.top() == '*' || stack.top() == '/')
				|| (str[i] == '*' || str[i] == '/') && (stack.top() == '*' || stack.top() == '/'))
			{
				while ((stack.top() != '+' || stack.top() != '-') && stack.getSize() != 0 && stack.top() != '(')
				{
					res += stack.top();
					stack.pop();
				}
				stack.push(str[i]);
			}
		}
		else if (str[i] == '(')
			stack.push(str[i]);
		else if (str[i] == ')')
		{
			while (stack.top() != '(')
			{
				res += stack.top();
				stack.pop();
			} 
			stack.pop();
		}
	}
	
	while(stack.getSize() != 0)
	{
		res += stack.top();
		stack.pop();
	}
	
	stack.~Stack();
	return res;
}

