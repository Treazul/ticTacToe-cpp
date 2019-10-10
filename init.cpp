#include "init.h"
#include "game.h"
#include <ncurses.h>
#include <string>

// Initialise the structs for initial coordinates, the centre of the squares and the players
Coord coord = {0, 0};
Square square1 = {1, 6, 25};
Square square2 = {2, 6, 35};
Square square3 = {3, 6, 45};
Square square4 = {4, 10, 25};
Square square5 = {5, 10, 35};
Square square6 = {6, 10, 45};
Square square7 = {7, 14, 25};
Square square8 = {8, 14, 35};
Square square9 = {9, 14, 45};
Players player1 = {1, 0};
Players player2 = {2, 0};
Players computer = {3, 0};
// Start nCurses up.
void initNcurses()
{
    initscr();
    cbreak();
}

void endGame(int x)
{
    moveToXAndY(11, 30);
    int yQuitCoord{20};
    clear();
    attron(A_BOLD);
    // Celebrate the winner or none at all if needed.
    if(x <= DRAW)
    {
        mvprintw(coord.x -1, coord.y, "GAME OVER.");
        if(x <= COMPUTER)
        {
            attron(A_UNDERLINE);
            if(x == PLAYER_1)
                mvprintw(coord.x, coord.y, "Player 1");
            else if (x == PLAYER_2)
                mvprintw(coord.x, coord.y, "Player 2");
            else if (x == COMPUTER)
                mvprintw(coord.x, coord.y, "The Computer");
            attroff(A_UNDERLINE);
            printw(" is the WINNER");
        }
        else if(x == DRAW)
        {
            mvprintw(coord.x, coord.y, "NOBODY WON.");
            attroff(A_BOLD);
            attron(A_DIM);
            mvprintw(coord.x + 1, coord.y+3, "BOO!");
            attroff(A_DIM);
        }
    }
    else if(x == QUIT)
    {
        mvprintw(coord.x -1, yQuitCoord, "Sorry to see you go!");
        mvprintw(coord.x, yQuitCoord, "I hope you'll play my game another time.");
    }
    else
    {
        mvprintw(coord.x -1, coord.y, "A serious error has occurred.");
        mvprintw(coord.x, coord.y, "Please inform the code maintainer as soon as possible");
        mvprintw(coord.x +1, coord.y, "Quote code: 1435");
    }
    attroff(A_BOLD);
    getch();
    endwin();
}
// Draw the playing grid.

void drawGrid()
{
    clear();
    mvprintw(2, 21, "Would you like to play a game of");
    mvprintw(3, 30, "Tic Tac Toe?");
    moveToXAndY(5, 21);
    std::string line  {"         |         |         "};
    const char* c_line = line.c_str();
    std::string across{"-----------------------------"};
    const char* c_across = across.c_str();
    int lineSize{3};
    // Continue to draw | | and ---- until it fits the correct grid size.
    // This allows me to potentially create a bigger tic-tac-toe grid later if needed.
    for (int x = 1; x <= lineSize; x++ )
    {
        // Line, Line, Line, Across until it reaches the last set of squares where you don't want an across.
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
    // Add indicators to the square number and make them muted.
    attron(A_DIM);
    mvprintw(square1.x, square1.y, "1");
    mvprintw(square2.x, square2.y, "2");
    mvprintw(square3.x, square3.y, "3");
    mvprintw(square4.x, square4.y, "4");
    mvprintw(square5.x, square5.y, "5");
    mvprintw(square6.x, square6.y, "6");
    mvprintw(square7.x, square7.y, "7");
    mvprintw(square8.x, square8.y, "8");
    mvprintw(square9.x, square9.y, "9");
    attroff(A_DIM);
}

