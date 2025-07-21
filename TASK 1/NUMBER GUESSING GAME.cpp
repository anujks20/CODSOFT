#include <iostream>
#include <cstdlib>
#include <ctime>     

using namespace std;

int main() {
    srand(time(0));

    int numberToGuess = rand() % 100 + 1; 
    int userGuess = 0;
    int tries = 0;

    cout << "===== Number Guessing Game =====" << endl;
    cout << "I've picked a number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    while (true) {
        cout << "\nEnter your guess: ";
        cin >> userGuess;
        tries++;

        if (userGuess < numberToGuess) {
            cout << "Oops! Too low. Try again.";
        } else if (userGuess > numberToGuess) {
            cout << "Too high! Give it another shot.";
        } else {
            cout << "\nWell done! You guessed it in " << tries << " tries." << endl;
            break;
        }
    }

    cout << "\nThanks for playing!" << endl;
    return 0;
}

