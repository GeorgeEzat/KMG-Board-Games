//
// Created by Kerol/Marco on 12/12/2024.
//

#ifndef GAME8_ULTIMATE_X_O_H
#define GAME8_ULTIMATE_X_O_H

#include "BoardGame_Classes.h"
#include <vector>
template <typename T>
class X_O_Board:public Board<T> {
public:
    vector<vector<T>>final_board;
    char current_symbol;

    X_O_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_small_win(int x,int y);
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class X_O_Player : public Player<T> {
public:
    X_O_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class X_O_Random_Player : public RandomPlayer<T>{
public:
    X_O_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()

using namespace std;

// Constructor for X_O_Board
template <typename T>
X_O_Board<T>::X_O_Board() {
    this->rows = this->columns = 9;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;

        }
    }
    final_board = vector<vector<T>>(3, vector<T>(3, 0));

    this->n_moves = 0;

}

template <typename T>
bool X_O_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0) && final_board[x/3][y/3] == 0) {
        if (mark == 0 ){
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

// Display the board and the pieces on it
template <typename T>
void X_O_Board<T>::display_board() {
    const string separator = "##";
    const string border = "##############################################################################";
    const string line = "--------------------------------------------------------------------------";

    cout << border << endl;

    for (int i = 0; i < this->rows; i++) {
        cout << separator;
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
            if ((j + 1) % 3 == 0 && j != this->columns - 1) {
                cout << separator;
            }
        }
        cout << separator << endl;
        if ((i + 1) % 3 == 0 && i != this->rows - 1) {
            cout << line << endl;
        }
    }

    cout << border << endl;

    for (int i = 0; i < 3; i++) {
        cout << separator;
        for (int j = 0; j < 3; j++) {
            cout << setw(2) << this->final_board[i][j] << " |";
        }
        cout << separator << endl;
        if (i != 2) {
            cout << "----------------" << endl;
        }
    }

    cout << border << endl;
}
template <typename T>
bool X_O_Board<T>::is_small_win(int x,int y) {
for(int i =0; i < 3;i++) {
    if ((this->board[x+i][y] == this->board[x+i][y + 1] && this->board[x+i][y] == this->board[x+i][y + 2] &&
         this->board[x+i][y] != 0)) {
        current_symbol = this->board[x+i][y];
        cout << "test";
        return true;
    }
    if (this->board[x][y+i] == this->board[x + 1][y+i] && this->board[x][y+i] == this->board[x + 2][y+i] &&
        this->board[x][y+i] != 0){
        current_symbol = this->board[x][y+i];
        return true;
    }
}
    // Check diagonals
    if ((this->board[x][y] == this->board[x+1][y+1] && this->board[x+1][y+1] == this->board[x+2][y+2] && this->board[x][y] != 0) ||
        (this->board[x+0][y+2] == this->board[x+1][y+1] && this->board[x+1][y+1] == this->board[x+2][y+0] && this->board[x+0][y+2] != 0)) {
        current_symbol = this->board[y][x];
        cout<<"*";
        return true;
    }

    return false;


}
// Returns true if there is any winner
template <typename T>
bool X_O_Board<T>::is_win() {
    // Check all small 3x3 boards
   for (int i = 0; i <9; i+=3 ){
        for (int j=0; j<9; j +=3){
            if (is_small_win(i,j)){
                final_board[i/3][j/3]=current_symbol;
            }
        }
    }

    // Check rows and columns in the final board
    for (int i = 0; i < 3; ++i) {
        if (final_board[i][0] == final_board[i][1] && final_board[i][1] == final_board[i][2] && final_board[i][0] != 0) {
            return true;
        }
        if (final_board[0][i] == final_board[1][i] && final_board[1][i] == final_board[2][i] && final_board[0][i] != 0) {
            return true;
        }
    }

    // Check diagonals
    if (final_board[0][0] == final_board[1][1] && final_board[1][1] == final_board[2][2] && final_board[0][0] != 0) {
        return true;
    }
    if (final_board[0][2] == final_board[1][1] && final_board[1][1] == final_board[2][0] && final_board[0][2] != 0) {
        return true;
    }

    return false;
}


// Return true if 9 moves are done and no winner
template <typename T>
bool X_O_Board<T>::is_draw() {
    return (this->n_moves == 81 && !is_win());
}

template <typename T>
bool X_O_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for X_O_Player
template <typename T>
X_O_Player<T>::X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void X_O_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for X_O_Random_Player
template <typename T>
X_O_Random_Player<T>::X_O_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void X_O_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
}








#endif //GAME8_ULTIMATE_X_O_H