// BellamFordAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

const int MAX_GRAPH = 100;

struct Node
{
	Node* next;
	int vertex;
	int weight;
};

bool bellmanFordAlgorithm(Node* adjList[MAX_GRAPH], int vertices, int startingVertex, int p[], unsigned long long int d[]);

int main()
{
	string exit;
	const unsigned long long int infinity = 18446744073709551615;
	int a;
	int b;
	int weight;
	int edges;
	int startingVertex;
	int vertices = 0;
	int* p; //koszt dojscia z wierzchołka startowego startingVertex do wierzchołka i-tego
	unsigned long long int* d; //poprzednik i-tego wierzchołka w najkrótszej ścieżce
	Node* adjList[MAX_GRAPH];
	Node* node;
	string edge;

	for (int i = 0; i < MAX_GRAPH; i++)
	{
		adjList[i] = NULL;
	}

	cin >> edges;

	//Input: 
	//liczba_krawedzi
	//(a,b) waga
	
	for (int i = 0; i < edges; i++)
	{
		cin >> edge;
		cin >> weight;

		a = stoi(edge.substr(1, 2));
		b = stoi(edge.substr(3, 4));
		//weight = stoi(edge.substr(5, 6));

		if (a > vertices)
			vertices = a;

		if (b > vertices)
			vertices = b;

		node = new Node;
		node->next = adjList[a - 1];
		node->vertex = b - 1;
		node->weight = weight;
		adjList[a - 1] = node;
	}

	cout << endl;

	for (int i = 0; i < vertices; i++)
	{
		cout << i + 1 << " : ";
		node = adjList[i];

		while (node)
		{
			cout << node->vertex + 1 << ' ';
			node = node->next;
		}
		cout << endl;
	}

	p = new int[vertices];
	d = new unsigned long long int[vertices];

	for (int i = 0; i < vertices; ++i)
	{
		d[i] = infinity;
		p[i] = -1;
	}

	cout << endl;
	cout << "Podaj wierzchołek startowy" << endl;
	cin >> startingVertex;

	if (bellmanFordAlgorithm(adjList, vertices, startingVertex - 1, p, d))
	{
		int* stack = new int[vertices];
		int stackPtr = 0;

		for (int i = 0; i < vertices; ++i)
		{
			for (int x = i; x != -1; x = p[x])
				stack[stackPtr++] = x;

			cout << "Sciezka: ";
			while (stackPtr)
				cout << stack[--stackPtr] + 1 << ' ';

			cout << "   Koszt: " << d[i] << endl;
		}

		delete[] stack;
	}
	else
		cout << "Negative cycle" << endl;

	delete[] p;
	delete[] d;

	while(!(cin >> exit)) {}

	/*
	TEST1
	11
	(1,2) 5
	(2,4) 3
	(2,5) 9
	(3,1) 3
	(3,2) -4
	(4,5) 3
	(4,6) 2
	(5,3) -1
	(5,6) -5
	(6,1) 9
	(6,3) 8
	*/
    return 0;
}

bool bellmanFordAlgorithm(Node* adjList[MAX_GRAPH], int vertices, int startingVertex, int p[], unsigned long long int d[])
{
	
	Node* v;
	bool test;

	d[startingVertex] = 0;

	for (int i = 0; i < vertices - 1; ++i)
	{
		test = true;

		for (int x = 0; x < vertices; ++x)
		{
			for (v = adjList[x]; v; v = v->next)
			{
				if (d[v->vertex] > d[x] + v->weight)
				{
					test = false;
					d[v->vertex] = d[x] + v->weight;
					p[v->vertex] = x;
				}
			}
		}

		if (test)
			return true;
	}

	//sprawdzenie czy sa ujemne cykle
	for (int x = 0; x < vertices; ++x)
	{
		for (v = adjList[x]; v; v = v->next)
		{
			if (d[v->vertex] > d[x] + v->weight)
				return false;
		}
	}
	cout << "za bellamem";

	return true;
}