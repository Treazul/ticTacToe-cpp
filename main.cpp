#include "init.h"
#include "game.h"
#include <ncurses.h>


int main()
{
    // Initialise nCurses.
    initNcurses();

    // Draw the game's grid
    drawGrid();
    // Play the game, the  return of 1 means P1 won, 2 means P2 won and 3 means nobody won
    // Anything other than those 3 numbers means something went seriously wrong.
    int winner = playGame();
    endGame(winner);
    return 0;
}
