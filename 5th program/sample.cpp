#include <iostream>
using namespace std;

class Node{
public:
    int num;
    Node* next;
    Node(){

    }
    Node(int num){
        this->num = num;
        this->next = NULL;
    }
};

int getLength(Node* head){
    int count = 0;
    while(head != NULL){
        head = head->next;
        count++;
    }
    return count;
}

void insertNode(Node*& head, int position, int length) {
    Node* newNode = new Node(8);
    Node* temp = head;
    if (temp == NULL) {
        head = newNode;
        return;
    }
    if (position == length) {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }
    else {
        int count = 1;
        while (count < position && temp->next != NULL) {
            temp = temp->next;
            count++;
        }
        Node* previous = temp->next;
        temp->next = newNode;
        newNode->next = previous;
        return;
    }
}

void deleteNode(Node* head, int position){
    if(head == NULL){
        cout << "Linked list is empty" << endl;
        return;
    }
    int count = 1;
    while(head != NULL){
        if(count == position){
            Node* nextNode = head->next;
            head->next = nextNode->next;
            return;
        }
        else{
            head = head->next;
            count++;
        }
    }
}

int main(){
    Node* current = new Node(3);
    Node* current1 = new Node(4);
    Node* current2 = new Node(5);
    Node* current3 = new Node(6);
    Node* current4 = new Node(8);
    Node* answer = current;
    answer->next = current1;
    answer = answer->next;
    answer->next = current2;
    answer = answer->next;
    answer->next = current3;
    answer = answer->next;
    answer->next = current4;
    answer = answer->next;
    Node* head = current;
    int length = getLength(head);
    int position;
    insertNode(head, 4, length);
    // insert(head,3);
    deleteNode(head, 5);
    while(current != NULL){
        cout << current->num << endl;
        current = current->next;
    }
}
