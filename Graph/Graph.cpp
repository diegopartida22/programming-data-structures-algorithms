
#include <iostream>
#include <list>

using namespace std;

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

    // new function load the arcs from the graph and store them in a adjancy matrix and a adjancy list
    void loadGraph();

    void DFS(int);
    void BFS(int);
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
// V = number of nodes, E = number of edges, the space complexity is O(V)
void Graph::DFS(int vertex)
{
    this->visited[vertex] = true;
    list<int> adjVertex = this->adjLists[vertex];

    cout << vertex << " ";

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

// Load graph function input
void Graph::loadGraph()
{
    int numArcs;
    int source, destination;

    cout << "Enter the number of arcs: ";
    cin >> numArcs;

    for (int i = 0; i < numArcs; i++)
    {
        cout << "Enter the source and destination of the arc: ";
        cin >> source >> destination;
        addEdge(source, destination);

        cout << "The graph is loaded" << endl;

        printGraph();
    }
}

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);

    g.printGraph();
    g.loadGraph();

    cout << "\nDFS: ";
    g.DFS(1);

    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 3);
    g2.addEdge(1, 2);
    g2.addEdge(2, 4);
    cout << "\nBFS: ";
    g2.BFS(0);

    return 0;
}
