// komiwojazer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Stack.h"
#include "Vertex.h"
#include "Node.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

const int MAX_GRAPH = 100;

void TSP(int startingVertex, Vertex* adjList[], int vertices);
void TSPReccurent(int currentVertex, int startingVertex, Vertex* adjList[], int vertices, Stack& stack, Stack& hStack, bool visited[], int weightSum, int* lowestWeightSum);

int main()
{
	string exit;
	int a;
	int b;
	int weight;
	int edges;
	int startingVertex;
	int vertices = 0;
	bool* visited;
	Vertex* adjList[MAX_GRAPH];
	Vertex* node;
	Stack stack;
	string edge;

	for (int i = 0; i < MAX_GRAPH; i++)
	{
		adjList[i] = NULL;
	}

	cin >> edges;

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

		node = new Vertex;
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

	cout << endl;

	cout << "Podaj wierzcholek startowy" << endl;
	cin >> startingVertex;

	TSP(startingVertex - 1, adjList, vertices);



	while (!(cin >> exit)) {}
    return 0;

	/*
	TEST1
	32
	(1,2) 2
	(1,3) 2
	(1,4) 4
	(1,5) 3
	(2,1) 2
	(2,3) 2
	(2,6) 1
	(2,7) 1
	(3,1) 2
	(3,2) 2
	(3,5) 2
	(3,6) 1
	(4,1) 4
	(4,6) 2
	(4,8) 3
	(5,1) 3
	(5,3) 2
	(5,7) 4
	(5,8) 5
	(6,2) 1
	(6,3) 1
	(6,4) 2
	(6,7) 2
	(6,8) 2
	(7,2) 1
	(7,5) 4
	(7,6) 2
	(7,8) 2
	(8,4) 3
	(8,5) 5
	(8,6) 2
	(8,7) 2
	*/
}

void TSP(int startingVertex, Vertex* adjList[], int vertices)
{
	int infinity = 2147483647;
	Stack stack;
	Stack hStack;
	bool* visited = new bool[vertices];
	int weightSum = 0;
	int lowestWeightSum = infinity;

	for (int i = 0; i < vertices; i++)
		visited[i] = false;

	TSPReccurent(startingVertex, startingVertex, adjList, vertices, stack, hStack, visited, weightSum, &lowestWeightSum);

	if (stack.isEmpty())
	{
		cout << "Brak cyklu Hamiltona.";
		return;
	}
	
	while (!stack.isEmpty())
		cout << stack.pop() << " ";

	cout << startingVertex << endl;

	cout << "Waga: " << lowestWeightSum << endl;

	return;
}

void TSPReccurent(int currentVertex, int startingVertex, Vertex* adjList[], int vertices, Stack& stack, Stack& hStack, bool visited[], int weightSum, int* lowestWeightSum)
{
	Vertex* v;
	Node* node;
	hStack.push(currentVertex);
	//cout << weightSum << endl;
	if (hStack.elements() < vertices)
	{
		visited[currentVertex] = true;

		for (v = adjList[currentVertex]; v; v = v->next)
		{
			if (!visited[v->vertex])
			{
				weightSum += v->weight;
				TSPReccurent(v->vertex, startingVertex, adjList, vertices, stack, hStack, visited, weightSum, lowestWeightSum);
				weightSum -= v->weight;
			}
			//cout << weightSum << endl;
		}
		visited[currentVertex] = false;
	}
	else
	{
		for (v = adjList[currentVertex]; v; v = v->next)
		{
			if (v->vertex == startingVertex)
			{
				weightSum += v->weight;

				if (weightSum < *lowestWeightSum)
				{
					while (!stack.isEmpty())
						stack.pop();

					*lowestWeightSum = weightSum;

					for (node = hStack.getHead(); node; node = node->next)
						stack.push(node->data);
				}

				//cout << stack.isEmpty() << endl;
				weightSum -= v->weight;
			}
			//cout << stack.isEmpty() << endl;
		}
		//cout << stack.isEmpty() << endl;
	}
	//cout << stack.isEmpty() << endl;
	hStack.pop();
}