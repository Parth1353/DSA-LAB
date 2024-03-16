#include <iostream>
#include <vector>
using namespace std;

class CustomQueue{
public: 
    int front_index;      
    int rear_index;    
    vector<int> elements;

    CustomQueue(int size){
        front_index = 0;
        rear_index = 0;
        vector<int> v(size);
        elements = v;
    }

    void add(int val){
        if(rear_index == elements.size()){
            cout<<"Queue is FULL!!!"<<endl;
            return;
        }
        elements[rear_index] = val;
        rear_index++;
    }

    void remove(){
        if(front_index == rear_index){   
            cout<<"Queue is EMPTY!!!"<<endl;
            return;
        }
        front_index++;
    }

    int peekFront(){
        if(front_index == rear_index){   
            cout<<"Queue is EMPTY!!!"<<endl;
            return -1;
        }
        return elements[front_index];
    }

    int peekBack(){
        if(front_index == rear_index){  
            cout<<"Queue is EMPTY!!!"<<endl;
            return -1;
        }
        return elements[rear_index-1];
    }

    int getSize(){
        return rear_index - front_index;
    }

    bool isEmpty(){
        return rear_index - front_index == 0;
    }

    void display(){
        for(int i=front_index; i<rear_index; i++){
            cout<<elements[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    CustomQueue myQueue(7);   
    int choice;

    do{
        cout<<"Enter your choice : ";
        cin>>choice;
        switch (choice) {
        case 1:
            cout<<"Push Done"<<endl;
            myQueue.add(10);
            myQueue.add(20);
            myQueue.add(30);
            myQueue.add(40);
            myQueue.add(50);
            myQueue.add(60);
            myQueue.add(70);
            break;
        case 2:
            cout<<"Pop Done"<<endl;
            myQueue.remove();
            break;
        case 3:
            cout<<"Front element is : "<<myQueue.peekFront()<<endl;
            break;
        case 4:
            cout<<"Back element is : "<<myQueue.peekBack()<<endl;
            break;
        case 5:
            cout<<"Size is : "<<myQueue.getSize()<<endl;
            break;
        case 6:      
            cout<<"Empty or not : "<<myQueue.isEmpty()<<endl;
            break;
        case 7:
            myQueue.display();
            break;
        default:
            cout << "Invalid choice" <<endl;
            return -1; 
        }
    } while(choice != 7);
    return 0;
}
