#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()

using namespace std;

int main() {
    int num, guess;
    int count = 0;

    // seed and generate the secret once
    srand(time(0));
    num = rand() % 100 + 1;  // 1..100

    cout << "********** NUMBER GUESS GAME **********\n";

    do {
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;
        count++;

        if (guess < num) {
            cout << "Too low!\n";
        }
        else if (guess > num) {
            cout << "Too high!\n";
        }
        else {
            cout << "Correct! The answer is " << num
                 << ". You got it in " << count
                 << (count == 1 ? " guess.\n" : " guesses.\n");
        }
    } while (guess != num);

    return 0;
}
