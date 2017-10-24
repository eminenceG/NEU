/*
 * assignment-4.c
 *
 * CS 5001 Fall 2017 Silicon Valley
 * Assignment 4: Tic-Tac-Toe (Naughts and Crosses)
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// your documentation block here
/**
* initialize the board
* @param board The board
*/
void initBoard(char board[3][3]) {
	// your code here
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
    }
}

// your documentation block here
/**
* mark the board where the play wants to place the mark;
* @param board the board
* @param turn which player's turn
* @param boardPos the position that the player wants to mark on
*/
void markTheBoard(char board[3][3], char turn, int boardPos) {
	// your code here
    int row = (boardPos - 1) % 3;
    int col = boardPos - row * 3 - 1;
    board[row][col] = turn;
}

// your documentation block here
/**
* display the board
* @param board the board
*/
void displayBoard(char board[3][3]) {
	// your code here
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("-------------\n");
    }
}

// your documentation block here
/**
* check if any player has won the game
* @param board the board
* @param marker marker indicating one plaer
* @return whether the player has wonr
*/
bool hasWon(const char board[3][3], char marker) {
	// your code here
    for (int i = 0; i < 3 ; i++) {
        if (board[i][0] == marker && board[i][1] == marker && board[i][2] == marker)
            return true;
        if (board[0][i] == marker && board[1][i] == marker && board[2][i] == marker)
            return true;
    }
    if (board[0][0] == marker && board[1][1] == marker && board[2][2] == marker)
        return true;
    if (board[0][2] == marker && board[1][1] == marker && board[2][0] == marker)
        return true;
    return false;
}

// your documentation block here
/**
* check is the game is a tie
* @param board the board
* @return whether the game is a tie
*/
bool isTie(const char board[3][3]) {
	// your code here
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    if (hasWon(board, 'X') || hasWon(board, 'O'))
        return false;
    else
        return true;
}

/**
 * Main program for an interactive game of tic-tac-toe.
 */
int main(void) {
	char board[3][3];
	char turn = 'X';

	// initialize the board
	initBoard(board);

    printf("To play a position use the following map to enter a position.\n");
    printf("-------------\n");
    for (int boardPos = 1; boardPos <= 9; boardPos += 3) {
    	printf("| %d | %d | %d |\n", boardPos, boardPos+1, boardPos+2);
            printf("-------------\n");
    }

    // play until there is a draw or a player has won
    while (!isTie(board) && !hasWon(board, 'X') && !hasWon(board, 'O')) {
        int boardPos = -1;
        bool validInput = false;

        // wait for valid input
        while(!validInput) {
            printf("Player %c, enter the position you want to play.\n", turn);
            int success = scanf("%d", &boardPos);
            if (success < 0 || boardPos < 0 || boardPos > 9 ||
                board[(boardPos-1) / 3][(boardPos-1) % 3] != ' ') {
                continue;
            }
            validInput = true;
        }

        // mark the position and display the updated board
        markTheBoard(board, turn, boardPos);

        // display the current board
        displayBoard(board);

        // other player's turn
        switch(turn) {
            case 'X':
                turn = 'O';
                break;
            case 'O':
                turn = 'X';
                break;
        }
    }

    // game over so report results
    if (isTie(board)) {
        printf("The game ends in a tie.\n");
    } else if (hasWon(board, 'X')) {
        printf("Player X has won.");
    } else {
        printf("Player O has won.");
    }

    return EXIT_SUCCESS;
}