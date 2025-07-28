// Problem 3: Number Triangle Pattern
// 📌 Problem Statement:
// Print a triangle where each row contains numbers from 1 up to the row number.

// 🔢 Input:
// An integer n (number of rows)

// ✅ Output Example:

// makefile
// Copy
// Edit
// Input: 4

// Output:
// 1
// 1 2
// 1 2 3
// 1 2 3 4


#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    // Outer loop for rows
    for (int i = 1; i <= n; ++i) {
        // Inner loop for printing numbers from 1 to i
        for (int j = 1; j <= i; ++j) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
