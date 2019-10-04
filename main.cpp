#include "init.h"
#include "logic.h"
#include <iostream>
#include <ncurses.h>


int main()
{
    startGame();
    drawGrid();
    refresh();
    chooseYourSymbol();
    playGame();
    return 0;
}
