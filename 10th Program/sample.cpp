#include <iostream>
#include <vector>
using namespace std;

class MaxPriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    MaxPriorityQueue() {}

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int getMax() {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty");
        }
        return heap[0];
    }

    int extractMax() {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty");
        }
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MaxPriorityQueue pq;

    cout << "Max Priority Queue using Max Heap" << endl;
    cout << "Enter elements to insert into the priority queue (-1 to stop):" << endl;

    int value;
    while (true) {
        cout << "Enter value: ";
        cin >> value;

        if (value == -1) {
            break;
        }

        pq.insert(value);
    }

    cout << "Max Element in the priority queue: " << pq.getMax() << endl;

    cout << "Extracting elements in descending order:" << endl;
    while (!pq.isEmpty()) {
        cout << pq.extractMax() << " ";
    }
    cout << endl;

    return 0;
}
