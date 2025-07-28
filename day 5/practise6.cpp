// Problem 7: Factorial of a Number (Using Loop)
// 📌 Problem Statement:
// Write a program to calculate the factorial of a number using a for loop.

// 📘 Definition:
// Factorial of n (written as n!) is:
// n! = n × (n-1) × (n-2) × ... × 2 × 1


#include <iostream>
using namespace std;

int main() {
    int n;
    long long factorial = 1;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial of a negative number doesn't exist." << endl;
    } else {
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }
        cout << "Factorial = " << factorial << endl;
    }

    return 0;
}
