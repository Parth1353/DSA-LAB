// #include <iostream>
// using namespace std;
// class Queue {
    
//     int* arr;
//     int qfront;
//     int rear; 
//     int size;
    
// public:
//     Queue() {
//         size = 100001;
//         arr = new int[size];
//         qfront = 0;
//         rear = 0;
//     }

//     bool isEmpty() {
//         if(qfront == rear) {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }

//     void enqueue(int data) {
//         if(rear == size)
//             cout << "Queue is Full" << endl;
//         else
//         {
//             arr[rear] = data;
//             rear++;
//         }
//     }

//     int dequeue() {
//         if(qfront == rear) {
//             return -1;
//         }
//         else
//         {	int ans = arr[qfront];
//             arr[qfront] = -1;
//             qfront++;
//             if(qfront==rear){
//                 qfront = 0;
//                 rear = 0;
//             }
//          return ans;
//         }
//     }
// int front() {
//         if(qfront == rear) {
//             return -1;
//         }
//         else
//         {
//             return arr[qfront];
//         }
//     }
// };     v#include <iostream>
using namespace std;
#include <iostream>
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
private:
    Node* qfront;
    Node* rear;

public:
    Queue() {
        qfront = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return (qfront == nullptr);
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);

        if (isEmpty()) {
            qfront = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        } else {
            int data = qfront->data;
            Node* temp = qfront;
            qfront = qfront->next;
            delete temp;
            return data;
        }
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        } else {
            return qfront->data;
        }
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Front element: " << myQueue.front() << endl;

    cout << "Dequeue: " << myQueue.dequeue() << endl;
    cout << "Front element after dequeue: " << myQueue.front() << endl;

    return 0;
}
