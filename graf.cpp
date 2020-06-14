
//zadanie implementacyjne 3
//Arkadiusz Kaus
#include <iostream>
#include <string>

using namespace std;

const int MAX_GRAPH = 100;

struct Node
{
	int data;
	Node* next;
};

class Stack
{
private:
	Node* head;
public:
	Stack()
	{
		head = NULL;
	}

	~Stack()
	{
		while (head)
			pop();
	}

	bool isEmpty()
	{
		return !head;
	}

	void push(int data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
	}

	int pop()
	{
		int data;
		Node* temp;
		if (isEmpty())
			return -1;

		temp = head;
		head = head->next;
		data = temp->data;

		delete temp;

		return data;
	}
};

class Queue
{
private:
	Node* head;
	Node* tail;
public:
	Queue() 
	{
		head = tail = NULL;
	}

	~Queue()
	{
		while (head)
			pop();
	}

	bool isEmpty()
	{
		return !head;
	}

	int front()
	{
		if (head)
			return head->data;
		else
			return -1;
	}

	void push(int data)
	{
		Node* n = new Node;

		n->next = NULL;
		n->data = data;

		if (tail)
			tail->next = n;
		else
			head = n;

		tail = n;
	}

	int pop()
	{
		int rtrn;

		if (head)
		{
			rtrn = head->data;
			Node* n = head;
			head = head->next;

			if (!head)
				tail = NULL;
			delete n;
		}

		return rtrn;
	}
};

bool DFSSort(int[][MAX_GRAPH], int, int[], int, Stack&);
bool DFSSort(Node**, int, int[], int, Stack&);
void topologicalSort(int[][MAX_GRAPH], int);
void topologicalSort(Node**, int);
bool isBipartite(int[][MAX_GRAPH], int);
bool isBipartite(Node**, int);
void adjMatrix();
void adjList();

int main()
{
	/*sortowanie topologiczne
	10
	(1,3)
	(2,1)
	(2,3)
	(4,1)
	(4,2)
	(5,2)
	(5,3)
	(6,1)
	(6,5)
	*/
	/*dwudzielny
	6
	(1,6)
	(1,8)
	(2,6)
	(3,7)
	(4,5)
	(4,8)
	*/
	//adjMatrix();
	adjList();

    return 0;
}

bool DFSSort(int adjMatrix[MAX_GRAPH][MAX_GRAPH], int vertex, int visited[], int vertices, Stack& stack)
{
	if (visited[vertex] == 1)
	{
		cout << "cykl" << endl;
		return false;
	}

	if (!visited[vertex])
	{
		visited[vertex] = 1;

		for (int i = 0; i < vertices; i++)
		{
			if (adjMatrix[vertex][i] && !DFSSort(adjMatrix, i, visited, vertices, stack))
				return false;
		}

		visited[vertex] = 2;
		stack.push(vertex);
	}

	return true;
}

bool DFSSort(Node** adjList, int vertex, int visited[], int vertices, Stack& stack)
{
	if (visited[vertex] == 1)
	{
		cout << "cykl" << endl;
		return false;
	}

	if (!visited[vertex])
	{
		visited[vertex] = 1;

		for (Node* i = adjList[vertex]; i; i = i->next)
		{
			if (!DFSSort(adjList, i->data, visited, vertices, stack))
				return false;
		}

		visited[vertex] = 2;

		stack.push(vertex);
	}

	return true;
}

void topologicalSort(int adjMatrix[MAX_GRAPH][MAX_GRAPH], int vertices)
{
	int* visited = new int[vertices];
	Stack stack;

	//Kolorowanie grafu: 0-biały, 1-szary, 2-zielony
	for (int i = 0; i < vertices; i++)
		visited[i] = 0;

	for (int i = 0; i < vertices; i++)
	{
		if (!visited[i])
			if (!DFSSort(adjMatrix, i, visited, vertices, stack)) break;
	}

	for (int i = 0; i < vertices; i++)
		cout << stack.pop() + 1 << " ";

	cout << endl << endl;
}

void topologicalSort(Node** adjList, int vertices)
{
	int* visited = new int[vertices];
	Stack stack;

	//Kolorowanie grafu: 0-biały, 1-szary, 2-zielony
	for (int i = 0; i < vertices; i++)
		visited[i] = 0;

	for (int i = 0; i < vertices; i++)
	{
		if (!visited[i])
			if (!DFSSort(adjList, i, visited, vertices, stack)) break;
	}

	for (int i = 0; i < vertices; i++)
		cout << stack.pop() + 1 << " ";

	cout << endl << endl;
}

bool isBipartite(int adjMatrix[MAX_GRAPH][MAX_GRAPH], int vertices)
{
	Queue queue;
	int vertex;
	int* colors = new int[vertices];

	//Kolorowanie grafu: 0-szary,1-czerwony,-1-niebieski
	for (int i = 0; i < vertices; i++)
		colors[i] = 0;

	for (int i = 0; i < vertices; i++)
	{
		if (!colors[i])
		{
			colors[i] = 1;
			queue.push(i);

			while (!queue.isEmpty())
			{
				vertex = queue.pop();

				for (int j = 0; j < vertices; j++)
				{
					if (adjMatrix[vertex][j] && (colors[vertex] == colors[j]))
					{
						delete[] colors;
						return false;
					}

					if (adjMatrix[vertex][j] && !colors[j])
					{
						colors[j] = -colors[vertex];
						queue.push(j);
					}
				}

			}
		}
	}
	delete[] colors;

	return true;
}

bool isBipartite(Node** adjList, int vertices)
{
	Queue queue;
	int vertex, child;
	int* colors = new int[vertices];

	//Kolorowanie grafu: 0-szary,1-czerwony,-1-niebieski
	for (int i = 0; i < vertices; i++)
		colors[i] = 0;

	for (int i = 0; i < vertices; i++)
	{
		if (!colors[i])
		{
			colors[i] = 1;
			queue.push(i);

			while (!queue.isEmpty())
			{
				vertex = queue.pop();

				for (Node* j = adjList[vertex]; j; j = j->next)
				{
					child = j->data;

					if (colors[vertex] == colors[child])
					{
						delete[] colors;
						return false;
					}

					if (!colors[child])
					{
						colors[child] = -colors[vertex];
						queue.push(child);
					}
				}
			}
		}
	}

	delete[] colors;

	return true;
}

void adjMatrix()
{
	int a;
	int b;
	int edges;
	int vertices = 0;
	int matrix[MAX_GRAPH][MAX_GRAPH];
	string edge;

	for (int i = 0; i < MAX_GRAPH; i++)
	{
		for (int j = 0; j < MAX_GRAPH; j++)
			matrix[i][j] = 0;
	}

	cin >> edges;

	for (int i = 0; i < edges; i++)
	{
		cin >> edge;

		a = stoi(edge.substr(1, 2));
		b = stoi(edge.substr(3, 4));

		if (a > vertices)
			vertices = a;

		if (b > vertices)
			vertices = b;

		matrix[a - 1][b - 1] = 1;
	}

	cout << endl;

	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
			cout << matrix[i][j] << " ";

		cout << endl;
	}

	cout << endl;

	if (isBipartite(matrix, vertices))
		cout << "Graf jest dwudzielna" << endl << endl;
	else
		cout << "Graf nie jest dwudzielny" << endl << endl;

	topologicalSort(matrix, vertices);
}

void adjList()
{
	int a;
	int b;
	int edges;
	int vertices = 0;
	Node* adjList[MAX_GRAPH];
	Node* node;
	string edge;

	for (int i = 0; i < MAX_GRAPH; i++)
	{
		adjList[i] = NULL;
	}

	cin >> edges;

	for (int i = 0; i < edges; i++)
	{
		cin >> edge;

		a = stoi(edge.substr(1, 2));
		b = stoi(edge.substr(3, 4));

		if (a > vertices)
			vertices = a;

		if (b > vertices)
			vertices = b;

		node = new Node;
		node->next = adjList[a - 1];
		node->data = b - 1;
		adjList[a - 1] = node;
	}

	cout << endl;

	for (int i = 0; i < vertices; i++)
	{
		cout << i + 1 << " : ";
		node = adjList[i];

		while (node)
		{
			cout << node->data + 1 << ' ';
			node = node->next;
		}
		cout << endl;
	}

	cout << endl;

	if (isBipartite(adjList, vertices))
		cout << "Graf dwudzielny" << endl;
	else
		cout << "Graf nie jes dwudzielny" << endl;

	cout << endl;

	topologicalSort(adjList, vertices);
}