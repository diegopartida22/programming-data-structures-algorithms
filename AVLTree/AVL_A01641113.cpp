#include <iostream>
using namespace std;

// AVL Tree Node
// Author: Diego Partida Romero A01641113
// Date: 23/10/2022

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node *parent;
};

class AVLTree
{
private:
    Node *AT;
    int n, numNodes;

public:
    AVLTree()
    {
        AT = NULL;
        n = 0;
        numNodes = 0;
    }
    ~AVLTree()
    {
        delete AT;
    }

    void insert(int);     // time complexity: O(log n)
    void deleteNode(int); // time complexity: O(log n)
    void find(int);       // time complexity: O(log n)
    void printTree();     // time complexity: O(n)
    void size();          // time complexity: O(1)
};

// Insert a node Time complexity: O(log n)
void AVLTree::insert(int num)
{
    Node *newNode = new Node;
    newNode->value = num;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    if (AT == NULL)
    {
        AT = newNode;
        numNodes++;
    }
    else
    {
        Node *temp = AT;
        while (temp != NULL)
        {
            if (num < temp->value)
            {
                if (temp->left == NULL)
                {
                    temp->left = newNode;
                    newNode->parent = temp;
                    numNodes++;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (num > temp->value)
            {
                if (temp->right == NULL)
                {
                    temp->right = newNode;
                    newNode->parent = temp;
                    numNodes++;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                break;
            }
        }
    }
}

// Delete a node Time complexity: O(log n)
void AVLTree::deleteNode(int num)
{
    Node *temp = AT;
    while (temp != NULL)
    {
        if (num < temp->value)
        {
            temp = temp->left;
        }
        else if (num > temp->value)
        {
            temp = temp->right;
        }
        else
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                if (temp->parent->left == temp)
                {
                    temp->parent->left = NULL;
                }
                else
                {
                    temp->parent->right = NULL;
                }
                delete temp;
                numNodes--;
            }
            else if (temp->left == NULL)
            {
                if (temp->parent->left == temp)
                {
                    temp->parent->left = temp->right;
                }
                else
                {
                    temp->parent->right = temp->right;
                }
                delete temp;
                numNodes--;
            }
            else if (temp->right == NULL)
            {
                if (temp->parent->left == temp)
                {
                    temp->parent->left = temp->left;
                }
                else
                {
                    temp->parent->right = temp->left;
                }
                delete temp;
                numNodes--;
            }
            else
            {
                Node *temp2 = temp->right;
                while (temp2->left != NULL)
                {
                    temp2 = temp2->left;
                }
                temp->value = temp2->value;
                if (temp2->parent->left == temp2)
                {
                    temp2->parent->left = temp2->right;
                }
                else
                {
                    temp2->parent->right = temp2->right;
                }
                delete temp2;
                numNodes--;
            }
            break;
        }
    }
}

// Find a node Time complexity: O(log n)
void AVLTree::find(int num)
{
    Node *temp = AT;
    while (temp != NULL)
    {
        if (num < temp->value)
        {
            temp = temp->left;
        }
        else if (num > temp->value)
        {
            temp = temp->right;
        }
        else
        {
            cout << "Found" << endl;
            break;
        }
    }
    if (temp == NULL)
    {
        cout << "Not Found" << endl;
    }
}

// Print the tree Time complexity: O(n)
void AVLTree::printTree()
{
    if (AT == NULL)
    {
        cout << "Empty" << endl;
    }
    else
    {
        Node *temp = AT;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        while (temp != NULL)
        {
            cout << temp->value << " ";
            if (temp->right != NULL)
            {
                temp = temp->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
            }
            else
            {
                while (temp->parent != NULL && temp->parent->right == temp)
                {
                    temp = temp->parent;
                }
                temp = temp->parent;
            }
        }
        cout << endl;
    }
}

// Print the size of the tree Time complexity: O(1)
void AVLTree::size()
{
    cout << numNodes << endl;
}

int main()
{
    cout << "AVL Tree" << endl;
    cout << "Author: Diego Partida Romero A01641113" << endl;
    cout << "Date: 23/10/2022" << endl;
    cout << "- - - - - - - - - - - - - - - " << endl;
    cout << "\n\tTest Case 1\n"
         << endl;
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    // Print Tree
    cout << "Print Tree: ";
    tree.printTree();

    // Find 30
    cout << "Find 30: ";
    tree.find(30);

    // Find 35
    cout << "Find 35: ";
    tree.find(35);

    // Delete 30
    cout << "Delete 25";
    tree.deleteNode(25);

    // Print Tree
    cout << "\nPrint Tree: ";
    tree.printTree();

    // Size
    cout << "Size: ";
    tree.size();

    // Test cases
    cout << "- - - - - - - - - - - - - - - " << endl;
    cout << "\n\tTest Case 2\n"
         << endl;
    AVLTree tree2;
    for (int i = 0; i < 10; i++)
    {
        tree2.insert(i);
    }
    cout << "Print Tree: ";
    tree2.printTree();
    cout << "Size: ";
    tree2.size();
    cout << "Delete 10" << endl;
    tree2.deleteNode(9);
    cout << "Print Tree: ";
    tree2.printTree();
    cout << "Size: ";
    tree2.size();
    cout << "Find 6" << endl;
    tree2.find(6);

    // Test case 3
    cout << "- - - - - - - - - - - - - - - " << endl;
    cout << "\n\tTest Case 3\n"
         << endl;
    AVLTree tree3;
    for (int i = 0; i < 5; i++)
    {
        tree3.insert(i + 10);
    }
    cout << "Print Tree: ";
    tree3.printTree();
    cout << "Size: ";
    tree3.size();
    cout << "Delete 14" << endl;
    tree3.deleteNode(14);
    cout << "Print Tree: ";
    tree3.printTree();
    cout << "Size: ";
    tree3.size();
    cout << "Find 13" << endl;
    tree3.find(13);

    // Test case 4
    cout << "- - - - - - - - - - - - - - - " << endl;
    cout << "\n\tTest Case 4\n"
         << endl;
    AVLTree tree4;
    int cont = 0;
    for (int i = 0; i < 5; i++)
    {
        tree4.insert(i + cont);
        cont += 10;
    }
    cout << "Print Tree: ";
    tree4.printTree();
    cout << "Size: ";
    tree4.size();
    cout << "Delete 44" << endl;
    tree4.deleteNode(44);
    cout << "Print Tree: ";
    tree4.printTree();
    cout << "Size: ";
    tree4.size();
    cout << "Find 44" << endl;
    tree4.find(44);
    return 0;
}
