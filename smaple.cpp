// FOR O(N) TIME COMPLEXCITY
#include <iostream>
using namespace std;

int main() 
{
    int size;

    cout << "Enter the size ";
    cin >> size;

    int* iA = new int[size];
    double* aA = new double[size];
    cout<< " elements       "<< endl;
    for (int i = 0; i < size; i++) 
    {
        cin >> iA[i];
    }

    double sum = 0.0; 
    for (int i = 0; i < size; i++) 
    {
        sum += iA[i];
        aA[i] = sum / (i + 1);
    }

    cout << "Averages" << endl;
    for (int i = 0; i < size; i++)
     {
        cout << aA[i] << endl;
    }
    return 0;
}

//by 0(n^2) time complexity



// #include <iostream>
// using namespace std;

// int main() {
//     int size;

//     cout << "Enter the size  ";
//     cin >> size;

//     int* iA = new int[size];
//     double* aA = new double[size];

//    cout<< " elements       " << endl;

//     for (int i = 0; i < size; i++) {
//         cin >> iA[i];
//     }

//     for (int i = 0; i < size; i++){
//         double sum = 0.0;
//         for (int j = 0; j <= i; j++) {
//             sum += iA[j];
//         }
//         aA[i] = sum / (i + 1);
//     }

//     cout << "Averages " << endl;

//     for (int i = 0; i < size; i++) {
//         cout << aA[i] << endl;
//     }


//     return 0;
// }
