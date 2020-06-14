// linkList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef int  elementtype;

struct celltype
{
	elementtype element;
	celltype * next;
};

typedef celltype  * position;

class Lista
{
protected:

	position l; // wskaźnik do głowy listy

public:

	Lista::Lista(elementtype x = 0)
	{
		l = new celltype;
		l->element = x;
		l->next = NULL;
	}    //konstruktor

	Lista::~Lista()
	{
		celltype *node = l;
		while (node != NULL)
		{
			celltype *next = node->next;
			delete node;
			node = next;
		}
		l = NULL;
	}  //destruktor

	void Insert(elementtype x, position p)
	{
		celltype *prev = p;
		celltype *n = p->next;
		celltype *newNode = new celltype;

		newNode->element = x;
		newNode->next = n;
		prev->next = newNode;
	}

	void Delete(position p)
	{
		celltype *tmp = p->next;
		p->next = tmp->next;

		delete tmp;
	}

	elementtype Retrieve(position p)
	{
		if (p->next != NULL)
			return p->next->element;
	}

	position Locate(elementtype x)
	{
		celltype *p = l;

		while (p->next->element != x)
			p = p->next;

		return p;
	}

	position First()
	{
		return l;
	}

	position Next(position p)
	{
		return p->next;
	}

	position Previous(position p)
	{
		celltype *tmp = l;
		while (tmp->next != p)
			tmp = tmp->next;

		return tmp;
	}

	position END()
	{
		celltype *tmp = l;

		while (tmp->next != NULL)
			tmp = tmp->next;

		return tmp;
	}

	void print()
	{
		celltype  *tmp = l;
		while (tmp != NULL)
		{
			cout << tmp->element << ", ";
			tmp = tmp->next;
		}
		cout << endl;
	}
};

int main()
{
	Lista l(0);
	l.print();

	l.Insert(100, l.First());
	l.print();


	for (int i = 0; i<3; i++)
		l.Insert(i, l.First());
	l.print();

	l.Insert(20, l.Previous(l.END()));
	l.print();
	l.Delete(l.Locate(20));
	l.print();
	system("pause");

	return 0;
}
