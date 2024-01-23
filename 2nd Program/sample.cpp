#include <iostream>
using namespace std;
void bubble(int* arr, int size)
{
    for (int i = 0; i < size; i++) 
    {
bool FLAG = false;
 for (int j = 0; j < (size - i - 1); j++) 
 {
if (arr[j] > arr[j + 1]) 
{
     swap(arr[j], arr[j + 1]);
FLAG = true;
            }
        }
  if (FLAG!=true) {
            break;
        }
    }
}

int main() {
    int size;

    cout << "the size";
    cin >> size;
int* A = new int[size];
cout << "the elements" << endl;
    for (int i = 0; i < size; ++i) {
 cin >> A[i];
    }
bubble(A, size);
    for (int i = 0; i < size; ++i) {
        cout << " " << A[i];
    }


    return 0;
}
