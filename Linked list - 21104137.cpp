// Doubly linked list with family members as elements (21104137)
#include <iostream>
#include <string>
using namespace std;
 
// A linked list node
class Node {
public:
    string name; // family member's name
    int age; // family member's age
    Node* next;
    Node* prev;
};
 
// function to add a new node at the end
void append(Node** head_ref, string memberName, int memberAge)
{
    // allocate node
    Node* new_node = new Node();
 
    Node* last = *head_ref; 
 
    // set data
    new_node->name = memberName;
    new_node->age = memberAge;
 
    // Make the next node null
    new_node->next = NULL;
 
    // If the Linked List is empty, then make the new node as head
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
 
    // Else traverse till the last node
    while (last->next != NULL)
        last = last->next;
 
    // Change the next of last node
    last->next = new_node;
 
    // Make last node as previous of new node
    new_node->prev = last;
}
 
// function to display the list
void printList(Node* node)
{
    Node* last;
    cout << "\nTraversal in decreasing order of age.\n";
    while (node != NULL) {
        cout << "Name: " << node->name << ", Age: " << node->age << "   ";
        last = node;
        node = node->next;
    }
    cout << endl;
    cout << "\nTraversal  in increasing order of age. \n";
    while (last != NULL) {
        cout << "Name: " << last->name << ", Age: " << last->age << "   ";
        last = last->prev;
    }
    cout << "\n\n";
}

int main()
{
    // Start with the empty list
    Node* head = NULL;
 
    // add family member's names
    append(&head, "Rajinder Kumar", 47);
    append(&head, "Geeta", 43);
    append(&head, "Kanishk", 20);
    append(&head, "Nishtha", 15);

    printList(head); // displaying the list
}
