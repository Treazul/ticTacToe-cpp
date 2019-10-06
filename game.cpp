#include "init.h"
#include "game.h"
#include <ncurses.h>

extern Coord coord;
extern Square square1;
extern Square square2;
extern Square square3;
extern Square square4;
extern Square square5;
extern Square square6;
extern Square square7;
extern Square square8;
extern Square square9;
extern Players player1;
extern Players player2;
int movesMade[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int turn{1};

void mvClearToEOL(int x, int y);

void moveToXAndY(int x, int y)
{
    coord.x = x;
    coord.y = y;
}

void chooseYourSymbol()
{
    while (!player1.symbol)
    {
        mvClearToEOL(20, 20);
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
    bool exit{false};
    char* c_symbol = new char(symbol);
    while (!exit)
    {
        switch(square)
        {
            case 1:
            {
                mvprintw(square1.x, square1.y, c_symbol);
                refresh();
                square1.currentSymbol = symbol;
                exit = true;
                break;
            }
            case 2:
            {
                mvprintw(square2.x, square2.y, c_symbol);
                refresh();
                square2.currentSymbol = symbol;
                exit = true;
                break;
            }
            case 3:
            {
                mvprintw(square3.x, square3.y, c_symbol);
                refresh();
                square3.currentSymbol = symbol;
                exit = true;
                break;
            }
            case 4:
            {
                mvprintw(square4.x, square4.y, c_symbol);
                refresh();
                square4.currentSymbol = symbol;
                exit = true;
                break;
            }
            case 5:
            {
                mvprintw(square5.x, square5.y, c_symbol);
                refresh();
                square5.currentSymbol = symbol;
                exit = true;
                break;
            }
            case 6:
            {
                mvprintw(square6.x, square6.y, c_symbol);
                refresh();
                square6.currentSymbol = symbol;
                exit = true;
                break;
            }
            case 7:
            {
                mvprintw(square7.x, square7.y, c_symbol);
                refresh();
                square7.currentSymbol = symbol;
                exit = true;
                break;
            }
            case 8:
            {
                mvprintw(square8.x, square8.y, c_symbol);
                refresh();
                square8.currentSymbol = symbol;
                exit = true;
                break;
            }
            case 9:
            {
                mvprintw(square9.x, square9.y, c_symbol);
                refresh();
                square9.currentSymbol = symbol;
                exit = true;
                break;
            }
            default:
            {
                mvClearToEOL(22, 20);
                mvprintw(22, 20, "That's not a good location.");
                refresh();
                break;
            }
        }
    }
}

bool checkXWin()
{
    char s1 = square1.currentSymbol;
    char s2 = square2.currentSymbol;
    char s3 = square3.currentSymbol;
    char s4 = square4.currentSymbol;
    char s5 = square5.currentSymbol;
    char s6 = square6.currentSymbol;
    char s7 = square7.currentSymbol;
    char s8 = square8.currentSymbol;
    char s9 = square9.currentSymbol;
    /*
    1 2 3
    4 5 6
    7 8 9
    */

    // First Line across
    if (s1 == 'X' && s2 == 'X' && s3 == 'X')
        return true;
    // Second Line across
    else if (s4 == 'X' && s5 == 'X' && s6 == 'X')
        return true;
    // Third Line across
    else if (s7 == 'X' && s8 == 'X' && s9 == 'X')
        return true;
    // First Line vertical
    else if (s1 == 'X' && s4 == 'X' && s7 == 'X')
        return true;
    // Second Line vertical
    else if (s2 == 'X' && s5 == 'X' && s8 == 'X')
        return true;
    // Third Line vertical
    else if (s3 == 'X' && s6 == 'X' && s9 == 'X')
        return true;
    // Diagonal from top left to bottom right
    else if (s1 == 'X' && s5 == 'X' && s9 == 'X')
        return true;
    // Diagonal from top right to bottom left
    else if (s7 == 'X' && s5 == 'X' && s3 == 'X')
        return true;
    else
        return false;
}

bool checkOWin()
{
    char s1 = square1.currentSymbol;
    char s2 = square2.currentSymbol;
    char s3 = square3.currentSymbol;
    char s4 = square4.currentSymbol;
    char s5 = square5.currentSymbol;
    char s6 = square6.currentSymbol;
    char s7 = square7.currentSymbol;
    char s8 = square8.currentSymbol;
    char s9 = square9.currentSymbol;
    /*
    1 2 3
    4 5 6
    7 8 9
    */

    // First Line across
    if (s1 == 'O' && s2 == 'O' && s3 == 'O')
        return true;
    // Second Line across
    else if (s4 == 'O' && s5 == 'O' && s6 == 'O')
        return true;
    // Third Line across
    else if (s7 == 'O' && s8 == 'O' && s9 == 'O')
        return true;
    // First Line vertical
    else if (s1 == 'O' && s4 == 'O' && s7 == 'O')
        return true;
    // Second Line vertical
    else if (s2 == 'O' && s5 == 'O' && s8 == 'O')
        return true;
    // Third Line vertical
    else if (s3 == 'O' && s6 == 'O' && s9 == 'O')
        return true;
    // Diagonal from top left to bottom right
    else if (s1 == 'O' && s5 == 'O' && s9 == 'O')
        return true;
    // Diagonal from top right to bottom left
    else if (s7 == 'O' && s5 == 'O' && s3 == 'O')
        return true;
    else
        return false;
}

void chooseYourPosition(Players player, int x)
{
    mvClearToEOL(19, 20);
    bool exit{false};
    while(!exit)
    {
        mvClearToEOL(20, 20);
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
            exit = true;
        }
        else
        {
            mvClearToEOL(19, 20);
            mvprintw(19, 20, "That's not an available square.");
            refresh();
        }
    }
}

int playGame()
{
    // Choose the symbol that player 1 is going to use
    chooseYourSymbol();
    bool exit{false};
    while(!exit)
    {
        if (turn == 1 || turn == 3 || turn == 5 || turn == 7 || turn == 9)
        {
            chooseYourPosition(player1, turn);
            if (player1.symbol == 'X')
            {
                if (checkXWin())
                {
                    exit = true;
                    return 1;
                }
            }
            else if (player1.symbol == 'O')
            {
                if (checkOWin())
                {
                     exit = true;
                    return 1;
                }
            }
        }
        else if (turn == 2 || turn == 4 || turn == 6 || turn == 8)
        {
                chooseYourPosition(player2, turn);
                if (player2.symbol == 'X')
                {
                    if (checkXWin())
                    {
                        exit = true;
                        return 2;
                    }
                }
                else if (player2.symbol == 'O')
                {
                    if (checkOWin())
                    {
                        exit = true;
                        return 2;
                    }
                }
        }
        else if (square1.currentSymbol != 'b' && square2.currentSymbol != 'b' && square3.currentSymbol != 'b' && square4.currentSymbol != 'b' && square5.currentSymbol != 'b' && square6.currentSymbol != 'b' && square7.currentSymbol != 'b' && square8.currentSymbol != 'b' && square9.currentSymbol != 'b' && !checkXWin() && !checkOWin())
        {
            exit = true;
            return 3;
        }
    }
    // 5 is the error exit, 4 is reserved for quitting naturally from the menu.
    return 5;
}
// Clear from the current location to the end of line
void mvClearToEOL(int x, int y)
{
    mvprintw(x, y, "                                                                                              ");
}
