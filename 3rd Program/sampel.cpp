#include <iostream>
using namespace std;


int binary(int arr[], int size, int item) 
{
    int left = 0;
    int right = size - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

      
        if (arr[mid] == item) {
            return mid;
        }

       
        else if (arr[mid] < item) 
        {
            left = mid + 1;
        }

      
        else 
        {
            right = mid - 1;
        }
    }

  
    return -1;
}
void deleteorinsert(int *&arr, int &size, int item) 
{
    int index = binary(arr, size, item);
    
    if (index != -1)
    {
        // Deleting item
        for (int i = index + 1; i < size; ++i) {
            arr[i - 1] = arr[i];
        }
        size--;
        cout << item << " deleted from array\n";
    }
    else
    {
        // Inserting item
        int *newArr = new int[size + 1];
        int i = 0;
        while (i < size && arr[i] < item) {
            newArr[i] = arr[i];
            i++;
        }
        newArr[i] = item;
        for (; i < size; ++i) {
            newArr[i + 1] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        size++;
        cout << item << " inserted into array " << binary(arr, size, item) << "\n";
    }
}

int main() 
{
    int size;
    cout << "Enter the size";
    cin >> size;

    int *array = new int[size];
    cout << "Enter " << size << "  array in sorted order:\n";
    for (int i = 0; i < size; ++i) 
    {
        cin >> array[i];
    }

    int search_item;
    cout << "Enter the item to search/delete/insert: ";
    cin >> search_item;

    cout << "before";
    for (int i = 0; i < size; ++i) {
        cout << " " << array[i];
    }
    cout << endl;

    deleteorinsert(array, size, search_item);

    cout << "after";
    for (int i = 0; i < size; ++i) 
    {
        cout << " " << array[i];
    }
    cout << endl;
    return 0;
}