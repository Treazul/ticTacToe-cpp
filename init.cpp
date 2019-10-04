#include <iostream>
#include <ncurses.h>
#include "init.h"
#include "logic.h"

Coord coord = {0, 0};
Coord square1 = {6, 25};
Coord square2 = {6, 35};
Coord square3 = {6, 45};
Coord square4 = {10, 25};
Coord square5 = {10, 35};
Coord square6 = {10, 45};
Coord square7 = {14, 25};
Coord square8 = {14, 35};
Coord square9 = {14, 45};
Players player1 = {1, 0};
Players player2 = {2, 0};


void startGame()
{
    initscr();
    cbreak();
}


void endGame()
{
    clearScreen();
    attron(A_BOLD);
    mvprintw(10, 35, "GAME OVER.");
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

