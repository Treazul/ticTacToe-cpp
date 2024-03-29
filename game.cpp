#include "init.h"
#include "game.h"
#include "logic.h"
#include <ncurses.h>
#include <iostream>


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
extern Players computer;
// Initialise the board with no symbol, board[0] will serve to count the entire contents of the rest of the board.
int board[10] = {0, NOSYMBOL, NOSYMBOL, NOSYMBOL, NOSYMBOL, NOSYMBOL, NOSYMBOL, NOSYMBOL, NOSYMBOL, NOSYMBOL};

int turn{1};

void mvClearToEOL(int x, int y);

void moveToXAndY(int x, int y)
{
    coord.x = x;
    coord.y = y;
}

void chooseYourSymbol(int players)
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
            player1.symbol = SYMBOLX;
            if (players == HUMAN)
                player2.symbol = SYMBOLO;
            else if (players == NOTHUMAN)
                computer.symbol = SYMBOLO;
        }
        else if (symbol == 'O' || symbol == 'o')
        {
            player1.symbol = SYMBOLO;
            if (players == HUMAN)
                player2.symbol = SYMBOLX;
            else if (players == NOTHUMAN)
                computer.symbol = SYMBOLX;
        }
        else
            mvprintw(19, 20, "That's not a symbol that can be used.");
    }
}
void boardAdd(int square, int playerSymbol);
void positionSquare(int square, int playerSymbol)
{
    const char* symbol{};
    bool exit{false};
    if (playerSymbol == SYMBOLX)
        symbol = "X";
    else if (playerSymbol == SYMBOLO)
        symbol = "O";
    boardAdd(square, playerSymbol);
    while (!exit)
    {
        switch(square)
        {
            case 1:
            {
                mvprintw(square1.x, square1.y, symbol);
                refresh();
                exit = true;
                break;
            }
            case 2:
            {
                mvprintw(square2.x, square2.y, symbol);
                refresh();
                exit = true;
                break;
            }
            case 3:
            {
                mvprintw(square3.x, square3.y, symbol);
                refresh();
                exit = true;
                break;
            }
            case 4:
            {
                mvprintw(square4.x, square4.y, symbol);
                refresh();
                exit = true;
                break;
            }
            case 5:
            {
                mvprintw(square5.x, square5.y, symbol);
                refresh();
                exit = true;
                break;
            }
            case 6:
            {
                mvprintw(square6.x, square6.y, symbol);
                refresh();
                exit = true;
                break;
            }
            case 7:
            {
                mvprintw(square7.x, square7.y, symbol);
                refresh();
                exit = true;
                break;
            }
            case 8:
            {
                mvprintw(square8.x, square8.y, symbol);
                refresh();
                exit = true;
                break;
            }
            case 9:
            {
                mvprintw(square9.x, square9.y, symbol);
                refresh();
                exit = true;
                break;
            }
            // This shouldn't trigger as invalid position should be handled by chooseYourPosition.
            default:
            {
                moveToXAndY(22, 20);
                mvClearToEOL(coord.x, coord.y);
                mvprintw(coord.x, coord.y, "That's not a good location.");
                refresh();
                break;
            }
        }
    }
}

void boardAdd(int square, int playerSymbol)
{
    board[square] = playerSymbol;
    board[0] += playerSymbol;
}

int checkWin()
{
    int line1{board[1]+board[2]+board[3]};
    int line2{board[4]+board[5]+board[6]};
    int line3{board[7]+board[8]+board[9]};
    int vert1{board[1]+board[4]+board[7]};
    int vert2{board[2]+board[5]+board[8]};
    int vert3{board[3]+board[6]+board[9]};
    int diag1{board[1]+board[5]+board[9]};
    int diag2{board[3]+board[5]+board[7]};

    if (line1 == 3 || line2 == 3 || line3 == 3 || vert1 == 3 || vert2 == 3 || vert3 == 3 ||
        diag1 == 3 || diag2 == 3)
        return SYMBOLX;
    else if (line1 == 6 || line2 == 6 || line3 == 6 || vert1 == 6 || vert2 == 6 || vert3 == 6 ||
        diag1 == 6 || diag2 == 6)
        return SYMBOLO;
    else
        return false;
}

void chooseYourPosition(Players player)
{
    moveToXAndY(20, 20);
    mvClearToEOL(coord.x -1, coord.y);
    bool exit{false};
    while(!exit)
    {
        mvClearToEOL(coord.x, coord.y);
        mvprintw(coord.x, coord.y, "Choose your Square ");
        if (player.number == 1)
        {
            printw("Player 1: ");
        }
        else if (player.number == 2)
            printw("Player 2: ");
        refresh();
        int pos;
        scanw("%d", &pos);
        if (pos > 0 && pos < 10 && board[pos] == NOSYMBOL)
        {
            positionSquare(pos, player.symbol);
            ++turn;
            exit = true;
        }
        else
        {
            mvClearToEOL(coord.x -1, coord.y);
            mvprintw(coord.x -1, coord.y, "That's not an available square.");
            refresh();
        }
    }
}

int playGame(int opponent)
{
    // Choose the symbol that player 1 is going to use
    chooseYourSymbol(opponent);
    bool exit{false};
    while(!exit)
    {
        if ((turn % 2) && turn < 10 && !checkWin())
            chooseYourPosition(player1);
        else if (!(turn % 2) && turn < 10 && !checkWin())
        {
            if(opponent == HUMAN)
                chooseYourPosition(player2);
            else if (opponent == NOTHUMAN)
                computerChoosePosition();
        }
        else if (checkWin())
        {
            if (checkWin() == SYMBOLO)
            {
                if (player1.symbol == SYMBOLO)
                    return PLAYER_1;
                else if (player2.symbol == SYMBOLO)
                    return PLAYER_2;
                else if (computer.symbol == SYMBOLO)
                    return COMPUTER;
            }
            else if (checkWin() == SYMBOLX)
            {
                if (player1.symbol == SYMBOLX)
                    return PLAYER_1;
                else if (player2.symbol == SYMBOLX)
                    return PLAYER_2;
                else if (computer.symbol == SYMBOLX)
                    return COMPUTER;
            }
        }
        else if ((board[0] == 13 || board[0] == 14) && !checkWin())
        {
            exit = true;
            return DRAW;
        }
        else
        {
            exit = true;
            return ERROR_DRAW;
        }
    }
    return ERROR;
}
// Clear from the current location to the end of line
void mvClearToEOL(int x, int y)
{
    mvprintw(x, y, "                                                                                              ");
}
