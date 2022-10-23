#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *prev;
};

Node *insert_node_begin(Node *head, int val)
{
    Node *new_node = new Node();
    new_node->val = val;
    new_node->prev = new_node->next = NULL;
    if (head)
    {
        new_node->next = head;
        head->prev = new_node;
    }
    return new_node;
};

// end, after, delete

Node *insert_node_end(Node *head, int val)
{
    Node *new_node = new Node();
    new_node->val = val;
    new_node->prev = new_node->next = NULL;
    if (head)
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    return new_node;
};

Node *insert_node_after(Node *head, int val)
{
    Node *new_node = new Node();
    new_node->val = val;
    new_node->prev = new_node->next = NULL;
    if (head)
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    return new_node;
};

Node *delete_node(Node *head, int val)
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
                if (temp->next)
                {
                    temp->next->prev = temp->prev;
                }
                delete temp;
                break;
            }
            temp = temp->next;
        }
    }
    return head;
};

void print_double_linked_list(Node *head)
{
    cout << "NULL <- ";
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->val << " <-> ";
        curr = curr->next;
    }
    cout << "NULL " << endl;
}

int main()
{
    Node *head = NULL;
    head = insert_node_begin(head, 10);
    head = insert_node_after(head, 20);
    head = insert_node_end(head, 70);
    head = insert_node_begin(head, 60);
    head = delete_node(head, 10);

    print_double_linked_list(head);

    cout << head->val << " Double Linked List are easy!";

    return 0;
}
