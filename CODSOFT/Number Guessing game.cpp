#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    int randomNumber, guess, attempts;
    char playAgain = 'y';

    // random number genration: to initialize random number generator
    srand(time(0));  // Seed for random number generation

    // Main game loop, controlled by playAgain
    while (playAgain == 'y' || playAgain == 'Y') {
        randomNumber = std::rand() % 100 + 1;  // Generate random number between 1 and 100
        attempts = 0;  // Reset attempts for each game

        cout << "Welcome! Try to guess a number between 1 and 100.\n";

        // Inner guessing loop
        while (true) {
            cout << "Enter your guess (or -1 to quit): ";
            cin >> guess;

            if (guess == -1) {
                cout << "You chose to quit. The correct number was: " << randomNumber << "\n";
                break;
            }

            attempts++;  // Increment the attempt count

            //this is to   Provide feedback
            if (guess > randomNumber) {
                cout << "Too high! Try again.\n";
            } else if (guess < randomNumber) {
                cout << "Too low! Try again.\n";
            } else {
                cout << "Congratulations! You guessed the correct number: " << randomNumber << "\n";
                cout << "It took you " << attempts << " attempts.\n";
                break;
            }
        }

        // Ask the player if they want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

   cout << "Thanks for playing! Goodbye.\n";

    return 0;
}
