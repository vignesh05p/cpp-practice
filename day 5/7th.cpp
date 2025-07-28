#include <iostream>
#include <cmath> // For abs()
using namespace std;

int main() {
    int num, count = 0;

    cout << "Enter an integer: ";
    cin >> num;

    // Input validation: check if the user entered an integer
    if (cin.fail()) {
        cout << "Invalid input. Please enter a valid integer." << endl;
        return 1;
    }

    // Handle 0 explicitly
    if (num == 0) {
        count = 1;
    } else {
        int temp = abs(num); // Handle negative numbers

        while (temp > 0) {
            temp /= 10;
            ++count;
        }
    }

    cout << "Number of digits in " << num << " is: " << count << endl;

    return 0;
}
