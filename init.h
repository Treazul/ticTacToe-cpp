#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

void initNcurses();
void endGame(int x);
void drawGrid();
//enums
enum Symbol
{
    NOSYMBOL = -10,
    SYMBOLX = 1,
    SYMBOLO = 2,
};

enum WinState
{
    PLAYER_1 = 1,
    PLAYER_2 = 2,
    COMPUTER = 3,
    DRAW = 4,
};
enum GameState
{
    QUIT = 5,
    ERROR = 6,
    ERROR_DRAW = 7,
    ERROR_COMPUTER_CHOOSE = 8,
};

enum OpponentState
{
    HUMAN,
    NOTHUMAN,
};

// Structs
struct Coord
{
    int x;
    int y;
};

struct Square
{
    int num;
    int x;
    int y;
};

struct Players
{
    int number;
    int symbol;
};


#endif // INIT_H_INCLUDED
