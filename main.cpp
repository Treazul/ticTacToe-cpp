#include "init.h"
#include "logic.h"
#include <ncurses.h>


int main()
{
    startGame();
    drawGrid();
    refresh();
    chooseYourSymbol();
    int winner;
    winner = playGame();
    endGame(winner);
    return 0;
}
