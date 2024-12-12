
#ifndef _NUM_X_O_H
#define _NUM_X_O_H

#include "BoardGame_Classes.h"

template <typename T>
class NUM_X_O_Board: public Board<T> {
public:
    NUM_X_O_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class NUM_X_O_Player : public Player<T> {
public:
    NUM_X_O_Player (string name, T symbol,bool is_0dd, vector<int> &available_numbers);
    bool hasNumber(int number);

    void removeNumber(int number);

    void getmove(int& x, int& y) override ;
private:
    bool odd;
    vector<int> num;

};

template <typename T>
class NUM_X_O_Random_Player : public RandomPlayer<T>{
public:
    NUM_X_O_Random_Player (T symbol,bool is_0dd, vector<int> &available_numbers);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// Constructor for NUM_X_O_Board
template <typename T>
NUM_X_O_Board<T>::NUM_X_O_Board() {
    this->rows = this->columns = 3;
    this->board = new int*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new int[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool NUM_X_O_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)  && mark != -1) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = mark;
        }

        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void NUM_X_O_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool NUM_X_O_Board<T>::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        if (((this->board[i][0] + this->board[i][1] + this->board[i][2] )== 15 && this->board[i][0] != 0 &&  this->board[i][1] != 0 &&  this->board[i][2] != 0) ||
                ((this->board[0][i] + this->board[1][i] + this->board[2][i] )== 15 && this->board[0][i] != 0 &&  this->board[1][i] != 0 &&  this->board[2][i] != 0)) {
            return true;
        }
    }

    // Check diagonals
    if (((this->board[0][0] + this->board[1][1] + this->board[2][2] )==15 && this->board[2][2] !=0 && this->board[0][0] != 0&& this->board[1][1] != 0) ||
            ((this->board[0][2] + this->board[1][1] + this->board[2][0]) ==15 && this->board[0][2] != 0 && this->board[1][1] != 0 && this->board[2][0] != 0)) {
        return true;
    }

    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool NUM_X_O_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool NUM_X_O_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for NUM_X_O_Player
template <typename T>
NUM_X_O_Player<T>::NUM_X_O_Player(string name, T symbol,bool is_0dd, vector<int> &available_numbers) : Player<T>(name, symbol) {
    odd = is_0dd;
    num = available_numbers;

}

//template <typename T>
//void NUM_X_O_Player<T>::getmove(int& x, int& y) {
//    cout << "\nPlease enter your move x and y (0 to 2) and value separated by spaces: ";
//    cin >> x >> y ; // INPUT MARK HERE
//    // CHEK IF THE MARK IS VALID USING HASNUMBER FUN IF YES REMOVE IT FROM VECTOR USING REMOVENUMBER FUNCTION
//    // if not vaild set the mark -1
//
//}

template <typename T>
void NUM_X_O_Player<T>::getmove(int& x, int& y) {
    int mark; // To hold the value for the move

    cout << "\nPlease enter your move (x y value) and value separated by spaces: ";
    cin >> x >> y >> mark;

    // Check if the mark is valid using hasNumber function
    if (hasNumber(mark)) {
        removeNumber(mark); // Remove it from the vector
        this->symbol = mark;

    } else {

        this->symbol = -1;
    }
}


template <typename T>
void NUM_X_O_Player<T>::removeNumber(int number) {
    num.erase(find(num.begin(), num.end(), number));
}

template <typename T>
bool NUM_X_O_Player<T>::hasNumber(int number) {
    if (std::find(num.begin(), num.end(), number) != num.end()) {
        return true;

    }

    return false;

}

// Constructor for NUM_X_O_Random_Player
template <typename T>
NUM_X_O_Random_Player<T>::NUM_X_O_Random_Player (T symbol,bool is_0dd, vector<int> &available_numbers) : RandomPlayer<T>(symbol) {

    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void NUM_X_O_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
}







#endif //NUM_X_O_H

