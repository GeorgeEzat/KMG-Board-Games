#ifndef Miseretictac_H
#define Miseretictac_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
int num = 0;
template <typename T>
class Misere_Board:public Board<T> {
public:
    Misere_Board(){
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
    }
    bool update_board (int x, int y, T symbol){
            // Only update if move is valid
    if (num > 0){
        return true;
    }
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| symbol == 0)) {
        if (symbol == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(symbol);
        }

        return true;
    }
    return false;
    }
    void display_board (){
            for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n--------------------------";
    }
    cout << endl;
    }

    bool is_win(){
    if (num > 0){
        return true;
    }
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0) ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 0)) {
            num = this->n_moves+3;
        }
    }

    // Check diagonals
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0)) {
        num= this->n_moves+3;
    }

    return false;
    }

    bool is_draw() override {
        return (this->n_moves == 9 && !is_win());
    }
    bool game_is_over() override {
        if (num != 0){
            num = 0;
        }
        return (is_win() || is_draw());
    }
};


template <typename T>
class MiserePlayer : public Player<T> {
public:
    MiserePlayer (string name, T symbol) : Player<T>(name, symbol) {} 
    void getmove(int& x, int& y) {
        if (num > 0){
            return; //will not take input 
        }
        else{
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
        }

    }

};

template <typename T>
class MisereRandom_Player : public RandomPlayer<T>{
public:
    MisereRandom_Player (T symbol): RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}
    void getmove(int &x, int &y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
    }
};











#endif
