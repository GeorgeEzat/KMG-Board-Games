#ifndef _5X5X_O_H
#define _5X5X_O_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <cstdlib> // for rand()
using namespace std;

static int counter_x;
static int counter_o;

template <typename T>
class X_O_Board5 : public Board<T> {
public:
    // Constructor to initialize a 5x5 board
    X_O_Board5() {
        this->rows = this->columns = 5;
        this->board = new T*[this->rows];
        for (int row_idx = 0; row_idx < this->rows; row_idx++) {
            this->board[row_idx] = new T[this->columns];
            for (int col_idx = 0; col_idx < this->columns; col_idx++) {
                this->board[row_idx][col_idx] = 0; // Initialize all cells as empty
            }
        }
        this->n_moves = 0;
    }

    // Updates the board with the given move (row, col, and mark)
    bool update_board(int row, int col, T mark) {
        if (!(row < 0 || row >= this->rows || col < 0 || col >= this->columns) && (this->board[row][col] == 0 || mark == 0)) {
            if (mark == 0) { // Undo move
                this->n_moves--;
                this->board[row][col] = 0;
            } else { // Make a move
                this->n_moves++;
                this->board[row][col] = toupper(mark);
            }
            return true;
        }
        return false;
    }

    // Displays the current state of the board
    void display_board() {
        for (int row_idx = 0; row_idx < this->rows; row_idx++) {
            cout << "\n| ";
            for (int col_idx = 0; col_idx < this->columns; col_idx++) {
                cout << "(" << row_idx << "," << col_idx << ")";
                cout << setw(2) << this->board[row_idx][col_idx] << " |";
            }
            cout << "\n------------------------------------------";
        }
        cout << endl;
    }

    // Counts the number of winning lines for a given symbol
    int count_lines(T symbol) {
        int line_count = 0;

        // Check horizontal lines
        for (int row_idx = 0; row_idx < this->rows; row_idx++) {
            for (int col_idx = 0; col_idx < this->columns - 2; col_idx++) {
                if (this->board[row_idx][col_idx] == symbol &&
                    this->board[row_idx][col_idx] == this->board[row_idx][col_idx + 1] &&
                    this->board[row_idx][col_idx] == this->board[row_idx][col_idx + 2]) {
                    line_count++;
                }
            }
        }

        // Check vertical lines
        for (int row_idx = 0; row_idx < this->rows - 2; row_idx++) {
            for (int col_idx = 0; col_idx < this->columns; col_idx++) {
                if (this->board[row_idx][col_idx] == symbol &&
                    this->board[row_idx][col_idx] == this->board[row_idx + 1][col_idx] &&
                    this->board[row_idx][col_idx] == this->board[row_idx + 2][col_idx]) {
                    line_count++;
                }
            }
        }

        // Check diagonal lines (top-left to bottom-right)
        for (int row_idx = 0; row_idx < this->rows - 2; row_idx++) {
            for (int col_idx = 0; col_idx < this->columns - 2; col_idx++) {
                if (this->board[row_idx][col_idx] == symbol &&
                    this->board[row_idx][col_idx] == this->board[row_idx + 1][col_idx + 1] &&
                    this->board[row_idx][col_idx] == this->board[row_idx + 2][col_idx + 2]) {
                    line_count++;
                }
            }
        }

        // Check diagonal lines (top-right to bottom-left)
        for (int row_idx = 0; row_idx < this->rows - 2; row_idx++) {
            for (int col_idx = 2; col_idx < this->columns; col_idx++) {
                if (this->board[row_idx][col_idx] == symbol &&
                    this->board[row_idx][col_idx] == this->board[row_idx + 1][col_idx - 1] &&
                    this->board[row_idx][col_idx] == this->board[row_idx + 2][col_idx - 2]) {
                    line_count++;
                }
            }
        }

        return line_count;
    }

    // Checks if there is a winning condition
    bool is_win() {
        if (this->n_moves == 24) { // Special condition for 24 moves
            counter_x = count_lines('X');
            counter_o = count_lines('O');
            if (counter_x < counter_o) {
                return true;
            }
        } else if (this->n_moves == 25) { // Check win condition on last move
            if (counter_x > counter_o) {
                return true;
            }
        }
        return false;
    }

    // Checks if the game is a draw
    bool is_draw() {
        return (this->n_moves == 25 && !is_win());
    }

    // Checks if the game is over (either win or draw)
    bool game_is_over() {
        return is_win() || is_draw();
    }
};

template <typename T>
class X_O_Player5 : public Player<T> {
public:
    // Constructor to initialize the player with a name and symbol
    X_O_Player5(string player_name, T player_symbol) : Player<T>(player_name, player_symbol) {}

    // Gets the move from the user
    void getmove(int& row, int& col) {
        do {
            cout << "\nEnter your move (row, col): ";
            cin >> row >> col;
            if (cin.fail() || row < 0 || row >= 5 || col < 0 || col >= 5) {
                cout << "Invalid move. Try again.\n";
                cin.clear();
                cin.ignore(1000, '\n'); // Clear invalid input
            } else {
                break;
            }
        } while (true);
    }
};

template <typename T>
class X_O_Random_Player5 : public RandomPlayer<T> {
public:
    // Constructor to initialize a random player with a symbol
    X_O_Random_Player5(T player_symbol) : RandomPlayer<T>(player_symbol) {
        this->dimension = 5;
        this->name = "Random Computer Player";
        srand(static_cast<unsigned int>(time(0)));
    }

    // Generates a random move for the computer player
    void getmove(int& row, int& col) {
        row = rand() % this->dimension;  // Random row between 0 and 4
        col = rand() % this->dimension;  // Random column between 0 and 4
    }
};

#endif
