//Find the maximum element in an array

#include <iostream>
using namespace std;

int main() {
    int n;

    // Input array size
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input array elements
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize max with the first element
    int maxElement = arr[0];

    // Traverse the array to find the maximum
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    // Output the maximum element
    cout << "The maximum element is: " << maxElement << endl;

    return 0;
}
