#include "init.h"
#include "logic.h"
#include <ncurses.h>
#include <string>

Coord coord = {0, 0};
Square square1 = {6, 25, 'b'};
Square square2 = {6, 35, 'b'};
Square square3 = {6, 45, 'b'};
Square square4 = {10, 25, 'b'};
Square square5 = {10, 35, 'b'};
Square square6 = {10, 45, 'b'};
Square square7 = {14, 25, 'b'};
Square square8 = {14, 35, 'b'};
Square square9 = {14, 45, 'b'};
Players player1 = {1, 0};
Players player2 = {2, 0};


void startGame()
{
    initscr();
    cbreak();
}

void endGame(int x)
{
    clearScreen();
    attron(A_BOLD);
    mvprintw(10, 35, "GAME OVER.");
    if(x == 1)
        {
            attron(A_UNDERLINE);
            mvprintw(11, 35, "Player 1");
            attroff(A_UNDERLINE);
            printw(" is the WINNER");
        }
    else if (x == 2)
        {
            attron(A_UNDERLINE);
            mvprintw(11, 35, "Player 2");
            attroff(A_UNDERLINE);
            printw("is the WINNER");
        }
    else if(x == 3)
        {
            mvprintw(11, 35, "NOBODY WON.");
            attroff(A_BOLD);
            attron(A_DIM);
            mvprintw(12, 38, "BOO!");
            attroff(A_DIM);
        }
    else
    {
        mvprintw(10, 35, "This message shouldn't ever be seen. What hath thou done?!?");
        mvprintw(11, 35, "Error code: Whiskey Uniform Tango.");
    }
    attroff(A_BOLD);
    getch();
    endwin();
}

void drawGrid()
{
    mvprintw(2, 21, "Would you like to play a game of");
    mvprintw(3, 30, "Tic Tac Toe?");
    moveToXAndY(5, 21);
    std::string line  {"         |         |         "};
    const char* c_line = line.c_str();
    std::string across{"-----------------------------"};
    const char* c_across = across.c_str();
    int lineSize{3};
    for (int x = 1; x <= lineSize; x++ )
    {
        if (x != lineSize)
        {
            mvprintw(coord.x, coord.y, c_line);
            refresh();
            mvprintw(coord.x+1, coord.y, c_line);
            refresh();
            mvprintw(coord.x+2, coord.y, c_line);
            refresh();
            mvprintw(coord.x+3, coord.y, c_across);
            refresh();
            moveToXAndY(coord.x + 4, coord.y);
        }
        else
        {
            mvprintw(coord.x, coord.y, c_line);
            refresh();
            mvprintw(coord.x+1, coord.y, c_line);
            refresh();
            mvprintw(coord.x+2, coord.y, c_line);
            refresh();
        }
    }
    mvprintw(square1.x, square1.y, "1");
    mvprintw(square2.x, square2.y, "2");
    mvprintw(square3.x, square3.y, "3");
    mvprintw(square4.x, square4.y, "4");
    mvprintw(square5.x, square5.y, "5");
    mvprintw(square6.x, square6.y, "6");
    mvprintw(square7.x, square7.y, "7");
    mvprintw(square8.x, square8.y, "8");
    mvprintw(square9.x, square9.y, "9");
}

