# Tic-Tac-Toe in C

A simple command-line **Tic-Tac-Toe** game implemented in C for two players. This project is designed to help users play a quick and interactive game of Tic-Tac-Toe directly in their terminal. It includes features like input validation, winner checking, and a replay option.
This is my first project in C so please forgive me if I have made any mistake!😅

## Features
- Two-player Tic-Tac-Toe game (`X` and `O`).
- Input validation for moves (no overwriting a previously occupied spot, no out-of-bound inputs).
- Replay option after each game.
- Handles incorrect input gracefully (non-numeric or out-of-range values).
- Displays the game board after every move.

## Getting Started

### Prerequisites
You need a C compiler installed on your machine to compile and run the code.

For example, you can use `gcc` (GNU Compiler Collection) to compile this C program. On most Linux systems, you can install `gcc` with:

```bash
sudo apt-get install gcc
```
## Compilation and Running
1. Clone this repository or download the source code.
2. Navigate to the folder containing the source code.
3. Compile the tic_tac_toe.c file using gcc
```bash
gcc -o tic_tac_toe tic_tac_toe.c
```
4. Run the compiled program
   ```bash
   ./tic_tac_toe

## How to Play
1. The game starts with Player 1 (`X`) and Player 2 (`O`).
2. The current state of the board is displayed after each move.
3. Players are prompted to choose a cell number (1-9) to place their mark on the board.
4. The game will announce a winner if any player successfully places three of their marks in a row, column, or diagonal.
5. If the board is full and no winner is declared, the game results in a draw.
6. After each game, players are asked if they want to replay (`y`/`n`).
