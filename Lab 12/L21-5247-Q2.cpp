// Muhammad Farhan Bukhari------------BCS-3F-----------21L-5247
// Q2 (Lab 12--Graphs)

#include <iostream>
#include <list>
using namespace std;

class Graph
{
	int v;
	list<int>* adj;

public:

	Graph(int n = 0)
	{
		v = n;
		adj = new list<int>[v];
	}

	void TakeInput(int n, int w)
	{
		adj[n].push_back(w);
	}

	void Print()
	{
		bool* visited = new bool[v];
		for (int i = 0; i < v; i++)
			visited[i] = false;

		for (int i = 1; i < v; i++)
			if (visited[i] == false)
				DFSHelp(i, visited);

		cout << endl;
		delete[]visited;
	}

	void DFSHelp(int v, bool visited[])
	{
		visited[v] = true;
		cout << v << " ";

		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		{
			if (!visited[*i])
				DFSHelp(*i, visited);
		}
	}
};

int main()
{
	Graph g(6);

	g.TakeInput(1, 2);
	g.TakeInput(3, 4);
	g.TakeInput(4, 5);

	cout << "\n\nQ2\n\n";
	cout << "Sample input is :\n";
	cout << "5 3 2		(no Of cities, no of roads, no of flights)\n1 2		(road)\n3 4		(road)\n4 5		(road)\n\n";

	cout << "\nOutput :\n\n";
	g.Print();
	return 0;
}
