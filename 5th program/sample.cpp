#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* next;
};

int getLength(Node* head) {
    int count = 0;
    while (head != nullptr) {
        head = head->next;
        count++;
    }
    return count;
}

void insertNode(Node*& head, int position, int length) {
    Node* newNode = new Node;
    if (newNode == nullptr) {
        cout << "Memory allocation failed" << endl;
        return;
    }
    cout << "Enter the number for the new node: ";
    cin >> newNode->num;
    newNode->next = nullptr;

    Node* temp = head;
    if (temp == nullptr) {
        head = newNode;
        return;
    }

    if (position == length) {
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        int count = 1;
        while (count < position && temp->next != nullptr) {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNode(Node*& head, int position) {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    int count = 1;
    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Invalid position" << endl;
        return;
    }

    Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    delete nodeToDelete;
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }

    cout << "Linked list contents:" << endl;
    while (head != nullptr) {
        cout << head->num << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    int numNodes;
    cout << "Enter the number of nodes to create: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; ++i) {
        int value;
        cout << "Enter the value for node " << i + 1 << ": ";
        cin >> value;

        Node* newNode = new Node;
        if (newNode == nullptr) {
            cout << "Memory allocation failed" << endl;
            break;
        }

        newNode->num = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    displayList(head);

    int position;
    cout << "Enter the position to insert a new node: ";
    cin >> position;

    int length = getLength(head);
    insertNode(head, position, length);

    displayList(head);

    cout << "Enter the position to delete a node: ";
    cin >> position;

    deleteNode(head, position);

    displayList(head);
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
