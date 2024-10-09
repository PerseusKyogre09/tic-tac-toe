#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 9

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
        resetBoard(board);
        currentPlayer = 1;
        winner = 0;

        while (winner == 0 && !isFull(board)) {
            displayBoard(board);
            currentPlayer = (currentPlayer % 2) ? 1 : 2;
            mark = (currentPlayer == 1) ? 'X' : 'O';

            choice = getValidInput(board);

            board[choice - 1] = mark;
            winner = checkWinner(board);

            currentPlayer++;
        }

        displayBoard(board);

        if (winner == 1) {
            printf("==> Player %d wins!\n", --currentPlayer);
        } else if (isFull(board)) {
            printf("==> It's a draw!\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &replay);

    } while (replay == 'y' || replay == 'Y');

    printf("Thanks for playing!\n");

    return 0;
}

void displayBoard(char board[]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}
int checkWinner(char board[]) {
    int winCombinations[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        if (board[winCombinations[i][0]] == board[winCombinations[i][1]] &&
            board[winCombinations[i][1]] == board[winCombinations[i][2]]) {
            return 1;
        }
    }
    return 0;
}

bool isFull(char board[]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;
}

void resetBoard(char board[]) {
    for (int i = 0; i < SIZE; i++) {
        board[i] = '0' + (i + 1);
    }
}

int getValidInput(char board[]) {
    int choice;
    char input[10];
    bool valid = false;

    do {
        printf("Enter a number (1-9): ");
        scanf("%s", input);

        if (isdigit(input[0]) && input[1] == '\0') {
            choice = input[0] - '0';

            if (choice >= 1 && choice <= 9 && board[choice - 1] == '0' + choice) {
                valid = true;
            } else {
                printf("Invalid move! The cell is already occupied or out of range. Try again.\n");
            }
        } else {
            printf("Invalid input! Please enter a number between 1 and 9.\n");
        }
    } while (!valid);

    return choice;
}
