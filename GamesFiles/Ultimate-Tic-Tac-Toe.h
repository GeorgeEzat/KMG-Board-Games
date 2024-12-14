#ifndef ULTIMATE_X_O_H
#define ULTIMATE_X_O_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <vector>
template <typename T>
class Ultimate_X_O_Board: public Board<T> {
public:
    Ultimate_X_O_Board ();
    bool update_board (int x, int y, T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_small_win(int x,int y);
    bool is_draw();
    bool game_is_over();
    vector<vector<T>>Final_board; // 3 * 3 board
    char current_symbol;

};

template <typename T>
class Ultimate_X_O_Player : public Player<T> {
public:
    Ultimate_X_O_Player (string name, T symbol);
    void getmove(int& x, int& y) ;
};

template <typename T>
class Ultimate_X_O_Random_Player : public RandomPlayer<T> {
public:
    Ultimate_X_O_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION



using namespace std;

// Constructor for Ultimate_X_O_Board
template <typename T>
Ultimate_X_O_Board<T>::Ultimate_X_O_Board() {
    this->rows = this->columns = 9;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    Final_board = vector<vector<T>>(3, vector<T>(3, 0));
    this->n_moves = 0;

}

template <typename T>
bool Ultimate_X_O_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0) && Final_board[x / 3][y / 3] == 0) {
        if (mark == 0 ) {
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
void Ultimate_X_O_Board<T>::display_board() {
    const string separator = "##";
    const string border = "##############################################################################";
    const string line = "--------------------------------------------------------------------------";

    cout << border << endl;
    // Display main board (9 * 9 board)
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
    // Display final board (3 * 3 board)
    for (int i = 0; i < 3; i++) {
        cout << separator;
        for (int j = 0; j < 3; j++) {
            cout << setw(2) << this->Final_board[i][j] << " |";
        }
        cout << separator << endl;
        if (i != 2) {
            cout << "----------------" << endl;
        }
    }

    cout << border << endl;
}
template <typename T>
bool Ultimate_X_O_Board<T>::is_small_win(int x, int y) {
    // Check the win in small boards of the main board
    for(int i =0; i < 3; i++) {
        if ((this->board[x+i][y] == this->board[x+i][y + 1] && this->board[x+i][y] == this->board[x+i][y + 2] &&
             this->board[x+i][y] != 0)) {
            current_symbol = this->board[x+i][y];
            cout << "test";
            return true;
        }
        if (this->board[x][y+i] == this->board[x + 1][y+i] && this->board[x][y+i] == this->board[x + 2][y+i] &&
            this->board[x][y+i] != 0) {
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

template <typename T>
bool Ultimate_X_O_Board<T>::is_win() {
    for (int i = 0; i <9; i+=3 ) {
        for (int j=0; j<9; j +=3) {
            if (is_small_win(i,j)) {
                Final_board[i / 3][j / 3]=current_symbol;
            }
        }
    }

    // Check rows and columns in the final board
    for (int i = 0; i < 3; ++i) {
        if (Final_board[i][0] == Final_board[i][1] && Final_board[i][1] == Final_board[i][2] && Final_board[i][0] != 0) {
            return true;
        }
        if (Final_board[0][i] == Final_board[1][i] && Final_board[1][i] == Final_board[2][i] && Final_board[0][i] != 0) {
            return true;
        }
    }

    // Check diagonals
    if (Final_board[0][0] == Final_board[1][1] && Final_board[1][1] == Final_board[2][2] && Final_board[0][0] != 0) {
        return true;
    }
    if (Final_board[0][2] == Final_board[1][1] && Final_board[1][1] == Final_board[2][0] && Final_board[0][2] != 0) {
        return true;
    }

    return false;
}


// Return true if 9 moves are done and no winner
template <typename T>
bool Ultimate_X_O_Board<T>::is_draw() {
    return (this->n_moves == 81 && !is_win());
}

template <typename T>
bool Ultimate_X_O_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for Ultimate_X_O_Player
template <typename T>
Ultimate_X_O_Player<T>::Ultimate_X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Ultimate_X_O_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 8) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for Ultimate_X_O_Random_Player
template <typename T>
Ultimate_X_O_Random_Player<T>::Ultimate_X_O_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 9;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void Ultimate_X_O_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 8
    y = rand() % this->dimension;
}








#endif //ULTIMATE_X_O_H