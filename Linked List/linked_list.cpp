#include <iostream>
using namespace std;

struct linked_list
{ // se crea una estructura que contiene un valor
    /* data */
    int data;          // A B C
    linked_list *next; // apuntador al siguiente
} node;                // instancia de linked list

int main()
{
    linked_list *head;

    linked_list *new_node = new linked_list(); // se crea el nuevo nodo
    new_node->data = 8;
    new_node->next = NULL;

    head = new_node; // El apuntador head apunta al apuntador de new_node

    linked_list *new_node1 = new linked_list();
    new_node1->data = 10;
    new_node1->next = NULL;

    head->next = new_node1;

    linked_list *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << endl;

    return 1;
}