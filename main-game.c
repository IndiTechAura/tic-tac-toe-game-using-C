#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//created by IndiTechAura from somewhere in India
//You can copy, modify and share this code under your own name but if you maintain the credits it is appreciated :)

// Function to clear the console
// Uses system("cls") for Windows and system("clear") for UNIX-like systems
void clearConsole() {
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For UNIX-like systems
    #endif
}

// Function to print the Tic-Tac-Toe board
void printBoard(char board[3][3]) {
    clearConsole();
    printf("\n");
    for (int i = 0; i < 3; ++i) {
        printf(" ");
        for (int j = 0; j < 3; ++j) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    return 0;
}

// Function to check if the board is full
int isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to handle player move
void playerMove(char board[3][3], int currentPlayer) {
    int row, col;
    printf("Player %d, enter your move (Row and Column): ", currentPlayer);
    // Check if the input is valid (two integers within the range 0-2)
    if (scanf("%d %d", &row, &col) != 2 || row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        // Clear the input buffer and inform the user about the invalid move
        while (getchar() != '\n');
        printf("Invalid move. Please enter valid numeric values for Row and Column within the range (0-2).\n");
        playerMove(board, currentPlayer); // Retry the move
    } else {
        board[row][col] = (currentPlayer == 1) ? 'X' : 'O';
    }
}

// Function to handle AI move
void aiMove(char board[3][3]) {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    board[row][col] = 'O';
}

// Function to display help menu
void showHelp() {
    printf("\nHow to Play Tic-Tac-Toe:\n");
    printf("1. The game is played on a 3x3 grid.\n");
    printf("2. Each player takes turns to place their mark ('X' or 'O') in an empty cell.\n");
    printf("3. The first player to get three of their marks in a row (horizontally, vertically, or diagonally) wins.\n");
    printf("4. The rows and columns are marked 0, 1 and 2.\n");
    printf("5. If the board is full and no player has three in a row, the game is a tie.\n\n");
}

// Function to display credits
void showCredits() {
    printf("\nCredits:\n");
    printf("Game developed by: IndiTechAura\n"); //if you keep the original credits, it is appreciated but you are free to share this code under your own name :)
    printf("IDEs used: Codeblocks, Visual Studio Code and Github\n\n");
}

int main() {
    srand(time(NULL));
    int currentPlayer = 1;
    int gameMode;
    char menuChoice;

    clearConsole();

    do {
        printf("Welcome to Tic-Tac-Toe!\n");
        printf("1. Player vs Player\n");
        printf("2. Player vs AI\n");
        printf("3. Help\n");
        printf("4. Credits\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &menuChoice);

        switch (menuChoice) {
            case '1':
                gameMode = 1;
                break;
            case '2':
                gameMode = 2;
                break;
            case '3':
                showHelp();
                continue;
            case '4':
                showCredits();
                continue;
            case '5':
                printf("Thanks for playing. Goodbye!\n");
                return 0;
            default:
                printf("Invalid command. Please enter a valid option.\n");
                continue;
        }

        do {
            printBoard();

            if (gameMode == 1 || currentPlayer == 1) {
                playerMove(board, currentPlayer);
            } else {
                aiMove(board);
            }

            if (checkWin(board)) {
                printBoard(board);
                if (gameMode == 1) {
                    printf("Player %d wins!\n", currentPlayer);
                } else {
                    if (currentPlayer == 1) {
                        printf("You win!\n");
                    } else {
                        printf("AI wins!\n");
                    }
                }
                break;
            }

            if (isBoardFull(board)) {
                printBoard(board);
                printf("It's a tie! or it's draw\n");
                break;
            }

            currentPlayer = (currentPlayer == 1) ? 2 : 1;

        } while (1);

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &menuChoice);

    } while (menuChoice == 'y' || menuChoice == 'Y');

    printf("Thanks for playing. Goodbye!\n");

    return 0;
}

