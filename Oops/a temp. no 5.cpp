#include <iostream>
using namespace std;

int n; // Global variable to store the size of the array

// Template function for selection sort
template <typename T>
void sel(T A[10]) {
    int i, j, minIndex;
    T temp;

    // Selection sort algorithm
    for (i = 0; i < n - 1; i++) { ///constructor
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex])
                minIndex = j;
        }
        // Swap elements
        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }

    // Display sorted array
    cout << "\nSorted Array: ";
    for (i = 0; i < n; i++) {
        cout << A[i] << ", ";
    }
    cout << endl;
}

int main() {
    int A[10];    // Array for integer elements
    float B[10];  // Array for float elements
    int i;

    // Input and sort integer array
    cout << "Enter total number of elements in the integer array: ";
    cin >> n;
    cout << "Enter the integer elements in the array:\n";
    for (i = 0; i < n; i++) {
        cin >> A[i];
    }
    sel<int>(A);

    // Input and sort float array
    cout << "\nEnter total number of elements in the float array: ";
    cin >> n;
    cout << "Enter the float elements in the array:\n";
    for (i = 0; i < n; i++) {
        cin >> B[i];
    }
    sel<float>(B);

    return 0;
}