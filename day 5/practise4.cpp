//  Problem 4: Right-Aligned Star Triangle
// 📌 Problem Statement:
// Print a right-aligned triangle using *, where each row starts with spaces followed by stars.

// 🔢 Input:
// An integer n (number of rows)

// ✅ Output Example:

// markdown
// Copy
// Edit
// Input: 4

// Output:
//    *  
//   * *  
//  * * *  
// * * * *

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        // Print spaces
        for (int space = 1; space <= n - i; ++space) {
            cout << " ";
        }
        // Print stars
        for (int star = 1; star <= i; ++star) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
