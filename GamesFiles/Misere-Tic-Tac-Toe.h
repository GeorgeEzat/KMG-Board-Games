#ifndef Miseretictac_H
#define Miseretictac_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <cstdlib> // for rand()
using namespace std;

int move_tracker = 0; // Tracks the state of the game

template <typename T>
class Misere_Board : public Board<T> {
public:
    // Constructor initializes a 3x3 board with empty cells
    Misere_Board() {
        this->rows = this->columns = 3;
        this->board = new char*[this->rows];
        for (int row_idx = 0; row_idx < this->rows; row_idx++) {
            this->board[row_idx] = new char[this->columns];
            for (int col_idx = 0; col_idx < this->columns; col_idx++) {
                this->board[row_idx][col_idx] = 0; // Empty cell
            }
        }
        this->n_moves = 0; // Initialize move count to 0
    }

    // Updates the board with a player's move, if valid
    bool update_board(int row, int col, T symbol) {
        if (move_tracker > 0) {
            return true; // Skip update if the game is over
        }
        if (!(row < 0 || row >= this->rows || col < 0 || col >= this->columns) && (this->board[row][col] == 0 || symbol == 0)) {
            if (symbol == 0) {
                this->n_moves--;
                this->board[row][col] = 0; // Reset cell
            } else {
                this->n_moves++;
                this->board[row][col] = toupper(symbol); // Update cell with symbol
            }
            return true;
        }
        return false; // Invalid move
    }

    // Displays the current state of the board
    void display_board() {
        for (int row_idx = 0; row_idx < this->rows; row_idx++) {
            cout << "\n| ";
            for (int col_idx = 0; col_idx < this->columns; col_idx++) {
                cout << "(" << row_idx << "," << col_idx << ")";
                cout << setw(2) << this->board[row_idx][col_idx] << " |";
            }
            cout << "\n--------------------------";
        }
        cout << endl;
    }

    // Checks if the game has been won
    bool is_win() {
        if (move_tracker > 0) {
            return true; // Game already won
        }
        // Check rows and columns for a win
        for (int row_idx = 0; row_idx < this->rows; row_idx++) {
            if ((this->board[row_idx][0] == this->board[row_idx][1] && this->board[row_idx][1] == this->board[row_idx][2] && this->board[row_idx][0] != 0) ||
                (this->board[0][row_idx] == this->board[1][row_idx] && this->board[1][row_idx] == this->board[2][row_idx] && this->board[0][row_idx] != 0)) {
                move_tracker = this->n_moves + 3;
            }
        }

        // Check diagonals for a win
        if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
            (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0)) {
            move_tracker = this->n_moves + 3;
        }

        return false; // No win detected
    }

    // Checks if the game is a draw
    bool is_draw() override {
        return (this->n_moves == 9 && !is_win());
    }

    // Determines if the game is over
    bool game_is_over() override {
        if (move_tracker != 0) {
            move_tracker = 0; // Reset tracker for the next game
        }
        return (is_win() || is_draw());
    }
};

template <typename T>
class MiserePlayer : public Player<T> {
public:
    // Constructor initializes player with name and symbol
    MiserePlayer(string player_name, T player_symbol) : Player<T>(player_name, player_symbol) {}

    // Prompts player to input their move
    void getmove(int& row, int& col) {
        if (move_tracker > 0) {
            return; // Skip input if the game is over
        } else {
            cout << "\nPlease enter your move (row, col) separated by spaces: ";
            cin >> row >> col;
        }
    }
};

template <typename T>
class MisereRandom_Player : public RandomPlayer<T> {
public:
    // Constructor initializes a random computer player
    MisereRandom_Player(T player_symbol) : RandomPlayer<T>(player_symbol) {
        this->dimension = 3;
        this->name = "Random Computer Player";
        srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    }

    // Generates a random move for the player
    void getmove(int& row, int& col) {
        row = rand() % this->dimension; // Random row between 0 and 2
        col = rand() % this->dimension; // Random column between 0 and 2
    }
};

#endif
