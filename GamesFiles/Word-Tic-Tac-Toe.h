#pragma once
#include "bits\stdc++.h"
#include "BoardGame_Classes.h"
//*********************************************************
// *Board Class*
template <typename T>
class Word_Board : public Board<T>
{
private:
    vector<string> dictionary;
    //-----------------------------------------------------
    void uploadDictionary()
    {
        string *line = new string("");
        ifstream words("dic.txt");
        while (getline(words, *line))
        {
            dictionary.push_back(*line);
        }
        words.close();
        delete line;
    }
    //-----------------------------------------------------
    bool wordChecker(char a, char b, char c)
    {
        if (a < 65 || b < 65 || c < 65)
            return false;
        string *temp = new string("");
        *temp += a;
        *temp += b;
        *temp += c;
        if (a == 'A')
        {
            for (short i = 0; i <= 70; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'B')
        {
            for (short i = 71; i <= 122; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'C')
        {
            for (short i = 123; i <= 159; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'D')
        {
            for (short i = 160; i <= 206; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'E')
        {
            for (short i = 207; i <= 245; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'F')
        {
            for (short i = 246; i <= 293; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'G')
        {
            for (short i = 294; i <= 337; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'H')
        {
            for (short i = 338; i <= 386; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'I')
        {
            for (short i = 387; i <= 405; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'J')
        {
            for (short i = 406; i <= 428; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'K')
        {
            for (short i = 429; i <= 455; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'L')
        {
            for (short i = 456; i <= 499; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'M')
        {
            for (short i = 500; i <= 546; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'N')
        {
            for (short i = 547; i <= 580; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'O')
        {
            for (short i = 581; i <= 625; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'P')
        {
            for (short i = 626; i <= 687; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'Q')
        {
            for (short i = 688; i <= 689; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'R')
        {
            for (short i = 690; i <= 738; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'S')
        {
            for (short i = 739; i <= 800; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'T')
        {
            for (short i = 801; i <= 857; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'U')
        {
            for (short i = 858; i <= 872; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'V')
        {
            for (short i = 873; i <= 893; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'W')
        {
            for (short i = 894; i <= 931; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'X')
        {
            if (*temp == dictionary.at(932))
            {
                delete temp;
                return true;
            }
        }
        else if (a == 'Y')
        {
            for (short i = 933; i <= 959; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        else if (a == 'Z')
        {
            for (short i = 960; i <= 971; i++)
            {
                if (*temp == dictionary.at(i))
                {
                    delete temp;
                    return true;
                }
            }
        }
        return false;
    }
    //-----------------------------------------------------
    void display()
    {
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
public:
    Word_Board()
    {
        uploadDictionary();
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
            this->board[x][y] = symbol;
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
        if (wordChecker(this->board[0][0], this->board[0][1], this->board[0][2]) ||
            wordChecker(this->board[0][2], this->board[0][1], this->board[0][0]) ||
            wordChecker(this->board[1][0], this->board[1][1], this->board[1][2]) ||
            wordChecker(this->board[1][2], this->board[1][1], this->board[1][0]) ||
            wordChecker(this->board[2][0], this->board[2][1], this->board[2][2]) ||
            wordChecker(this->board[2][2], this->board[2][1], this->board[2][0]) ||
            wordChecker(this->board[0][0], this->board[1][0], this->board[2][0]) ||
            wordChecker(this->board[2][0], this->board[1][0], this->board[0][0]) ||
            wordChecker(this->board[0][1], this->board[1][1], this->board[2][1]) ||
            wordChecker(this->board[2][1], this->board[1][1], this->board[0][1]) ||
            wordChecker(this->board[0][2], this->board[1][2], this->board[2][2]) ||
            wordChecker(this->board[2][2], this->board[1][2], this->board[0][2]) ||
            wordChecker(this->board[0][0], this->board[1][1], this->board[2][2]) ||
            wordChecker(this->board[2][2], this->board[1][1], this->board[0][0]) ||
            wordChecker(this->board[0][2], this->board[1][1], this->board[2][0]) ||
            wordChecker(this->board[2][0], this->board[1][1], this->board[0][2]))
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
class Word_Player : public Player<T>
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
    bool charInput(string &temp)
    {
        cout << "\nEnter an alphabetical character: ";
        getline(cin >> ws, temp);
        if (temp.size() - 1)
            return false;
        if (!isalpha(temp.at(0)))
            return false;
        return true;
    }
    //-----------------------------------------------------
    void cin_character(char &c)
    {
        string *temp = new string("");
        while (!charInput(*temp))
        {
            cout << "\nInvalid Input!\n";
        }
        c = toupper(temp->at(0));
        delete temp;
    }
    //------------------------------------------------
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

public:
    Word_Player(string n, T symbol) : Player<T>(n, symbol) {}
    //-----------------------------------------------------
    Word_Player(T symbol) : Player<T>(symbol) {}
    //-----------------------------------------------------
    void getmove(int &x, int &y)
    {
        short *index = new short(0);
        cin_numbers(*index);
        checkValidIndex(*index);
        IndexTranslator(x, y, *index);
        delete index;
        //-------------------------------------------------
        char *character = new char;
        cin_character(*character);
        this->symbol = *character;
        delete character;
        //-------------------------------------------------
    }
    //-----------------------------------------------------
};
//*********************************************************
// *Random computer player Class*
template <typename T>
class Random_Word_Player : public RandomPlayer<T>
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
    Random_Word_Player(string name, T symbol) : RandomPlayer<T>(symbol)
    {
        this->name = name;
        this->name += " (Random Computer)";
        srand(static_cast<unsigned int>(time(0)));
    }
    //-----------------------------------------------------
    void getmove(int &x, int &y)
    {
        short index = (rand() % 9) + 1;
        IndexTranslator(x, y, index);
        short character = (rand() % 26) + 65;
        this->symbol = character;
    }
    //-----------------------------------------------------
};
//*********************************************************