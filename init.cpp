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
    if(x != 1 && x != 2)
    {
        mvprintw(11, 35, "NOBODY WON.");
    }
    else if(x == 1)
        mvprintw(11, 35, "Player 1 is the WINNER");
    else if (x == 2)
        mvprintw(11, 35, "Player 1 is the WINNER");
    attroff(A_BOLD);
    getch();
    endwin();
}

void drawGrid()
{
    moveToXAndY(5, 21);
    std::string line  {"         |         |        "};
    const char* c_line = line.c_str();
    std::string across{"----------------------------"};
    const char* c_across = across.c_str();
    int lineSize{3};
    int x{1};
    while (x <= lineSize)
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
        x++;
    }
}

