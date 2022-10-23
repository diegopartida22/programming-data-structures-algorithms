#include <iostream>
#include <queue>
using namespace std;

// A binary search tree is a binary tree in wich every node fits a specific ordering property
// all left descendents <= n < all right

struct Node
{
    int data;           // data of the node
    Node *left, *right; // right child

    Node(int d)
    {
        data = d;
        left = right = NULL;
    } // constructor for Node class
};

class BST
{
private:
    Node *Root;

    void Insert(int &, Node *&); // Insert a node in BST     // Time Complexity O(log n)
    void InOrder(Node *);        // Print BST in InOrder     // Time Complexity O(n)
    void PreOrder(Node *);       // Print BST in PreOrder    // Time Complexity O(n)
    void PostOrder(Node *);      // Print BST in PostOrder   // Time Complexity O(n)
    void LevelByLevel(Node *);   // Print BST level by level // Time Complexity O(n)
    void DeleteNode(int &, Node *&); // Delete a node from BST // Time Complexity O(log n)
    int height(Node *);             // Height of the tree      // Time Complexity O(n)
    void ancestors(Node *, int);   // Print ancestors of a node // Time Complexity O(n)
    int whatLevelAmI(Node *, int); // Return level of a node // Time Complexity O(n) 

public:
    BST() : Root(NULL){}; // Constructor to initialize Root to NULL, NULL is a pointer to nothing and is used to indicate that the node is empty or does not exist in the tree

    ~BST() // Destructor to free the memory allocated to the tree
    {
        DeleteBST(Root);
        cout << "\nDestructor: BST deleted\n";
    }

    // Functions to call the recursive functions (non-recursive)
    void Insert(int &value) { Insert(value, Root); } // Insert a node in BST    // O(log n)
    void InOrder() { InOrder(Root); }                // Print BST in InOrder    // O(n)
    void PreOrder() { PreOrder(Root); }              // Print BST in PreOrder   // O(n)
    void PostOrder() { PostOrder(Root); }            // Print BST in PostOrder  // O(n)
    void LevelByLevel() { LevelByLevel(Root); }      // Print BST level by level// O(n)
    void BFT();                                      // Print BST in Breadth First Traversal // O(n)

    void SubstituteToMin(Node *&, Node *&);                  // Substitute a node with the minimum value in the right subtree,
    void DeleteNode(int &value) { DeleteNode(value, Root); } // Delete a node from BST
    void visit(int);
    void DeleteBST(Node *&); // Delete the BST         // O(n) (worst case) or O(log n) (best case) or O(n) (average case)
    int height() { return height(Root); }
    void ancestors(int value) { ancestors(Root, value); }
    int whatLevelAmI(int value) { return whatLevelAmI(Root, value); }
    };

void BST::Insert(int &value, Node *&root) // We use reference to avoid copying the value, if you modified the value in the function it also modified out of the function
{
    if (root == NULL)
    {
        root = new Node(value);
    }

    else
    {
        if (value < root->data) 
        {
            Insert(value, root->left); 
        }

        else if (value > root->data) 
        {
            Insert(value, root->right); 
        }

        else 
        {
            cout << "Repeated element\n";
        }
    }
}

int BST::height(Node *root)
{
    if (root == NULL)
        return -1;
    else
    {
        int left_side = height(root->left);
        int right_side = height(root->right);

        return max(left_side, right_side) + 1;
    }
}

// The PreOrder function is generally a recursive function as well and moves through the leves of the tree in the following order: root, left, right
//    A
// B     C                       PreOrder: A B C
void BST::PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// The InOrder function is generally a recursive function as well and moves through the leves of the tree in the following order: left, root, right
//    B
// A     C                       InOrder: A B C
void BST::InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

// The PostOrder function is generally a recursive function as well and moves through the leves of the tree in the following order: left, right, root
//    C
// A     B                       PostOrder: A B C
void BST::PostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

// The LevelByLevel function is generally a recursive function as well and moves through the leves of the tree in the following order: root, left, right
//    A
// B     C                       LevelByLevel: A B C
void BST::LevelByLevel(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> Q; // queue to store the nodes of the tree
    Q.push(root);    // push the root of the tree in the queue

    while (!Q.empty()) // while the queue is not empty
    {
        Node *current = Q.front(); // get the first element of the queue
        Q.pop();                   // remove the first element of the queue

        cout << current->data << " "; // print the data of the current node

        if (current->left != NULL) // if the left child of the current node is not NULL
        {
            Q.push(current->left); // push the left child of the current node in the queue
        }

        if (current->right != NULL) // if the right child of the current node is not NULL
        {
            Q.push(current->right); // push the right child of the current node in the queue
        }
    }
}

// The Breadth First Traversal function is generally a non-recursive function and moves through the leves of the tree in the following order: root, left, right
void BST::BFT()
{
    if (Root == NULL)
    {
        cout << "The BST is empty" << endl;
        return;
    }

    queue<Node *> Q; 
    Q.push(Root);    

    Node *Aux; 
    while (!Q.empty())
    {
        Q.push(NULL);

        Aux = Q.front(); 

        while (Aux != NULL)
        {
            cout << Aux->data << " "; 

            if (Aux->left != NULL)
            {
                Q.push(Aux->left);
            }

            if (Aux->right != NULL) 
            {
                Q.push(Aux->right);
            }

            Q.pop();         
            Aux = Q.front(); 
        }
        Q.pop();

        cout << endl;
    }
}

// Substitute a node with the minimum value in the right subtree
void BST::SubstituteToMin(Node *&root, Node *&apAux)
{
    if (root->left != NULL)
    {
        SubstituteToMin(root->left, apAux);
    }
    else
    {
        // Transfer the data from the substitute node
        apAux->data = root->data;

        // Save the minValue-right subtree (To delete)
        apAux = root;

        // Swap place minValue-right subtree with right subtree
        root = root->right;
    }
}

// Delete a node from BST (Binary Search Tree)
void BST::DeleteNode(int &value, Node *&root)
{
    if (root == NULL)
    {
        cout << "The BST is empty" << endl;
        return;
    }

    if (value < root->data) 
    {
        DeleteNode(value, root->left); 
    }

    else if (value > root->data)
    {
        DeleteNode(value, root->right); 
    }

    else
    {
        Node *apAux = root; 

        if (root->left == NULL) 
        {
            root = root->right; 
        }

        else if (root->right == NULL)
        {
            root = root->left;
        }

        else 
        {
            SubstituteToMin(root->right, apAux);
        }

        delete apAux;
        cout << "\nNode to delete: " << value << endl;
        cout << "The node " << value << " was deleted" << endl;
    }
}

void BST::DeleteBST(Node *&root)
{
    if (root != NULL)
    {
        DeleteBST(root->left);
        DeleteBST(root->right);
        delete root;
    }
}

void BST::visit(int value)
{
    if (value == 1)
    {
        cout << "PreOrder: ";
        PreOrder(Root);
    }
    else if (value == 2)
    {
        cout << "InOrder: ";
        InOrder(Root);
    }
    else if (value == 3)
    {
        cout << "PostOrder: ";
        PostOrder(Root);
    }
    else if (value == 4)
    {
        cout << "LevelByLevel: ";
        LevelByLevel(Root);
    }
    else
    {
        cout << "Invalid option" << endl;
    }
}

int BST::whatLevelAmI(Node *root, int value)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == value)
    {
        return 1;
    }

    int level = whatLevelAmI(root->left, value);

    if (level != 0)
    {
        return level + 1;
    }

    level = whatLevelAmI(root->right, value);

    if (level != 0)
    {
        return level + 1;
    }

    return 0;
}


void BST::ancestors(Node *root, int value)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data == value)
    {
        return;
    }

    if (root->data > value)
    {
        cout << root->data << " ";
        ancestors(root->left, value);
    }
    else
    {
        cout << root->data << " ";
        ancestors(root->right, value);
    }
}


int main()
{
    system("clear");
    BST A;

    vector<int> v = {47, 60, 22, 12, 6, 13, 41, 20, 52, 16};
    for (int i : v)
    {
        A.Insert(i);
    }

    cout << "Author: Diego Partida Romero A01641113" << endl;
    cout << "Date: 17/10/2022" << endl;
    cout << "Binary Search Tree" << endl;
    cout << "- - - - - - - - - - - " << endl;
    cout << "Tree\n";
    A.BFT();
    cout << "\nThe height of the tree is: " << A.height() << endl;

    // VISIT
    cout << "- - - - - - - - - - - " << endl;
    cout << "VISIT FUNCTION\n" << endl;
    int option;
    cout << "Choose the way to visit the BST: " << endl;
    cout << "1. PreOrder" << endl;
    cout << "2. InOrder" << endl;
    cout << "3. PostOrder" << endl;
    cout << "4. LevelByLevel" << endl;
    cout << "Option: ";
    cin >> option;
    cout << endl;

    A.visit(option);
    cout << endl;

    A.BFT();

    cout << "- - - - - - - - - - - " << endl;
    cout << "DELETE LEAF NODE";
    int a = 16; // leaf node
    A.DeleteNode(a);

    A.BFT();
    cout << "The height of the BST is: " << A.height() << endl;
    
    int value;
    cout << "Enter the value to find the ancestors: ";
    cin >> value;
    cout << "The ancestors of " << value << " are: "; 
    A.ancestors(value);
    cout << endl;

    // WHAT LEVEL AM I
    cout << "Enter the value to find the level: ";
    cin >> value;
    cout << "The level of " << value << " is: " << A.whatLevelAmI(value) << endl;

    A.BFT();
    cout << "- - - - - - - - - - - " << endl;
    cout << "DELETE NODE WITH ONE CHILD";
    a = 13; 
    A.DeleteNode(a);
    A.BFT();
    cout << "The height of the BST is: " << A.height() << endl;

    cout << "Enter the value to find the ancestors: ";
    cin >> value;
    cout << "The ancestors of " << value << " are: "; 
    A.ancestors(value);
    cout << endl;

    cout << "Enter the value to find the level: ";
    cin >> value;
    cout << "The level of " << value << " is: " << A.whatLevelAmI(value) << endl;

    A.BFT();
    cout << "- - - - - - - - - - - " << endl;
    cout << "DELETE NODE WITH TWO CHILDREN";
    a = 47;
    A.DeleteNode(a);

    A.BFT();
    cout << "The height of the BST is: " << A.height() << endl;
    cout << "Enter the value to find the ancestors: ";
    cin >> value;
    cout << "The ancestors of " << value << " are: "; 
    A.ancestors(value);
    cout << endl;

    cout << "Enter the value to find the level: ";
    cin >> value;
    cout << "The level of " << value << " is: " << A.whatLevelAmI(value) << endl;

    return 0;
}
