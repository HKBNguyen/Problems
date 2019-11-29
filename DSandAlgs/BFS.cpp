#include<iostream>
#include<list>
#include <queue>
using namespace std;

class Graph
{
	int V; // # of vertices
	// adjacency list
	list<int> *adj;
public:

	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V]; // an array of adjacency lists
	}

	void addEdge(int v, int w)
	{
		adj[v].push_back(w); // add the vertex w to v's adjacency list
	}

	void BFS(int s)
	{
		bool *visited = new bool[V];
		for (int i = 0; i < V; i++)
		{
			visited[i] = false;
		}
		// BFS uses a queue
		list<int> queue;
		// mark the source as visited and push it into the queue
		visited[s] = true;
		queue.push_back(s);
		// iterator to get all of the adjacent vertices
		list<int>::iterator itr;

		while(!queue.empty())
		{
			// look at the first element and pop it
			s = queue.front();
			cout << s << " ";
			queue.pop_front();

			// visit all adjacent vertices of the current node s
			// if an adjacent vertex has not been visited then mark
			// it visited and push it onto the queue
			for (itr = adj[s].begin(); itr != adj[s].end(); ++itr)
			{
				if(!visited[*itr])
					{
						visited[*itr] = true;
						queue.push_back(*itr);
					}

			}
		}
	}
};

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}