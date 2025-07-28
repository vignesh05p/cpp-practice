#include <iostream>
using namespace std;

int main() {
    int num, count = 0;
    cout << "Enter a number: ";
    cin >> num;

    // Handle 0 explicitly (0 has 1 digit)
    if (num == 0) {
        count = 1;
    } else {
        // Take absolute in case of negative numbers
        num = abs(num);
        while (num > 0) {
            num /= 10; // Remove last digit
            ++count;
        }
    }

    cout << "Number of digits = " << count << endl;

    return 0;
}
