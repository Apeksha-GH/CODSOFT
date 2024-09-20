#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};  // The Tic-Tac-Toe board
char currentPlayer = 'X';  // X will go first

// Function declarations
void showBoard();
void takeTurn();
bool hasWon();
bool isDraw();
void changePlayer();
void resetBoard();

int main() {
    char playAgain = 'y';  // Play again control

    cout << "Welcome to Tic-Tac-Toe!\n";

    // Game loop
    while (playAgain == 'y' || playAgain == 'Y') {
        resetBoard();  // Reset the board for a new game
        currentPlayer = 'X';  // X always starts

        bool gameOn = true;

        while (gameOn) {
            showBoard();
            takeTurn();

            if (hasWon()) {
                showBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameOn = false;  // End the game
            }
            else if (isDraw()) {
                showBoard();
                cout << "It's a draw!\n";
                gameOn = false;  // End the game
            }
            else {
                changePlayer();  // Switch turns if no win or draw
            }
        }

        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;  // Ask to play again
    }

    cout << "Thanks for playing! Goodbye!\n";
    return 0;
}

// Function to display the current state of the board
void showBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    cout << "\n";
}

// Function to handle the current player's turn
void takeTurn() {
    int choice;
    bool validMove = false;

    while (!validMove) {
        cout << "Player " << currentPlayer << ", choose a spot (1-9): ";
        cin >> choice;

        if (choice >= 1 && choice <= 9) {
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            // Check if the spot is available
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = currentPlayer;
                validMove = true;
            } else {
                cout << "That spot is already taken. Try again.\n";
            }
        } else {
            cout << "Invalid input. Choose a number between 1 and 9.\n";
        }
    }
}

// Function to check if the current player has won
bool hasWon() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

// Function to check if the game is a draw
bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;  // If there's an empty spot, it's not a draw
        }
    }
    return true;  // If no empty spots, it's a draw
}

// Function to switch turns between players
void changePlayer() {
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

// Function to reset the board for a new game
void resetBoard() {
    char startingBoard[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = startingBoard[i][j];  // Reset board to initial state
        }
    }
}
