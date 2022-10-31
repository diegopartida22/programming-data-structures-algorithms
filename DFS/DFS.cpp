using namespace std;

#include <iostream>
#include <list>

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

    void DFS(int);
};

void Graph::addEdge(int s, int d)
{
    this->adjLists[s].push_back(d);
    this->adjLists[d].push_back(s);
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
void Graph::DFS(int vertex)
{
    this->visited[vertex] = true;
    list<int> adjVertex = this->adjLists[vertex];

    cout << vertex << " ";

    for (auto i : adjVertex)
        if (!this->visited[i])
            DFS(i);
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    g.ResetVisited();

    cout << "\nDFS: ";
    g.DFS(1);

    return 0;
}
