#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED
// Set a global variable for coordinates being exactly 0.
void startGame();
void endGame(int x);

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
void drawGrid();


#endif // INIT_H_INCLUDED
