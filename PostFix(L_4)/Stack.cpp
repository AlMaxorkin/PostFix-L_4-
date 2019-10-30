#include "Stack.h"

using namespace std;

Stack::Stack()
{
	head = NULL;
}

Stack::~Stack()
{

}

void Stack::push()
{	
	int buf;
	cin >> buf;

	comp* temp = new comp;
	temp->data = buf;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}

void Stack::pop()
{

}

