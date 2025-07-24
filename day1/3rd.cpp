// ind the Second Largest Element in an Array (in One Pass)
// ⚠️ Trick:

// Don’t sort the array.

// Don’t use extra space.

// Do it in just one pass.


#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n < 2) {
        cout << "Need at least 2 elements!" << endl;
        return 0;
    }

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MIN)
        cout << "No second largest element (all elements are same)." << endl;
    else
        cout << "Second largest element is: " << second << endl;

    return 0;
}
