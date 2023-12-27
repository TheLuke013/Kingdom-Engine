#include "Game.h"

int main(int, char**)
{
    Game game;
	game.initGame("My Game", 640, 480);
	game.startLoop();

    return 0;
}
