#pragma once
//----------------------------------------------------
// *Classes Headers*
//----------------------------------------------------
// Kerolos's files
#include "Four-in-a-row.h"
#include "Numerical-Tic-Tac-Toe.h"
//------------------------------
// Marco's files
#include "5x5-Tic-Tac-Toe.h"
#include "Misere-Tic-Tac-Toe.h"
//------------------------------
// George's files
#include "Pyramid-Tic-Tac-Toe.h"
#include "Word-Tic-Tac-Toe.h"
#include "SUS.h"
//------------------------------
// Kerolos And Marco
#include "Ultimate-Tic-Tac-Toe.h"
//----------------------------------------------------
class Program
{
private:
    void Header()
    {
        system("cls");
        cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
        cout << "+        KMG Board Games        +\n";
        cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    }
    //------------------------------------------------
    void exit()
    {
        system("cls");
        cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
        cout << "See You Soon Enjoying KMG Games ;)\n";
        cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
    }
    //------------------------------------------------
    void MainMenu()
    {
        Header();
        cout << "*********************************" << endl;
        cout << "Choose a game you want to play:" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Pyramid Tic Tac Toe" << endl;
        cout << "2. Four in a row" << endl;
        cout << "3. 5x5 Tic Tac Toe" << endl;
        cout << "4. Word Tic Tac Toe" << endl;
        cout << "5. Numerical Tic Tac Toe" << endl;
        cout << "6. Misere Tic Tac Toe" << endl;
        cout << "7. Ultimate Tic Tac Toe" << endl;
        cout << "8. SUS" << endl;
        cout << "0. exit" << endl;
        cout << "*********************************" << endl;
    }
    //------------------------------------------------
    bool digitInput(string &temp)
    {
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
            cout << "\nPlease enter a valid number: ";
        }
        n = stoi(*temp);
        delete temp;
    }
    //------------------------------------------------
    void playerName(string &name, short n)
    {
        name = "";
        cout << "Enter Player " << n << " name: ";
        getline(cin >> ws, name);
    }
    //------------------------------------------------
    void playerType(short &type, short n, bool AI)
    {
        type = 0;
        cout << "Choose Player " << n << " type:" << endl;
        cout << "1. Human" << endl;
        cout << "2. Random Computer" << endl;
        if (AI)
            cout << "3. AI (Unbeatable)" << endl;
        cin_numbers(type);
        if (AI)
        {
            while (!(type >= 1 && type <= 3))
            {
                cout << "Enter valid choice(1 or 3): ";
                cin_numbers(type);
            }
        }
        else
        {
            while (!(type == 1 || type == 2))
            {
                cout << "Enter valid choice(1 or 2): ";
                cin_numbers(type);
            }
        }
        Header();
    }
    //------------------------------------------------
    void GameData(string &name1, string &name2, short &type1, short &type2, bool AI = false)
    {
        playerName(name1, 1);
        playerType(type1, 1, AI);
        playerName(name2, 2);
        playerType(type2, 2, AI);
    }
    //------------------------------------------------
    void GameRunning()
    {
        string name1, name2;
        short type1, type2, choice;
        MainMenu();
        cin_numbers(choice);
        while (true)
        {
            if (choice == 1)
            {
                Header();
                GameData(name1, name2, type1, type2, true);
                Player<char> *players[2];
                Pyramid_Board<char> *B = new Pyramid_Board<char>();
                //-----------------------------------------------------------
                if (type1 == 1)
                    players[0] = new Pyramid_Player<char>(name1, 'X');
                else if (type1 == 2)
                    players[0] = new Pyramid_Random_Player<char>(name1, 'X');
                else if (type1 == 3)
                {
                    players[0] = new Pyramid_AI_Player<char>(name1, 'X');
                    players[0]->setBoard(B);
                }
                //-----------------------------------------------------------
                if (type2 == 1)
                    players[1] = new Pyramid_Player<char>(name2, 'O');
                else if (type2 == 2)
                    players[1] = new Pyramid_Random_Player<char>(name2, 'O');
                else if (type2 == 3)
                {
                    players[1] = new Pyramid_AI_Player<char>(name2, 'O');
                    players[1]->setBoard(B);
                }
                //-----------------------------------------------------------
                GameManager<char> Pyramid(B, players);
                Pyramid.run();
                delete B;
                for (int i = 0; i < 2; ++i)
                {
                    delete players[i];
                }
                system("pause");
            }
            else if (choice == 2)
            {
                Header();
                GameData(name1, name2, type1, type2);
                Player<char> *players[2];
                Four_Board<char> *B = new Four_Board<char>();
                if (type1 == 1)
                    players[0] = new Four_Player<char>(name1, 'X');
                else if (type1 == 2)
                    players[0] = new Four_Random_Player<char>('X');
                if (type2 == 1)
                    players[1] = new Four_Player<char>(name2, 'O');
                else if (type2 == 2)
                    players[1] = new Four_Random_Player<char>('O');
                GameManager<char> Four(B, players);
                Four.run();
                delete B;
                for (int i = 0; i < 2; ++i)
                {
                    delete players[i];
                }
                system("pause");
            }
            else if (choice == 3)
            {
                Header();
                GameData(name1, name2, type1, type2);
                Player<char> *players[2];
                X_O_Board5<char> *B = new X_O_Board5<char>();
                if (type1 == 1)
                    players[0] = new X_O_Player5<char>(name1, 'X');
                else if (type1 == 2)
                    players[0] = new X_O_Random_Player5<char>('X');
                if (type2 == 1)
                    players[1] = new X_O_Player5<char>(name2, 'O');
                else if (type2 == 2)
                    players[1] = new X_O_Random_Player5<char>('O');
                GameManager<char> G5x5(B, players);
                G5x5.run();
                delete B;
                for (int i = 0; i < 2; ++i)
                {
                    delete players[i];
                }
                system("pause");
            }
            else if (choice == 4)
            {
                Header();
                GameData(name1, name2, type1, type2);
                Player<char> *players[2];
                Word_Board<char> *B = new Word_Board<char>();
                if (type1 == 1)
                    players[0] = new Word_Player<char>(name1, 'X');
                else if (type1 == 2)
                    players[0] = new Word_Random_Player<char>(name1, 'X');
                if (type2 == 1)
                    players[1] = new Word_Player<char>(name2, 'O');
                else if (type2 == 2)
                    players[1] = new Word_Random_Player<char>(name2, 'O');
                GameManager<char> Word(B, players);
                Word.run();
                delete B;
                for (int i = 0; i < 2; ++i)
                {
                    delete players[i];
                }
                system("pause");
            }
            else if (choice == 5)
            {
                Header();
                vector<int> odd {1,3,5,7,9};
                vector<int> even {2,4,6,8};
                GameData(name1, name2, type1, type2);
                Player<int> *players[2];
                NUM_X_O_Board<int> *B = new NUM_X_O_Board<int>();
                if (type1 == 1)
                    players[0] = new NUM_X_O_Player<int>(name1, 'X', odd);
                else if (type1 == 2)
                    players[0] = new NUM_X_O_Random_Player<int>('X', odd);
                if (type2 == 1)
                    players[1] = new NUM_X_O_Player<int>(name2, 'O', even);
                else if (type2 == 2)
                    players[1] = new NUM_X_O_Random_Player<int>('O', even);
                GameManager<int> Numerical(B, players);
                Numerical.run();
                delete B;
                for (int i = 0; i < 2; ++i)
                {
                    delete players[i];
                }
                system("pause");
            }
            else if (choice == 6)
            {
                Header();
                GameData(name1, name2, type1, type2);
                Player<char> *players[2];
                Misere_Board<char> *B = new Misere_Board<char>();
                if (type1 == 1)
                    players[0] = new MiserePlayer<char>(name1, 'X');
                else if (type1 == 2)
                    players[0] = new MisereRandom_Player<char>('X');
                if (type2 == 1)
                    players[1] = new MiserePlayer<char>(name2, 'O');
                else if (type2 == 2)
                    players[1] = new MisereRandom_Player<char>('O');
                GameManager<char> Misere(B, players);
                Misere.run();
                delete B;
                for (int i = 0; i < 2; ++i)
                {
                    delete players[i];
                }
                system("pause");
            }
            else if (choice == 7)
            {
                Header();
                GameData(name1, name2, type1, type2);
                Player<char> *players[2];
                Ultimate_X_O_Board<char> *B = new Ultimate_X_O_Board<char>();
                if (type1 == 1)
                    players[0] = new Ultimate_X_O_Player<char>(name1, 'X');
                else if (type1 == 2)
                    players[0] = new Ultimate_X_O_Random_Player<char>('X');
                if (type2 == 1)
                    players[1] = new Ultimate_X_O_Player<char>(name2, 'O');
                else if (type2 == 2)
                    players[1] = new Ultimate_X_O_Random_Player<char>('O');
                GameManager<char> ultimate(B, players);
                ultimate.run();
                delete B;
                for (int i = 0; i < 2; ++i)
                {
                    delete players[i];
                }
                system("pause");
            }
            else if (choice == 8)
            {
                Header();
                GameData(name1, name2, type1, type2);
                Player<char> *players[2];
                SUS_Board<char> *B = new SUS_Board<char>();
                if (type1 == 1)
                    players[0] = new SUS_Player<char>(name1, 'S');
                else if (type1 == 2)
                    players[0] = new SUS_Random_Player<char>(name1, 'S');
                if (type2 == 1)
                    players[1] = new SUS_Player<char>(name2, 'U');
                else if (type2 == 2)
                    players[1] = new SUS_Random_Player<char>(name2, 'U');
                GameManager<char> SUS(B, players);
                SUS.run();
                delete B;
                for (int i = 0; i < 2; ++i)
                {
                    delete players[i];
                }
                system("pause");
            }
            else if (choice == 0)
                break;
            else
            {
                while (choice > 8 || choice < 0)
                {
                    cout << "\nWrong choice my dear 0_0! , enter a valid one: ";
                    cin_numbers(choice);
                }
                continue;
            }
            MainMenu();
            cin_numbers(choice);
        }
        exit();
    }
    //------------------------------------------------

public:
    void Run() { GameRunning(); }
};