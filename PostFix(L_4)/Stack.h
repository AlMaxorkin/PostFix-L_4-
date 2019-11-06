#pragma once
#include <iostream>
struct Node
{
	char data;
	Node* next;
};

class Stack
{
	Node* head, * tail;
	int size;
public:
	Stack();
	~Stack();
	Node* getTail() { return tail; }
	Node* getHead() { return head; }
	int getSize() { return size; }
	bool isempty();
	void push(char);
	void pop();
	char top();
};

std::string postfix(std::string);
