#include "stdafx.h"
#include "Stack.h"
#include "Node.h"

Stack::Stack()
{
	head = NULL;
}

Stack::~Stack()
{
	while (head)
		pop();
}

bool Stack::isEmpty()
{
	return !head;
}

void Stack::push(int data)
{
	this->m_elements++;
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

int Stack::pop()
{
	this->m_elements--;
	int data;
	Node* temp;
	if (isEmpty())
		return -1;

	temp = head;
	head = head->next;
	data = temp->data;

	//delete temp;

	return data;
}

unsigned int Stack::elements()
{
	return this->m_elements;
}

Node* Stack::getHead()
{
	return this->head;
}