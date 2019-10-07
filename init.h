#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

void initNcurses();
void endGame(int x);
void drawGrid();

// Structs
struct Coord
{
    int x;
    int y;
};

struct Square
{
    int x;
    int y;
    char currentSymbol;
};

struct Players
{
    int number;
    char symbol;
};

enum WinState
{
    PLAYER_1 = 1,
    PLAYER_2 = 2,
    DRAW = 3,
};
enum GameState
{
    QUIT = 4,
    ERROR = 5,
};


#endif // INIT_H_INCLUDED
