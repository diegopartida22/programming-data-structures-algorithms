#include <iostream>
#include <math.h>
using namespace std;

// Author: Diego Partida Romero A01641113
// Date: 17/10/2022
// HEAP TREE

struct Node
{
    int value;
    int priority;
    Node *left;
    Node *right;
    Node *parent;
};

class HeapTree
{
private:
    Node *HT;
    int N, NumNodes;

public:
    HeapTree(int size)
    {
        HT = new Node[size];
        N = size;
        NumNodes = 0;

        for (int i = 0; i < N; i++)
        {
            HT[i].value = 0;
            HT[i].priority = 0;
            HT[i].left = NULL;
            HT[i].right = NULL;
            HT[i].parent = NULL;
        }
    }
    ~HeapTree()
    {
        delete[] HT;
    }

    void Push(int, int); // Insert a new node - Time complexity: O(log n)
    void Pop();          // Remove the root node - Time complexity: O(log n)
    void Print();        // Print the tree - Time complexity: O(n)
    int Top();           // Return the value of the root node - Time complexity: O(1)
    int Size();          // Return the number of nodes in the tree - Time complexity: O(1)
    bool Empty();        // Return true if the tree is empty - Time complexity: O(1)
};

// Push a new element into the heap tree maintaining the heap property MaxHeap
void HeapTree::Push(int value, int priority)
{
    if (NumNodes == N)
    {
        cout << "Heap is full" << endl;
        return;
    }

    int i = NumNodes;
    HT[i].value = value;
    HT[i].priority = priority;
    NumNodes++;

    while (i > 0 && HT[i].priority > HT[(i - 1) / 2].priority)
    {
        int temp = HT[i].priority;
        HT[i].priority = HT[(i - 1) / 2].priority;
        HT[(i - 1) / 2].priority = temp;

        temp = HT[i].value;
        HT[i].value = HT[(i - 1) / 2].value;
        HT[(i - 1) / 2].value = temp;

        i = (i - 1) / 2;
    }
}

// Remove the root node from the heap tree maintaining
void HeapTree::Pop()
{
    if (NumNodes == 0)
    {
        cout << "Heap is empty" << endl;
        return;
    }

    HT[0] = HT[NumNodes - 1];
    NumNodes--;

    int i = 0;
    while (i < NumNodes)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left >= NumNodes)
            break;

        int max = left;
        if (right < NumNodes && HT[right].priority > HT[left].priority)
            max = right;

        if (HT[i].priority < HT[max].priority)
        {
            swap(HT[i], HT[max]);
            i = max;
        }
        else
            break;
    }
}

// Print the heap tree as a tree structure
void HeapTree::Print()
{
    if (NumNodes == 0)
    {
        cout << "Heap is empty" << endl;
        return;
    }

    int i = 0;
    int level = 0;
    int count = 0;
    while (i < NumNodes)
    {
        cout << HT[i].value << " ";
        i++;
        count++;
        if (count == pow(2, level))
        {
            cout << endl;
            level++;
            count = 0;
        }
    }
    cout << endl;
}

// Return the value of the root node
int HeapTree::Top()
{
    if (NumNodes == 0)
    {
        cout << "Heap is empty" << endl;
        return -1;
    }

    return HT[0].value;
}

int HeapTree::Size()
{
    return NumNodes;
}

// Check if the heap tree is empty return true if it is empty
bool HeapTree::Empty()
{
    if (NumNodes == 0)
        return true;
    else
        return false;
}

// MAIN
int main()
{
    cout << "Heap Tree" << endl;
    cout << "Author: Diego Partida Romero A01641113" << endl;
    cout << "Date: 17/10/2022" << endl;
    cout << "----------------------------------------" << endl;
    int size;
    cout << "Enter the size of the heap: ";
    cin >> size;
    HeapTree HT(size);
    // Pushing elements into the heap tree
    for (int i = 0; i < size; i++)
    {
        HT.Push(i, i);
    }
    // Printing the heap
    cout << "Heap" << endl;
    HT.Print();
    // Popping the top element
    cout << "- - - - - - - - - - - -" << endl;
    cout << "Popping the top element" << endl;
    HT.Pop();
    HT.Print();

    // Printing the top element
    cout << "- - - - - - - - - - - -" << endl;
    cout << "Top element: " << HT.Top() << endl;

    // Printing the size of the heap
    cout << "- - - - - - - - - - - -" << endl;
    cout << "Size of the heap: " << HT.Size() << endl;

    // Printing if the heap is empty
    cout << "- - - - - - - - - - - -" << endl;
    cout << "Is the heap empty? " << HT.Empty() << endl;

    // Create 3 more heaps with random numbers and sizes
    cout << "- - - - - - - - - - - -\n"
         << endl;
    cout << "TEST CASES" << endl;
    HeapTree HT1(10);
    for (int i = 0; i < 10; i++)
    {
        HT1.Push(rand() % 100, rand() % 100);
    }

    HeapTree HT2(5);
    for (int i = 0; i < 5; i++)
    {
        HT2.Push(rand() % 100, rand() % 100);
    }

    HeapTree HT3(15);
    for (int i = 0; i < 15; i++)
    {
        HT3.Push(rand() % 100, rand() % 100);
    }

    cout << "\n- - - - - - - - - - - -" << endl;
    cout << "Heap 1" << endl;
    HT1.Print();
    cout << "- - - - - - - - - - - -" << endl;
    cout << "Popping the top element" << endl;
    HT1.Pop();
    HT1.Print();
    cout << "- - - - - - - - - - - -" << endl;
    cout << "Top element: " << HT1.Top() << endl;
    cout << "- - - - - - - - - - - -" << endl;
    cout << "Size of the heap: " << HT1.Size() << endl;
    cout << "- - - - - - - - - - - -" << endl;
    cout << "Is the heap empty? " << HT1.Empty() << endl;

    cout << "- - - - - - - - - - - -" << endl;
    cout << "\nHeap 2" << endl;
    HT2.Print();
    cout << "- - - - - - - - - - - -" << endl;
    cout << "Popping the top element" << endl;
    HT2.Pop();
    HT2.Print();
    cout << "- - - - - - - - - - - -" << endl;
    cout << "Top element: " << HT2.Top() << endl;
    cout << "- - - - - - - - - - - -" << endl;
    cout << "Size of the heap: " << HT2.Size() << endl;
    cout << "- - - - - - - - - - - -" << endl;
    cout << "Is the heap empty? " << HT2.Empty() << endl;

    return 0;
}