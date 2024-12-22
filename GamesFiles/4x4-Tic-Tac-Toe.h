#pragma once
#include "bits\stdc++.h"
#include "BoardGame_Classes.h"
int lastX = -1;
int lastY = -1;
//*********************************************************
// *Board Class*
template <typename T>
class Board_4x4 : public Board<T>
{
private:
    //-----------------------------------------------------
    void display()
    {
        for (short i = 0; i < 4; i++)
        {
            cout << "+--------+--------+--------+--------+\n";
            for (short j = 0; j < 4; j++)
            {
                cout << "+(" << i << "," << j << ") ";
                if (this->board[i][j] != 0)
                    cout << this->board[i][j] << " ";
                else
                    cout << "  ";
            }
            cout << "+\n";
        }
        cout << "+--------+--------+--------+--------+\n";
    }
    //-----------------------------------------------------
    bool checkWinning()
    {
        for (short i = 0; i < 4; i++)
        {
            for (short j = 0; j < 2; j++)
            {
                if ((this->board[i][j] == this->board[i][j + 1]) && (this->board[i][j] == this->board[i][j + 2]) && (this->board[i][j] != 0))
                    return true;
            }
        }
        for (short i = 0; i < 2; i++)
        {
            for (short j = 0; j < 4; j++)
            {
                if ((this->board[i][j] == this->board[i + 1][j]) && (this->board[i][j] == this->board[i + 2][j]) && (this->board[i][j] != 0))
                    return true;
            }
        }
        for (short i = 0; i < 2; i++)
        {
            for (short j = 2; j < 4; j++)
            {
                if ((this->board[i][j] == this->board[i + 1][j - 1]) && (this->board[i][j] == this->board[i + 2][j - 2]) && (this->board[i][j] != 0))
                    return true;
            }
        }
        for (short i = 0; i < 2; i++)
        {
            for (short j = 1; j >= 0; j--)
            {
                if ((this->board[i][j] == this->board[i + 1][j + 1]) && (this->board[i][j] == this->board[i + 2][j + 2]) && (this->board[i][j] != 0))
                    return true;
            }
        }
        return false;
    }
    //-----------------------------------------------------
    bool CheckNew(int &x, int &y, int lastX, int lastY, T symbol)
    {
        if ((this->board[x][y] == 0) &&
            (this->board[lastX][lastY] == symbol) &&
            (abs(x - lastX) + abs(y - lastY) == 1))
            return true;
        return false;
    }
    //----------------------------------------------------
public:
    //-----------------------------------------------------
    Board_4x4()
    {
        lastX = -1;
        lastY = -1;
        this->rows = this->columns = 4;
        this->board = new char *[this->rows];
        for (int i = 0; i < this->rows; i++)
        {
            this->board[i] = new char[this->columns];
            for (int j = 0; j < this->columns; j++)
            {
                this->board[i][j] = 0;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (i % 2 == 0)
            {
                this->board[0][i] = 'O';
                this->board[3][i] = 'X';
            }
            else
            {
                this->board[0][i] = 'X';
                this->board[3][i] = 'O';
            }
        }
        this->n_moves = 0;
    }
    //-----------------------------------------------------
    bool update_board(int x, int y, T symbol)
    {
        if (CheckNew(x, y, lastX, lastY, symbol))
        {
            this->n_moves++;
            this->board[lastX][lastY] = 0;
            this->board[x][y] = symbol;
            return true;
        }
        return false;
    }
    //-----------------------------------------------------
    void display_board() { display(); }
    //-----------------------------------------------------
    bool is_win() { return checkWinning(); }
    //-----------------------------------------------------
    bool is_draw() { return (this->n_moves == 16 && !is_win()); }
    //-----------------------------------------------------
    bool game_is_over() { return is_win() || is_draw(); }
    //-----------------------------------------------------
};
//*********************************************************
// *Player CLass*
template <typename T>
class Player_4x4 : public Player<T>
{
private:
    //-----------------------------------------------------
    bool digitInput(string &temp, string msg)
    {
        cout << endl;
        cout << msg;
        getline(cin >> ws, temp);
        if (temp.size() != 3)
            return false;
        if ((temp.at(0) >= 48 && temp.at(0) <= 51) &&
            (temp.at(2) >= 48 && temp.at(2) <= 51) &&
            (temp.at(1) == ' '))
            return true;
        return false;
    }
    //-----------------------------------------------------
    void cin_numbers(int &x, int &y, string msg)
    {
        string *temp = new string("");
        while (!digitInput(*temp, msg))
        {
            cout << "\nInvalid Input!\n";
        }
        x = temp->at(0) - 48;
        y = temp->at(2) - 48;
        delete temp;
    }
    //-----------------------------------------------------
    void getXY(int &x, int &y)
    {
        string msg1 = "Enter current position x and y (0 to 3) separated by spaces: ";
        cin_numbers(x, y, msg1);
        lastX = x;
        lastY = y;
        string msg2 = "Enter new position x and y (0 to 3) separated by spaces: ";
        cin_numbers(x, y, msg2);
    }
    //-----------------------------------------------------

public:
    Player_4x4(string n, T symbol) : Player<T>(n, symbol) {}
    //-----------------------------------------------------
    Player_4x4(T symbol) : Player<T>(symbol) {}
    //-----------------------------------------------------
    void getmove(int &x, int &y) { getXY(x, y); }
    //-----------------------------------------------------
};
//*********************************************************
// *Random computer player Class*
template <typename T>
class Random_Player_4x4 : public RandomPlayer<T>
{
private:
    //-----------------------------------------------------
    void randomMove(int &x, int &y)
    {
        x = rand() % 4;
        y = rand() % 4;
        lastX = x;
        lastY = y;
        while (abs(x - lastX) + abs(y - lastY) != 1)
        {
            x = rand() % 4;
            y = rand() % 4;
        }
    }
    //-----------------------------------------------------

public:
    Random_Player_4x4(string name, T symbol) : RandomPlayer<T>(symbol)
    {
        this->name = name;
        this->name += " (Random Computer)";
        srand(static_cast<unsigned int>(time(0)));
    }
    //-----------------------------------------------------
    void getmove(int &x, int &y) { randomMove(x, y); }
    //-----------------------------------------------------
};
//*********************************************************