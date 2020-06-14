// listaTablicowa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


typedef int elementtype, position;
const long int MIN = -10000000;
const int maxlength = 10;
struct List
{
	elementtype elements[maxlength];
	int last;           //indeks ostatniego elementu listy
};

position END(List l)
{
	return l.last + 1;
}

position First(List l)
{
	return 0;
}

position Next(position p, List l)
{
	if (p >= l.last)
		return -1;
	else
		return p + 1;
}

position Previous(position p, List l)
{
	if (p - 1 < 0)
		return -1;
	else
		return p - 1;
}

position Locate(elementtype x, List l)
{ //zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
	for (int i = 0; i <= l.last; i++)
	{
		if (l.elements[i] == x)
			return i;
	}

	return END(l);
}

elementtype Retrieve(position p, List l)
{
	if (p <= l.last && p >= 0)
		return l.elements[p];
	else
		return MIN;
}

bool Insert(int x, position p, List &l)
{
	if (l.last < maxlength && p < maxlength && p >= 0)
	{
		for (int i = l.last; i >= p; i--)
		{
			l.elements[i + 1] = l.elements[i];
		}
		l.last++;
		l.elements[p] = x;

		return true;
	}
	else
		return false;
}

bool Delete(position p, List &l)
{
	if (p >= 0 && p <= l.last)
	{
		for (int i = p; i <= l.last; i++)
			l.elements[i] = l.elements[i + 1];
		l.last--;
		return true;
	}
	else
		return false;
}

void print(List l)
{
	//position i = First(l);

	for (int i = 0; i < END(l); i++)
	{
		cout << Retrieve(i, l) << ", ";
	}
	cout << endl;
	/*while (i != END(l))
	{
		printf("  %d,", Retrieve(i, l));
		i = Next(i, l);
	}
	printf("\n");*/

}

int main()
{
	List l;
	l.last = -1;
	Insert(100, First(l), l);
	print(l);

	for (int i = 0; i<3; i++)
		Insert(i, First(l), l);
	print(l);

	Insert(20, Previous(END(l), l), l);
	print(l);
	Delete(Locate(20, l), l);
	print(l);

	system("pause");

    return 0;
}

