// Day 5: Basic Problems (Patterns, Sums, etc.)
// 1. Print the following pattern:

// markdown
// Copy
// Edit
// Input: 4  
// Output:  
// *  
// * *  
// * * *  
// * * * *

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    // Outer loop for each row
    for (int i = 1; i <= n; ++i) {
        // Inner loop for printing stars
        for (int j = 1; j <= i; ++j) {
            cout << "* ";
        }
        cout << endl; // Newline after each row
    }

    return 0;
}
