// Problem 2: Reverse Star Pattern
// 📌 Problem Statement:
// Print a pattern of * in reverse order, starting from n stars in the first row to 1 in the last.

// 🔢 Input:
// An integer n (number of rows)

// ✅ Output Example:

// markdown
// Copy
// Edit
// Input: 5

// Output:
// * * * * *
// * * * *
// * * *
// * *
// *

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    // Outer loop for rows
    for (int i = n; i >= 1; --i) {
        // Inner loop for stars
        for (int j = 1; j <= i; ++j) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
