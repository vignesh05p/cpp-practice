// Problem 5: Sum of First N Natural Numbers
// 📌 Problem Statement:
// Write a program to calculate the sum of the first n natural numbers.

// 🔢 Input:
// An integer n

// ✅ Output Example:

// makefile
// Copy
// Edit
// Input: 5  
// Output: Sum = 15
// 🧮 Formula:
// Sum = 1 + 2 + 3 + ... + n = n * (n + 1) / 2

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int sum = n * (n + 1) / 2;
    cout << "Sum = " << sum << endl;

    return 0;
}
