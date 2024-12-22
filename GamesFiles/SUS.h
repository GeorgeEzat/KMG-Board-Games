#pragma once
#include "bits\stdc++.h"
#include "BoardGame_Classes.h"
// boolean refers to the end of the game
bool END = false;
//*********************************************************
// *Board Class*
template <typename T>
class SUS_Board : public Board<T>
{
private:
    short sCount;
    short uCount;
    vector<bool> checks;
    //-----------------------------------------------------
    void display()
    {
        if (END)
            return;
        for (short i = 0; i < 3; i++)
        {
            cout << "+-----+-----+-----+\n";
            for (short j = 0; j < 3; j++)
            {
                if (j < 3)
                    cout << "+  ";
                cout << this->board[i][j] << "  ";
            }
            cout << "+\n";
        }
        cout << "+-----+-----+-----+\n";
    }
    //-----------------------------------------------------
    void WinningCount(short &count)
    {
        // all possibilities to win
        if ((this->board[0][0] == 'S') && (this->board[0][2] == 'S') && (this->board[0][1] == 'U') && checks.at(0))
        {
            count++;
            checks.at(0) = false;
        }
        if ((this->board[1][0] == 'S') && (this->board[1][2] == 'S') && (this->board[1][1] == 'U') && checks.at(1))
        {
            count++;
            checks.at(1) = false;
        }
        if ((this->board[2][0] == 'S') && (this->board[2][2] == 'S') && (this->board[2][1] == 'U') && checks.at(2))
        {
            count++;
            checks.at(2) = false;
        }
        if ((this->board[0][0] == 'S') && (this->board[2][0] == 'S') && (this->board[1][0] == 'U') && checks.at(3))
        {
            count++;
            checks.at(3) = false;
        }
        if ((this->board[0][1] == 'S') && (this->board[2][1] == 'S') && (this->board[1][1] == 'U') && checks.at(4))
        {
            count++;
            checks.at(4) = false;
        }
        if ((this->board[0][2] == 'S') && (this->board[2][2] == 'S') && (this->board[1][2] == 'U') && checks.at(5))
        {
            count++;
            checks.at(5) = false;
        }
        if ((this->board[0][0] == 'S') && (this->board[2][2] == 'S') && (this->board[1][1] == 'U') && checks.at(6))
        {
            count++;
            checks.at(6) = false;
        }
        if ((this->board[0][2] == 'S') && (this->board[2][0] == 'S') && (this->board[1][1] == 'U') && checks.at(7))
        {
            count++;
            checks.at(7) = false;
        }
    }
    //-----------------------------------------------------
    bool checkWinning()
    {
        if (END)
            return (uCount > sCount) ? true : false;
        //-------------------------------------------------
        if ((this->n_moves % 2) == 0)
            WinningCount(uCount);
        else
            WinningCount(sCount);
        //-------------------------------------------------
        if (this->n_moves == 9)
        {
            END = true;
            return (sCount > uCount) ? true : false;
        }
        //-------------------------------------------------
        return false;
    }
    //-----------------------------------------------------
public:
    SUS_Board()
    {
        // modify some needed values to start the game
        END = false;
        sCount = 0;
        uCount = 0;
        for (short i = 0; i < 8; i++)
            checks.push_back(true);
        //-------------------------------------------------
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
        if (END)
            return true;
        if (this->board[x][y] >= 49 && this->board[x][y] <= 57)
        {
            this->n_moves++;
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
    bool is_draw() { return (END && !is_win()); }
    //-----------------------------------------------------
    bool game_is_over() { return is_win() || is_draw(); }
    //-----------------------------------------------------
};
//*********************************************************
// *Player CLass*
template <typename T>
class SUS_Player : public Player<T>
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
        cout << "Enter your move (from 1 to 9): ";
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
    void move(int &x, int &y)
    {
        if (END)
            return;
        short *index = new short(0);
        cin_numbers(*index);
        checkValidIndex(*index);
        IndexTranslator(x, y, *index);
        delete index;
    }
    //-----------------------------------------------------

public:
    SUS_Player(string n, T symbol) : Player<T>(n, symbol) {}
    //-----------------------------------------------------
    SUS_Player(T symbol) : Player<T>(symbol) {}
    //-----------------------------------------------------
    void getmove(int &x, int &y) { move(x, y); }
    //-----------------------------------------------------
};
//*********************************************************
// *Random computer player Class*
template <typename T>
class SUS_Random_Player : public RandomPlayer<T>
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
    void randomMove(int &x, int &y)
    {
        if (END)
            return;
        short *index = new short(0);
        *index = (rand() % 9) + 1;
        IndexTranslator(x, y, *index);
        delete index;
    }
    //-----------------------------------------------------
public:
    SUS_Random_Player(string name, T symbol) : RandomPlayer<T>(symbol)
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