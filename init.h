#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED
// Set a global variable for coordinates being exactly 0.
void startGame();
void endGame();

struct Coord
{
    int x;
    int y;
};

struct Players
{
    int number;
    char symbol;
};
void drawGrid();


#endif // INIT_H_INCLUDED
