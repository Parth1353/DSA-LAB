#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string roll_no;
    string name;
    float cgpi;
    int semester;
    Student* next;
    Student(string roll_no, string name, float cgpi, int semester) {
        this->roll_no = roll_no;
        this->name = name;
        this->cgpi = cgpi;
        this->semester = semester;
        this->next = nullptr;
    }

    void display() {
        cout << "Roll No.: " << roll_no << endl;
        cout << "Name: " << name << endl;
        cout << "CGPI: " << cgpi << endl;
        cout << "Semester: " << semester << endl;
    }
};

class LinkedList {
private:
    Student* head;

public:
 
    LinkedList() {
        head = nullptr;
    }
    void insert(Student* new_student) {
        if (head == nullptr) {
            head = new_student;
        } else {
            Student* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_student;
        }
    }

    void displayRecords() {
        if (head == nullptr) {
            cout << "No records found." << endl;
        } else {
            Student* current = head;
            while (current != nullptr) {
                current->display();
                current = current->next;
            }
        }
    }

    void displayRecordsWithCGPI(float threshold) {
        bool found = false;
        Student* current = head;
        while (current != nullptr) {
            if (current->cgpi > threshold) {
                found = true;
                current->display();
            }
            current = current->next;
        }
        if (!found) {
            cout << "No records found with CGPI greater than " << threshold << endl;
        }
    }

    void insertAtPosition(Student* new_student, int position) {
        if (position <= 0) {
            cout << "Invalid position." << endl;
            return;
        }
        if (position == 1) {
            new_student->next = head;
            head = new_student;
        } else {
            int count = 1;
            Student* current = head;
            while (current != nullptr && count < position - 1) {
                current = current->next;
                count++;
            }
            if (current == nullptr) {
                cout << "Invalid position." << endl;
            } else {
                new_student->next = current->next;
                current->next = new_student;
            }
        }
    }
    Student* getHead() {
        return head;
    }
    ~LinkedList() {
        Student* current = head;
        while (current != nullptr) {
            Student* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList records;
    for (int i = 0; i < 5; ++i) {
        string roll_no, name;
        float cgpi;
        int semester;

        cout << "Enter details of student " << i + 1 << ":" << endl;
        cout << "Roll No.: ";
        cin >> roll_no;
        cout << "Name: ";
        cin >> name;
        cout << "CGPI: ";
        cin >> cgpi;
        cout << "Semester: ";
        cin >> semester;

        Student* new_student = new Student(roll_no, name, cgpi, semester);
        records.insert(new_student);
    }
    float threshold;
    cout << "\nEnter the CGPI threshold: ";
    cin >> threshold;
    cout << "Students with CGPI greater than " << threshold << ":" << endl;
    records.displayRecordsWithCGPI(threshold);
    int position;
    cout << "\nEnter the position to insert a new record: ";
    cin >> position;

    string new_roll_no, new_name;
    float new_cgpi;
    int new_semester;

    cout << "Enter details of new student:" << endl;
    cout << "Roll No.: ";
    cin >> new_roll_no;
    cout << "Name: ";
    cin >> new_name;
    cout << "CGPI: ";
    cin >> new_cgpi;
    cout << "Semester: ";
    cin >> new_semester;

    Student* new_student = new Student(new_roll_no, new_name, new_cgpi, new_semester);
    records.insertAtPosition(new_student, position);

    cout << "\nFinal records after insertion:" << endl;
    records.displayRecords();

    return 0;
}
