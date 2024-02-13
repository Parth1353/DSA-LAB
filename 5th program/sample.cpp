#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head; 

public:
   
    LinkedList() {
        head = nullptr;
    } 
    void insert(int value) {
     
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head; 
        head = newNode; 
    }

    void remove(int value) {
        
        if (head == nullptr)
            return;


        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            return;
        }

      
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

       
        if (current != nullptr) {
            previous->next = current->next;
            delete current;
        }
    }

   
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

   
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

   
    int numElements;
    cout << "Enter the number of elements to insert: ";
    cin >> numElements;

    
    cout << "Enter the elements to insert:\n";
    for (int i = 0; i < numElements; ++i) {
        int value;
        cin >> value;
        list.insert(value);
    }

    cout << "Initial list: ";
    list.display();

   
    int deleteValue;
    cout << "Enter the element to delete: ";
    cin >> deleteValue;
    list.remove(deleteValue);

    cout << "List after deleting " << deleteValue << ": ";
    list.display();

    return 0;
}
