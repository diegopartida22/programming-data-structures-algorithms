#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;


struct Node
{
    int data;           
    Node *left, *right; 
    Node(int d) : data(d), left(NULL), right(NULL) {} 
};

class BST
{
private:
    Node *Root; 
    void Insert(int &, Node *&); // Insert a node in BST     // O(log n)
    void InOrder(Node *);        // Print BST in InOrder     // O(n)
    void PreOrder(Node *);       // Print BST in PreOrder    // O(n)
    void PostOrder(Node *);      // Print BST in PostOrder   // O(n)
    void DeleteNode(int &, Node *&);
    void height(Node *root, int &h, int &max_h);
    void whatLevelAmI(Node *root, int &value, int &level, int &current_level);
    void ancestors(Node *root, int &value);


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
    void BFT();                                      // Print BST in Breadth First Traversal // O(n)

    void SubstituteToMin(Node *&, Node *&);                  // Substitute a node with the minimum value in the right subtree,
    void DeleteNode(int &value) { DeleteNode(value, Root); } // Delete a node from BST
    void DeleteBST(Node *&); // Delete the BST         // O(n) (worst case) or O(log n) (best case) or O(n) (average case)


};

void BST::Insert(int &value, Node *&root) // We use reference to avoid copying the value, if you modified the value in the function it also modified out of the function
{
    if (root == NULL)
    {
        root = new Node(value);
    }

    else
    {
        if (value < root->data) // if value is less than the data of the root, go to the left
        {
            Insert(value, root->left); // recursive call to insert the value in the left subtree of the root
        }

        else if (value > root->data) // if value is greater than the data of the root, go to the right
        {
            Insert(value, root->right); // recursive call to insert the value in the right subtree of the root
        }

        else // if value is equal to the data of the root, do nothing
        {
            cout << "Repeated element\n";
        }
    }
}

// The PreOrder function is generally a recursive function as well and moves through the leves of the tree in the following order: root, left, right
//    A
// B     C                       PreOrder: A B C
void BST::PreOrder(Node *root)
{
    if (root != NULL)
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
    if (root != NULL)
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
void BST::PostOrder(Node *root) // print the brothers of the root first
{
    if (root != NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

// The Breadth First Traversal function is generally a non-recursive function and moves through the leves of the tree in the following order: root, left, right
void BST::BFT()
{
    if (Root == NULL)
    {
        cout << "The BST is empty" << endl;
        return;
    }

    queue<Node *> Q; // queue to store the nodes of the tree
    Q.push(Root);    // push the root of the tree in the queue

    Node *Aux; // Auxiliar pointer to store the nodes of the tree
    while (!Q.empty())
    {
        Q.push(NULL);

        Aux = Q.front(); // get the first element of the queue

        while (Aux != NULL)
        {
            cout << Aux->data << " "; // print the data of the node

            if (Aux->left != NULL) // if the left child of the node is not NULL, push it in the queue
            {
                Q.push(Aux->left);
            }

            if (Aux->right != NULL) // if the right child of the node is not NULL, push it in the queue
            {
                Q.push(Aux->right);
            }

            Q.pop();         
            Aux = Q.front(); // get the first element of the queue
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
        SubstituteToMin(root, apAux);
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

void BST::DeleteNode(int &value, Node *&root)
{
    if (root == NULL)
    {
        cout << "The BST is empty" << endl;
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

        if (apAux->right == NULL) // only left child node
        {
            root = apAux->left;
        }

        if (apAux->left == NULL) // only right child node
        {
            root = apAux->right;
        }
        if (apAux->left != NULL && apAux->right != NULL) // two children
        {
            SubstituteToMin(root->right, apAux);
        }

        cout << "\nThe key to be deleted is: " << value << endl;
        cout << "The node " << apAux->data << " was deleted" << endl;
        delete apAux;
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

void BST::height(Node *root, int &h, int &max)
{
    if (root != NULL)
    {
        h++;
        if (h > max)
        {
            max = h;
        }
        height(root->left, h, max);
        height(root->right, h, max);
        h--;
    }
}

void BST::whatLevelAmI(Node *root, int &value, int &level, int &current_level)
{
    if (root != NULL)
    {
        current_level++;
        if (root->data == value)
        {
            level = current_level;
        }
        whatLevelAmI(root->left, value, level, current_level);
        whatLevelAmI(root->right, value, level, current_level);
        current_level--;
    }
}

void BST::ancestors(Node *root, int &value)
{
    if (root != NULL)
    {
        if (root->data == value)
        {
            return;
        }
        else
        {
            cout << root->data << " ";
            if (value < root->data)
            {
                ancestors(root->left, value);
            }
            else
            {
                ancestors(root->right, value);
            }
        }
    }
}

int main()
{
    system("cls");


    BST A;
    vector<int> v = {47, 60, 22, 12, 6, 13, 41, 20, 52, 16};
    for (int i : v)
    {
        A.Insert(i);
    }

    cout << "InOrder: ";
    A.InOrder();

    cout << "\nPreOrder: ";
    A.PreOrder();

    cout << "\nPostOrder: ";
    A.PostOrder();

    cout << "\nBreadth First Traversal: ";
    A.BFT();

    int value = 22;
    A.DeleteNode(value);

    // Ancestors



    int a = 16; // leaf node
    A.DeleteNode(a);
    A.BFT();

    a = 13; // node with one child
    A.DeleteNode(a);
    A.BFT();

    a = 10; // node with two children
    A.DeleteNode(a);
    A.BFT();

    return 0;
}
