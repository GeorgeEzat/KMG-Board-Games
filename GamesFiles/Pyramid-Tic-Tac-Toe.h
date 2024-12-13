#pragma once
#include "bits\stdc++.h"
#include "BoardGame_Classes.h"
//*********************************************************
// *Board Class*
template <typename T>
class Pyramid_Board : public Board<T>
{
private:
    //-----------------------------------------------------
    void display()
    {
        cout << setw(19) << "+-----+" << endl;
        cout << setw(15) << "+  " << this->board[0][0] << "  +" << endl;
        cout << setw(25) << "+-----+-----+-----+" << endl;
        cout << setw(9) << "+  " << this->board[0][1] << "  +  " << this->board[0][2];
        cout << "  +  " << this->board[1][0] << "  +" << endl;
        cout << "+-----+-----+-----+-----+-----+" << endl;
        cout << "+  " << this->board[1][1] << "  +  " << this->board[1][2];
        cout << "  +  " << this->board[2][0] << "  +  " << this->board[2][1];
        cout << "  +  " << this->board[2][2] << "  +" << endl;
        cout << "+-----+-----+-----+-----+-----+" << endl;
    }
    //-----------------------------------------------------
public:
    Pyramid_Board()
    {
        // fill the board with numbers from 1 to 9(using ASCII)
        short *temp = new short(49);
        this->rows = this->columns = 3;
        this->board = new char *[this->rows];
        for (int i = 0; i < this->rows; i++)
        {
            this->board[i] = new char[this->columns];
            for (int j = 0; j < this->columns; j++)
            {
                this->board[i][j] = *temp;
                (*temp)++;
            }
        }
        this->n_moves = 0;
        delete temp;
    }
    //-----------------------------------------------------
    bool update_board(int x, int y, T symbol)
    {
        if (this->board[x][y] >= 49 && this->board[x][y] <= 57)
        {
            this->n_moves++;
            this->board[x][y] = toupper(symbol);
            return true;
        }
        return false;
    }
    //-----------------------------------------------------
    void display_board() { display(); }
    //-----------------------------------------------------
    bool is_win()
    {
        // all possibilities to win
        if ((this->board[0][0] == this->board[0][1] && this->board[0][0] == this->board[1][1]) ||
            (this->board[0][0] == this->board[1][0] && this->board[0][0] == this->board[2][2]) ||
            (this->board[0][0] == this->board[0][2] && this->board[0][0] == this->board[2][0]) ||
            (this->board[0][1] == this->board[0][2] && this->board[0][1] == this->board[1][0]) ||
            (this->board[1][1] == this->board[1][2] && this->board[1][1] == this->board[2][0]) ||
            (this->board[1][2] == this->board[2][0] && this->board[1][2] == this->board[2][1]) ||
            (this->board[2][0] == this->board[2][1] && this->board[2][0] == this->board[2][2]))
            return true;
        return false;
    }
    //-----------------------------------------------------
    bool is_draw() { return (this->n_moves == 9 && !is_win()); }
    //-----------------------------------------------------
    bool game_is_over() { return is_win() || is_draw(); }
    //-----------------------------------------------------
};
//*********************************************************
// *Player CLass*
template <typename T>
class Pyramid_Player : public Player<T>
{
private:
    //-----------------------------------------------------
    void IndexTranslator(int &x, int &y, short index)
    {
        if (index == 1)
        {
            x = 0;
            y = 0;
        }
        else if (index == 2)
        {
            x = 0;
            y = 1;
        }
        else if (index == 3)
        {
            x = 0;
            y = 2;
        }
        else if (index == 4)
        {
            x = 1;
            y = 0;
        }
        else if (index == 5)
        {
            x = 1;
            y = 1;
        }
        else if (index == 6)
        {
            x = 1;
            y = 2;
        }
        else if (index == 7)
        {
            x = 2;
            y = 0;
        }
        else if (index == 8)
        {
            x = 2;
            y = 1;
        }
        else if (index == 9)
        {
            x = 2;
            y = 2;
        }
    }
    //-----------------------------------------------------
    bool digitInput(string &temp)
    {
        cout << "\nEnter your move (from 1 to 9): ";
        getline(cin >> ws, temp);
        for (auto &c : temp)
        {
            if (!isdigit(c))
                return false;
        }
        return true;
    }
    //------------------------------------------------
    void cin_numbers(short &n)
    {
        string *temp = new string("");
        while (!digitInput(*temp))
        {
            cout << "\nInvalid Input!\n";
        }
        n = stoi(*temp);
        delete temp;
    }
    //-----------------------------------------------------
    void checkValidIndex(short &index)
    {
        while (true)
        {
            if (!(index > 9 || index < 1))
                return;
            else
            {
                cout << "\nInvalid Input!\n";
                cin_numbers(index);
            }
        }
    }
    //-----------------------------------------------------

public:
    Pyramid_Player(string n, T symbol) : Player<T>(n, symbol) {}
    //-----------------------------------------------------
    Pyramid_Player(T symbol) : Player<T>(symbol) {}
    //-----------------------------------------------------
    void getmove(int &x, int &y)
    {
        short *index = new short(0);
        cin_numbers(*index);
        checkValidIndex(*index);
        IndexTranslator(x, y, *index);
        delete index;
    }
    //-----------------------------------------------------
};
//*********************************************************
// *Random computer player Class*
template <typename T>
class Random_Pyramid_Player : public RandomPlayer<T>
{
private:
    //-----------------------------------------------------
    void IndexTranslator(int &x, int &y, short index)
    {
        if (index == 1)
        {
            x = 0;
            y = 0;
        }
        else if (index == 2)
        {
            x = 0;
            y = 1;
        }
        else if (index == 3)
        {
            x = 0;
            y = 2;
        }
        else if (index == 4)
        {
            x = 1;
            y = 0;
        }
        else if (index == 5)
        {
            x = 1;
            y = 1;
        }
        else if (index == 6)
        {
            x = 1;
            y = 2;
        }
        else if (index == 7)
        {
            x = 2;
            y = 0;
        }
        else if (index == 8)
        {
            x = 2;
            y = 1;
        }
        else if (index == 9)
        {
            x = 2;
            y = 2;
        }
    }
    //-----------------------------------------------------
public:
    Random_Pyramid_Player(string name, T symbol) : RandomPlayer<T>(symbol)
    {
        this->name = name;
        this->name += " (Random Computer)";
        srand(static_cast<unsigned int>(time(0)));
    }
    //-----------------------------------------------------
    void getmove(int &x, int &y)
    {
        short *index = new short(0);
        *index = (rand() % 9) + 1;
        IndexTranslator(x, y, *index);
        delete index;
    }
    //-----------------------------------------------------
};
//*********************************************************