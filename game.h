#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "init.h"
void moveToXAndY(int x = 0, int y = 0);
void chooseYourPosition(Players player);
void chooseYourSymbol(int players);
void positionSquare(int square, int playerSymbol);
int playGame(int opponent);
void mvClearToEOL(int x, int y);

#endif // GAME_H_INCLUDED
