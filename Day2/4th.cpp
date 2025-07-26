#include <iostream>
#include <cctype> 

using namespace std;

int main() {
    double temp;
    char unit;

   
    cout << "Enter unit (C for Celsius / F for Fahrenheit): ";
    cin >> unit;

    unit = tolower(unit); 

    if (unit != 'c' && unit != 'f') {
        cout << "|| Enter a valid unit (C or F) ||" << endl;
        return 1;
    }

    cout << "Enter Temperature: ";
    cin >> temp;

    if (unit == 'c') {
        double fahrenheit = (temp * 1.8) + 32;
        cout << "Temperature in Fahrenheit: " << fahrenheit << "°F" << endl;
    } else {
        double celsius = (temp - 32) / 1.8;
        cout << "Temperature in Celsius: " << celsius << "°C" << endl;
    }

    return 0;
}
