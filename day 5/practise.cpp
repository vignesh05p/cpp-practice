//  Problem 6: Check if a Number is Prime
// 📌 Problem Statement:
// Write a program to check whether a given number is prime or not.

// 📘 Definition:
// A number is prime if it is greater than 1 and has only two factors: 1 and itself.

#include <iostream>
using namespace std;

int main() {
    int n, i;
    bool isPrime = true;

    cout << "Enter a number: ";
    cin >> n;

    if (n <= 1) {
        isPrime = false;
    } else {
        for (i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime)
        cout << n << " is a Prime number." << endl;
    else
        cout << n << " is NOT a Prime number." << endl;

    return 0;
}
