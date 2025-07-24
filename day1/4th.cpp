// Question 4: Check if the Array is Sorted in Ascending Order
// 🧠 What makes it tricky?

// You have to stop early if unsorted.

// You must handle arrays with duplicates (like [1, 2, 2, 3]).

// // Edge case: arrays with 0 or 1 element are considered sorted.



#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    if (n <= 1) return true;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (isSorted(arr, n)) {
        cout << "Array is sorted in ascending order.\n";
    } else {
        cout << "Array is NOT sorted.\n";
    }

    return 0;
}
