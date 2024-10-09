#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 9

// Function declarations
void displayBoard(char board[]);
int checkWinner(char board[]);
bool isFull(char board[]);
void resetBoard(char board[]);
int getValidInput(char board[]);

int main() {
    char board[SIZE];
    int currentPlayer, choice, winner;
    char mark;
    char replay;

    do {
        resetBoard(board); // Initialize/reset the board
        currentPlayer = 1; // Player 1 starts
        winner = 0; // Reset winner flag

        // Main game loop
        while (winner == 0 && !isFull(board)) {
            displayBoard(board);
            currentPlayer = (currentPlayer % 2) ? 1 : 2; // Switch players
            mark = (currentPlayer == 1) ? 'X' : 'O';

            // Get valid input from the player
            choice = getValidInput(board);

            // Place the mark on the board
            board[choice - 1] = mark;
            winner = checkWinner(board); // Check for a winner

            currentPlayer++; // Switch to the next player
        }

        displayBoard(board); // Display the final board

        // Check the game result
        if (winner == 1) {
            printf("==> Player %d wins!\n", --currentPlayer);
        } else if (isFull(board)) {
            printf("==> It's a draw!\n");
        }

        // Ask if players want to replay the game
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &replay);

    } while (replay == 'y' || replay == 'Y');

    printf("Thanks for playing!\n");

    return 0;
}

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}

// Function to check if a player has won
int checkWinner(char board[]) {
    // Winning combinations: rows, columns, diagonals
    int winCombinations[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}  // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        if (board[winCombinations[i][0]] == board[winCombinations[i][1]] &&
            board[winCombinations[i][1]] == board[winCombinations[i][2]]) {
            return 1; // A player has won
        }
    }
    return 0; // No winner yet
}

// Function to check if the board is full (no more moves possible)
bool isFull(char board[]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false; // There's still an empty spot
        }
    }
    return true; // Board is full
}

// Function to reset the board to its initial state
void resetBoard(char board[]) {
    for (int i = 0; i < SIZE; i++) {
        board[i] = '0' + (i + 1); // Reset each cell to its initial number
    }
}

// Function to get valid input from the player
int getValidInput(char board[]) {
    int choice;
    char input[10]; // Buffer for handling input
    bool valid = false;

    do {
        printf("Enter a number (1-9): ");
        scanf("%s", input);

        // Check if the input is a valid single digit (1-9)
        if (isdigit(input[0]) && input[1] == '\0') {
            choice = input[0] - '0'; // Convert character to integer

            // Check if the choice is within range and the cell is empty
            if (choice >= 1 && choice <= 9 && board[choice - 1] == '0' + choice) {
                valid = true;
            } else {
                printf("Invalid move! The cell is already occupied or out of range. Try again.\n");
            }
        } else {
            printf("Invalid input! Please enter a number between 1 and 9.\n");
        }
    } while (!valid); // Keep asking until valid input is received

    return choice;
}
