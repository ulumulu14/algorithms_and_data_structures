#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack
{
private:
	Node *head;
	unsigned int m_elements = 0;
public:
	Stack();
	~Stack();
	bool isEmpty();
	void push(int data);
	int pop();
	unsigned int elements();
	Node* getHead();
};
#endif