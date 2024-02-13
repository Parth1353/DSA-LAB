#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    };
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "DELETION DONE" << endl;
    };
};
void printList(Node *&head)
{
    if (head == NULL)
    {
        cout << "EMPTY" << endl;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        cout << "data value" << temp->data << endl;
        temp = temp->next;
    }
};
void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        temp = head;
        return;
    }
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
};
void insertAtTail(Node *&tail, Node *&head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        Node *temp = new Node(d);
        temp = head;
        return;
    }
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
};
void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    Node *temp = head;
    int i = 0;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }
    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
};
void deleteNode(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    Node *current = head;
    Node *previous = NULL;
    int j = 0;
    while (j <= position)
    {
        previous = current;
        current = current->next;
        j++;
    }
    previous->next = current->next;
    current->next = NULL;
    delete current;
};