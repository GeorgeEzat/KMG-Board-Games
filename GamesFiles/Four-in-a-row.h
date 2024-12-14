#ifndef FOUR_IN_A_ROW_H
#define FOUR_IN_A_ROW_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>

template <typename T>
class Four_Board: public Board<T> {
public:
    Four_Board ();
    bool update_board (int x, int y, T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class Four_Player : public Player<T> {
public:
    Four_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class Four_Random_Player : public RandomPlayer<T> {
public:
    Four_Random_Player (T symbol);
    void getmove(int&x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION




using namespace std;

// Constructor for Four_Board
template <typename T>
Four_Board<T>::Four_Board() {
    this->rows = 6;
    this->columns = 7;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool Four_Board<T>::update_board(int x,int y, T mark) {
    // Valid column number
    if (y < 0 || y >= this->columns) return false;

    // Check if the column is full
    if (this->board[0][y] != 0) return false;

    // Find the lowest empty row in the column
    for (int i = this->rows - 1; i >= 0; i--) {
        if (this->board[i][y] == 0) {
            this->n_moves++;
            this->board[i][y] = toupper(mark);
            return true;
        }
    }
    return false;

}

// Display the board and the pieces on it
template <typename T>
void Four_Board<T>::display_board() {
    cout<< this->rows;
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n---------------------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool Four_Board<T>::is_win() {
    // Check rows
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns - 3; j++) {
            if ((this->board[i][j] == this->board[i][j + 1] &&
                 this->board[i][j] == this->board[i][j + 2] &&
                 this->board[i][j] == this->board[i][j + 3] &&
                 this->board[i][j] != 0)) {
                return true;
            }
        }
    }

    // Check columns
    for (int j = 0; j < this->columns; j++) {
        for (int i = 0; i < this->rows - 3; i++) {
            if (this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j] &&
                this->board[i][j] == this->board[i + 3][j] &&
                this->board[i][j] != 0) {
                return true;
            }
        }
    }

    // Check diagonals from top left to bottom right
    for ( int i = 0 ; i < this->rows-3; i++) {
        for (int j = 0 ; j < this -> columns-3; j ++) {
            if (this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2] &&
                this->board[i][j] == this->board[i + 3][j + 3] &&
                this->board[i][j] != 0)
                return true;
        }
    }
    for ( int i = this->rows-1 ; i >= 3; i--) {
        for (int j = 0 ; j < this -> columns-3; j++) {
            if (this->board[i][j] == this->board[i - 1][j + 1] &&
                this->board[i][j] == this->board[i - 2][j + 2] &&
                this->board[i][j] == this->board[i - 3][j + 3] &&
                this->board[i][j] != 0)
                return true;
        }
    }

    return false;
}

// Return true if 42 moves are done and no winner
template <typename T>
bool Four_Board<T>::is_draw() {
    return (this->n_moves == 42 && !is_win());
}

template <typename T>
bool Four_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for Four_Player
template <typename T>
Four_Player<T>::Four_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Four_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move y (0 to 6) (column only): ";
    cin  >> y;
}

// Constructor for Four_Random_Player
template <typename T>
Four_Random_Player<T>::Four_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 7;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void Four_Random_Player<T>::getmove(int&x, int& y) {
    y = rand() % this->dimension;
}







#endif //FOUR_IN_A_ROW_H