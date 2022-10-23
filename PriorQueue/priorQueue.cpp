#include <iostream>
using namespace std;

struct Node
{
    int value;
    int priority;
};

class PriorQueue
{
private:
    Node *PQ;
    int N, NumNodes;

public:
    PriorQueue(int size)
    {
        N = size;
        PQ = new Node[size]; // pointer node
        NumNodes = -1;
    }
    ~PriorQueue()
    {
        delete[] PQ;
    }

    void Push(int, int); // Time complexity: O(n)
    Node *Pop();         // Time complexity: O(1)
    int Peek();          // Time complexity: O(1)
    void Display(int);
    void Display();
};

// Return the value of the node with the highest priority
void PriorQueue::Push(int value, int priority) // Time comlexity O(1)
{
    if (NumNodes == N - 1) // check if the list is full
    {
        cout << "Priority Queue is full" << endl;
        return; // the return is to exit the function
    }

    // Increase the size
    NumNodes++;

    // Insert the element
    PQ[NumNodes].value = value;
    PQ[NumNodes].priority = priority;
}

// Pop the element with the highest priority
Node *PriorQueue::Pop() // Time complexity O(n)
{
    if (NumNodes == -1)
    {
        cout << "Priority Queue is empty" << endl;
        return NULL;
    }

    int ind = Peek(); // search in the list and pop the number with the highest priority

    Node *Aux = &PQ[ind];

    for (int i = ind; i < NumNodes; i++)
    {
        PQ[i] = PQ[i + 1]; // jump the index to move the list
    }

    NumNodes--;

    return Aux;
}

// Search in the list and return the index of the number with the highest priority
int PriorQueue::Peek() // Time complexity O(n)
{
    int highestPriority = INT_MIN; // call the minimum value (-2 147 433 648)
    int ind = -1;

    for (int i = 0; i <= NumNodes; i++)
    {
        if (highestPriority < PQ[i].priority)
        {
            highestPriority = PQ[i].priority;
            ind = i;
        }
        else if (highestPriority == PQ[i].priority && PQ[i].value > PQ[i].value)
        {
            highestPriority = PQ[i].priority;
            ind = i;
        }
    }

    return ind;
}

void PriorQueue::Display(int idx)
{
    cout << PQ[idx].value << endl
         << endl;
}

void PriorQueue::Display()
{
    cout << "Elements: ";

    for (int i = 0; i <= NumNodes; i++)
    {
        cout << PQ[i].value << " ";
    }
    cout << endl
         << endl;
}

int main()
{
    PriorQueue P(5);

    P.Push(10, 2);
    P.Push(14, 4);
    P.Push(16, 4);
    P.Push(12, 3);
    P.Display();

    int indx = P.Peek();
    cout << "Higher priority element: ";
    P.Display(indx);

    P.Pop();
    P.Display();

    indx = P.Peek();
    cout << "Higher priority element: ";
    P.Display(indx);

    P.Pop();
    P.Display();

    indx = P.Peek();
    cout << "Higher priority element: ";
    P.Display(indx);

    P.Pop();
    P.Display();

    P.Pop();
    P.Display();

    P.Pop();

    return 0;
}