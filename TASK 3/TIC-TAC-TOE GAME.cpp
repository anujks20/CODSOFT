#include <iostream>
#include <vector>
#include <string>

using namespace std;

char board[3][3];
char currentPlayer;


void resetBoard() {
    char start = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = start++;
        }
    }
    currentPlayer = 'X';
}


void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n";
}


void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}


bool makeMove(int pos) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if (pos < 1 || pos > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}


bool checkWin() {
    
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer)) {
            return true;
        }
    }

    
    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}


bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    string playAgain;

    do {
        resetBoard();
        bool gameOver = false;

        cout << "===== Welcome to Tic-Tac-Toe =====\n";
        displayBoard();

        while (!gameOver) {
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (!makeMove(move)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            displayBoard();

            if (checkWin()) {
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (isDraw()) {
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (yes/no): ";
        cin >> playAgain;

    } while (playAgain == "yes" || playAgain == "y");

    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}

