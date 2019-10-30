#pragma once
#include <iostream>
struct comp
{
	char data;
	comp* next;
};

class Stack
{
	comp* head;
	int size;
public:
	Stack();
	~Stack();
	void push();
	void pop();
};
