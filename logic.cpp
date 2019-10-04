#include "init.h"
#include "ncurses.h"
#include "logic.h"
#include <iostream>
#include <vector>

extern Coord coord;
extern Coord square1;
extern Coord square2;
extern Coord square3;
extern Coord square4;
extern Coord square5;
extern Coord square6;
extern Coord square7;
extern Coord square8;
extern Coord square9;
extern Players player1;
extern Players player2;
const int maxNumMoves{9};
int movesMade[maxNumMoves] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int turn{1};

void moveToXAndY(int x, int y)
{
    coord.x = x;
    coord.y = y;
}

void chooseYourSymbol()
{
    while (!player1.symbol)
    {
        mvprintw(20, 20, "What Symbol are you using? X or O: ");
        refresh();
        char symbol{};
        symbol = getchar();
        if (symbol == 'X' || symbol == 'x')
        {
            printw("X");
            player1.symbol = 'X';
            player2.symbol = 'O';
        }
        else if (symbol == 'O' || symbol == 'o')
        {
            printw("O");
            player1.symbol = 'O';
            player2.symbol = 'X';
        }
        else
            mvprintw(19, 20, "That's not a symbol that can be used.");
    }
}

void positionSquare(int square, char symbol)
{
    int exit{0};
    char* c_symbol = new char(symbol);
    while (exit == 0)
    {
        switch(square)
        {
            case 1:
            {
                mvprintw(square1.x, square1.y, c_symbol);
                refresh();
                ++exit;
                break;
            }
            case 2:
            {
                mvprintw(square2.x, square2.y, c_symbol);
                refresh();
                ++exit;
                break;
            }
            case 3:
            {
                mvprintw(square3.x, square3.y, c_symbol);
                refresh();
                ++exit;
                break;
            }
            case 4:
            {
                mvprintw(square4.x, square4.y, c_symbol);
                refresh();
                ++exit;
                break;
            }
            case 5:
            {
                mvprintw(square5.x, square5.y, c_symbol);
                refresh();
                ++exit;
                break;
            }
            case 6:
            {
                mvprintw(square6.x, square6.y, c_symbol);
                refresh();
                ++exit;
                break;
            }
            case 7:
            {
                mvprintw(square7.x, square7.y, c_symbol);
                refresh();
                ++exit;
                break;
            }
            case 8:
            {
                mvprintw(square8.x, square8.y, c_symbol);
                refresh();
                ++exit;
                break;
            }
            case 9:
            {
                mvprintw(square9.x, square9.y, c_symbol);
                refresh();
                ++exit;
                    break;
            }
            default:
            {
                mvprintw(22, 20, "                                                 ");
                mvprintw(22, 20, "That's not a good location.");
                refresh();
                break;
            }
        }
    }
}
void chooseYourPosition(Players player, int x)
{
    int exit{};
    while(exit == 0)
    {
        mvprintw(20, 20, "                                           ");
        mvprintw(20, 20, "Choose your Square ");
        if (player.number == 1)
        {
            printw("Player 1: ");
        }
        else if (player.number == 2)
            printw("Player 2: ");
        refresh();
        int pos;
        scanw("%d", &pos);
        if (pos > 0 && pos < 10 && pos != movesMade[0] && pos != movesMade[1] && pos != movesMade[2] && pos != movesMade[3] && pos != movesMade[4] &&
            pos != movesMade[5] && pos != movesMade[6] && pos != movesMade[7] && pos != movesMade[8])
        {
            positionSquare(pos, player.symbol);
            movesMade[x] = pos;
            ++turn;
            ++exit;
        }
        else
        {
            mvprintw(19, 20, "                                                 ");
            mvprintw(19, 20, "That's not an available square.");
            refresh();
        }
    }
}

void clearScreen()
{
    for (int x = 0; x < 25; x++)
    {
        mvprintw(x, 1, "                                                                               ");
        refresh();
    }
}
void playGame()
{
    while (turn <= 10)
    {
        if (turn == 1 || turn == 3 || turn == 5 || turn == 7 || turn == 9)
            chooseYourPosition(player1, turn);
        else if (turn == 2 || turn == 4 || turn == 6 || turn == 8)
            chooseYourPosition(player2, turn);
        else if (turn == 10)
        {
            ++turn;
            endGame();
        }
    }
}
