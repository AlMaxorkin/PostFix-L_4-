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
	while (head != NULL)
	{
		tail = head->next;
		delete head;
		head = tail;
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
			if (stack.getSize() == 0)
				stack.push(str[i]);
			else if ((str[i] == '*' || str[i] == '/') && (stack.top() == '+' || stack.top() == '-'))
				stack.push(str[i]);
			else if ((str[i] == '+' || str[i] == '-') && (stack.top() == '*' || stack.top() == '/')
				|| (str[i] == '+' || str[i] == '-') && (stack.top() == '+' || stack.top() == '-')
				|| (str[i] == '*' || str[i] == '/') && (stack.top() == '*' || stack.top() == '/'))
			{
				while (stack.top() != '(')
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
			do
			{
				if(stack.top() != '(')
					res += stack.top();
				stack.pop();
			} while (stack.top() != '(');
		}
	}
	
	while (stack.getHead != NULL)
	{
		res += stack.top();
		stack.pop();
	} 
	
	stack.~Stack();
	return res;
}

