#ifndef _5X5X_O_H
#define _5X5X_O_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <cstdlib> // for rand()
using namespace std;
// static int p1_points;
// static int p2_points;
static int x_count;
static int o_count;

template <typename T>
class X_O_Board5 : public Board<T> {
public:
    X_O_Board5() {
        this->rows = this->columns = 5;
        this->board = new T*[this->rows];
        for (int i = 0; i < this->rows; i++) {
            this->board[i] = new T[this->columns];
            for (int j = 0; j < this->columns; j++) {
                this->board[i][j] = 0; // Use space for empty cells
            }
        }
        this->n_moves = 0;
    }

    bool update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }
        return true;
    }
    return false;
    }

    void display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n------------------------------------------";
    }
    cout << endl;
    }

    int count_lines(T symbol) {
        int count = 0;

        // Check horizontal
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns - 2; j++) {
                if (this->board[i][j] == symbol &&
                    this->board[i][j] == this->board[i][j + 1] &&
                    this->board[i][j] == this->board[i][j + 2]) {
                    count++;
                }
            }
        }

        // Check vertical
        for (int i = 0; i < this->rows - 2; i++) {
            for (int j = 0; j < this->columns; j++) {
                if (this->board[i][j] == symbol &&
                    this->board[i][j] == this->board[i + 1][j] &&
                    this->board[i][j] == this->board[i + 2][j]) {
                    count++;
                }
            }
        }

        // Check diagonal (top-left to bottom-right)
        for (int i = 0; i < this->rows - 2; i++) {
            for (int j = 0; j < this->columns - 2; j++) {
                if (this->board[i][j] == symbol &&
                    this->board[i][j] == this->board[i + 1][j + 1] &&
                    this->board[i][j] == this->board[i + 2][j + 2]) {
                    count++;
                }
            }
        }

        // Check diagonal (top-right to bottom-left)
        for (int i = 0; i < this->rows - 2; i++) {
            for (int j = 2; j < this->columns; j++) {
                if (this->board[i][j] == symbol &&
                    this->board[i][j] == this->board[i + 1][j - 1] &&
                    this->board[i][j] == this->board[i + 2][j - 2]) {
                    count++;
                }
            }
        }

        return count;
    }

    bool is_win() {
    if (this -> n_moves == 24){
        x_count = count_lines('X');
        o_count = count_lines('O');
        if (x_count < o_count) {
            return true;
        }
    }
    else if (this -> n_moves == 25 ){
        if (x_count > o_count) {
            return true;
        }
    }
    return false;
    }

    bool is_draw() {
        return (this->n_moves == 25 && !is_win());
    }

    bool game_is_over() {
        return is_win() || is_draw();
    }
};

template <typename T>
class X_O_Player5 : public Player<T> {
public:
    X_O_Player5(string name, T symbol) : Player<T>(name, symbol) {}
    void getmove(int& x, int& y) {
        do {
            cout << "\nEnter your move (x, y): ";
            cin >> x >> y;
            if (cin.fail() || x < 0 || x >= 5 || y < 0 || y >= 5) {
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
    X_O_Random_Player5(T symbol) : RandomPlayer<T>(symbol) {
        this->dimension = 5;
        this->name = "Random Computer Player";
        srand(static_cast<unsigned int>(time(0)));
    }

    void getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
    }
};

#endif
