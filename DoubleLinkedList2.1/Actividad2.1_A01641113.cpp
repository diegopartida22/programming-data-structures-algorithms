#include <iostream>
using namespace std;

// Diego Partida Romero A01641113
// Date: 25/09/2022
// Actividad 2.1 : Double Linked List

struct Node
{
    int val;
    Node *next;
    Node *prev;
};

// Insert Functions "Create"
Node *insertNodeBegin(Node *head, int val) // Time Complexity O(1)
{
    Node *newNode = new Node();
    newNode->val = val;
    newNode->prev = newNode->next = NULL;
    if (head)
    {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
};

Node *insertNodeEnd(Node *head, int val) // Time Complexity O(n)
{
    Node *newNode = new Node();
    newNode->val = val;
    newNode->prev = newNode->next = NULL;
    if (head)
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return newNode;
};

// Del Function "Delete"
Node *delNode(Node *head, int val) // Time Complexity O(n)
{
    if (head)
    {
        Node *temp = head;
        while (temp->next)
        {
            if (temp->val == val)
            {
                if (temp->prev)
                {
                    temp->prev->next = temp->next;
                }
                else
                {
                    head = temp->next;
                }
                if (temp->next)
                {
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return head;
            }
            temp = temp->next;
        }
    }
    return head;
};

// Search Function "Read"
int searchNode(Node *head, int val) // O(n)
{
    int index = 0;
    Node *temp = head;
    while (temp)
    {
        if (temp->val == val)
        {
            return index;
        }

        temp = temp->next;
        index++;
    }
    cout << "Value not found ";
    return -1;
}

// Update Function
Node *updateNode(Node *head, int val, int newVal) // Time Complexity O(n)
{
    if (head)
    {
        Node *temp = head;
        while (temp->next)
        {
            if (temp->val == val)
            {
                temp->val = newVal;
                break;
            }
            temp = temp->next;
        }
    }
    return head;
};

// Print Function
void printDoubleLinkedList(Node *head) // Time Complexity O(n)
{
    if (head)
    {
        Node *temp = head;
        while (temp->next)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << temp->val << endl;
    }
}

int main()
{
    cout << "Diego Partida Romero A01641113" << endl;
    cout << "Date: 25/09/2022" << endl;
    cout << "Actividad 2.1 : Double Linked List" << endl;
    cout << "- - - - - - - - - - - " << endl;

    Node *head = NULL;

    head = insertNodeBegin(head, 1);
    head = insertNodeBegin(head, 2);
    head = insertNodeBegin(head, 3);
    head = insertNodeBegin(head, 4);
    head = insertNodeBegin(head, 5);
    head = insertNodeBegin(head, 6);
    head = insertNodeBegin(head, 7);
    head = insertNodeBegin(head, 8);
    head = insertNodeBegin(head, 9);
    head = insertNodeBegin(head, 10);

    cout << "Double Linked List: ";
    printDoubleLinkedList(head);

    head = insertNodeBegin(head, 11);
    cout << "Insert Node Begin: ";
    printDoubleLinkedList(head);

    head = delNode(head, 11);
    cout << "Delete Node: ";
    printDoubleLinkedList(head);

    head = updateNode(head, 10, 100);
    cout << "Update Node: ";
    printDoubleLinkedList(head);

    cout << "- - - - - - - - - - - " << endl;
    cout << "Index of value '9': " << searchNode(head, 9) << endl;
    cout << "Index of value '100': " << searchNode(head, 100) << endl;
    cout << "Index of value '17': " << searchNode(head, 17) << endl
         << endl;

    return 0;
}