
#include <iostream>
#include <list>

using namespace std;

// Author: Diego Partida Romero A01641113
// Date: 7/11/2022

class Graph
{
private:
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int V)
    {
        numVertices = V;
        adjLists = new list<int>[V];
        visited = new bool[V];
    }

    ~Graph()
    {
        delete[] adjLists;
        delete[] visited;
    }

    void addEdge(int, int);
    void printGraph();
    void ResetVisited();
    void loadGraph();

    void DFS(int);
    void BFS(int);
};

void Graph::addEdge(int s, int d)
{
    this->adjLists[s].push_back(d);
}

void Graph::printGraph()
{
    for (int i = 0; i < this->numVertices; i++)
    {
        cout << "\nVertex " << i << ":";
        for (auto x : this->adjLists[i])
            cout << " -> " << x;
        cout << endl;
    }
}

void Graph::ResetVisited()
{
    for (int i = 0; i < this->numVertices; i++)
        this->visited[i] = false;
}

//  DFS Function complexity - O(V + E) = O(V)
// V = number of nodes, E = number of edges, the space complexity is O(V)
void Graph::DFS(int vertex)
{
    this->visited[vertex] = true;
    list<int> adjVertex = this->adjLists[vertex];

    cout << vertex << "  ";

    for (auto i : adjVertex)
        if (!this->visited[i])
            DFS(i);
}

// BFS Function complexity - O(V + E) = O(V)
void Graph::BFS(int startVertex)
{
    visited[startVertex] = true;

    list<int> queue;
    queue.push_back(startVertex);

    while (!queue.empty())
    {
        int currVertex = queue.front();
        cout << currVertex << "  ";
        queue.pop_front();

        for (auto i : adjLists[currVertex])
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}

// Print adjency matrix and adjency list
void Graph::loadGraph()
{
    int adjMatrix[this->numVertices][this->numVertices];

    for (int i = 0; i < this->numVertices; i++)
        for (int j = 0; j < this->numVertices; j++)
            adjMatrix[i][j] = 0;

    for (int i = 0; i < this->numVertices; i++)
    {
        for (int x : this->adjLists[i])
            adjMatrix[i][x] = 1;
    }

    cout << "\nAdjency List: " << endl;
    for (int i = 0; i < this->numVertices; i++)
    {
        cout << i << " -> ";
        for (auto x : this->adjLists[i])
            cout << x << " ";
        cout << endl;
    }

    cout << "\nAdjency Matrix: " << endl;
    for (int i = 0; i < this->numVertices; i++)
    {
        for (int j = 0; j < this->numVertices; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    cout << "Author: Diego Partida Romero A01641113\nDate: 7/11/22" << endl;

    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 1);
    g.addEdge(6, 3);
    g.addEdge(6, 5);
    g.addEdge(6, 6);

    g.loadGraph();

    cout << "\nDFS: ";
    g.DFS(1);

    g.ResetVisited();

    cout << "\n\nBFS: ";
    g.BFS(0);
    cout << endl;

    return 0;
}
