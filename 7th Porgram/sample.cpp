#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* head;
    Node* tail;
    int size;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head->value;
    }

    int back() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return tail->value;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Front element is: " << q.front() << endl;
                break;
            case 4:
                cout << "Back element is: " << q.back() << endl;
                break;
            case 5:
                cout << "Size of queue is: " << q.getSize() << endl;
                break;
            case 6:
                cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
                break;
            case 7:
                cout << "Queue elements: ";
                q.display();
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
