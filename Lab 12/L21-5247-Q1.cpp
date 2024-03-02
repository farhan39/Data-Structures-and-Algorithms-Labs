// Muhammad Farhan Bukhari------------BCS-3F-----------21L-5247
// Q1 (Lab 12--Graphs)

#include <iostream>
#include <list>
using namespace std;
class Graph
{
	int v; // No. of vertices
	list<int>* adj; // adjacency lists

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

	void ExploreFunction(int start)
	{
		bool* visited = new bool[v];

		for (int i = 0; i < v; i++)
			visited[i] = false;

		int* arr = new int[10];
		int counter = 0;

		if (visited[start] == false)
			DFSHelp(start, visited, arr, counter);

		for (int i = 0; i <= counter; i++)
		{
			for (int j = 0; j < i; j++)
				cout << arr[j] << "  ";

			cout << endl;
		}

		delete[]visited;
	}

	void DFSHelp(int v, bool visited[], int* arr, int& counter)
	{
		visited[v] = true;

		arr[counter] = v;
		counter++;

		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if (!visited[*i])
				DFSHelp(*i, visited, arr, counter);
		}
	}

	void Print() //to print the DFS tree
	{
		for (int i = 0; i < v; i++)
			DFSHelp(i);
	}

	void DFSHelp(int v)
	{
		cout << v << "  ";

		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			cout << *i << "  ";
		}

		cout << endl;
	}
};

int main()
{
	Graph g1(4);
	g1.TakeInput(0, 1);
	g1.TakeInput(0, 2);
	g1.TakeInput(1, 2);
	g1.TakeInput(2, 0);
	g1.TakeInput(2, 3);
	g1.TakeInput(3, 3);

	cout << "\n\nQ1\n\n";
	cout << "Explore function for graph g1 with entry 1 is :\n";

	g1.ExploreFunction(1);

	cout << "\n\nGraph g1 with dfs is :\n\n";
	g1.Print();
	return 0;
}