#include "game.h"
#include "init.h"
#include <random>
#include <ctime>

extern Players computer;
extern Players player1;
extern int board[10];
extern int turn;
int possCheck(int symbol);
int lastNumbers[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int arraySize = 9;
int iteration = {0};
int getRandomNumber()
{
    std::mt19937 mersenne(static_cast<std::mt19937::result_type>(std::time(nullptr)));
    std::uniform_int_distribution<> die(1,9);
    int number = die(mersenne);
    return number;
}

void computerChoosePosition()
{
    int pos{0};
    if (possCheck(computer.symbol))
    {
        positionSquare(possCheck(computer.symbol), computer.symbol);
        ++turn;
    }
    else if (possCheck(player1.symbol))
    {
        positionSquare(possCheck(player1.symbol), computer.symbol);
        ++turn;
    }
    else
    {
        bool endLoop{false};
        while(!endLoop)
        {
            pos = getRandomNumber();
            if(board[pos] == NOSYMBOL)
            {
                positionSquare(pos, computer.symbol);
                ++turn;
                endLoop = true;
            }
        }
    }
}

int possCheck(int symbol)
{
    if(board[1] == NOSYMBOL && board[2] == symbol && board[3] == symbol)
        return 1;
    else if (board[2] == NOSYMBOL && board[1] == symbol && board[3] == symbol)
        return 2;
    else if (board[3] == NOSYMBOL && board[1] == symbol && board[2] == symbol)
        return 3;
    else if (board[4] == NOSYMBOL && board[5] == symbol && board[6] == symbol)
        return 4;
    else if (board[5] == NOSYMBOL && board[4] == symbol && board[6] == symbol)
        return 5;
    else if (board[6] == NOSYMBOL && board[4] == symbol && board[5] == symbol)
        return 6;
    else if (board[7] == NOSYMBOL && board[8] == symbol && board[9] == symbol)
        return 7;
    else if (board[8] == NOSYMBOL && board[7] == symbol && board[9] == symbol)
        return 8;
    else if (board[9] == NOSYMBOL && board[7] == symbol && board[8] == symbol)
        return 9;
    else if (board[1] == NOSYMBOL && board[4] == symbol && board[7] == symbol)
        return 1;
    else if (board[4] == NOSYMBOL && board[1] == symbol && board[7] == symbol)
        return 4;
    else if (board[7] == NOSYMBOL && board[1] == symbol && board[4] == symbol)
        return 7;
    else if (board[2] == NOSYMBOL && board[5] == symbol && board[8] == symbol)
        return 2;
    else if (board[5] == NOSYMBOL && board[2] == symbol && board[8] == symbol)
        return 5;
    else if (board[8] == NOSYMBOL && board[2] == symbol && board[5] == symbol)
        return 8;
    else if (board[3] == NOSYMBOL && board[6] == symbol && board[9] == symbol)
        return 3;
    else if (board[6] == NOSYMBOL && board[3] == symbol && board[9] == symbol)
        return 6;
    else if (board[9] == NOSYMBOL && board[3] == symbol && board[6] == symbol)
        return 9;
    else if (board[1] == NOSYMBOL && board[5] == symbol && board[9] == symbol)
        return 1;
    else if (board[5] == NOSYMBOL && board[1] == symbol && board[9] == symbol)
        return 5;
    else if (board[9] == NOSYMBOL && board[1] == symbol && board[5] == symbol)
        return 9;
    else if (board[3] == NOSYMBOL && board[5] == symbol && board[7] == symbol)
        return 3;
    else if (board[5] == NOSYMBOL && board[3] == symbol && board[7] == symbol)
        return 5;
    else if (board[7] == NOSYMBOL && board[3] == symbol && board[5] == symbol)
        return 7;
    else
        return 0;
}
