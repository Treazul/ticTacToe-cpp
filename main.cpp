#include "init.h"
#include "game.h"
#include "menu.h"
#include <ncurses.h>


int main()
{
    // Initialise nCurses.
    initNcurses();

    bool madeChoice = false;
    while (!madeChoice)
    {
        int choice{startMenu()};
        switch(choice)
        {
        case 1:
            {
                drawGrid();
                int winner = playGame(HUMAN);
                endGame(winner);
                madeChoice = true;
                break;
            }
        case 2:
            {
                drawGrid();
                int winner = playGame(NOTHUMAN);
                endGame(winner);
                madeChoice = true;
                break;
            }
        case 3:
            {
                endGame(QUIT);
                madeChoice = true;
                break;
            }
        }
    }
    return 0;
}
