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



#endif // INIT_H_INCLUDED
