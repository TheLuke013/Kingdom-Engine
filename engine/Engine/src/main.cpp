#include "Game.h"
#include <iostream>

const char* window_name = "";
int window_width = 0;
int window_height = 0;

int main(int argc, char* argv[])
{
	//verifica os argumentos passados
	if (argc == 4)
	{
		for (int i = 0; i < argc; i++)
		{
			//Itera sobre os argumentos e atribui os valores as variaveis
			window_name = argv[1];
			window_width = std::stoi(argv[2]);
			window_height = std::stoi(argv[3]);
		}
	}
	else
	{
		//Imprime mensagem de erro se os argumentos passados nao forem igual a 4
		std::cout << "Usage: " << argv[0] << " <window_name> <window_width> <window_height>" << std::endl;
		return 1;
	}

	Game game;
	game.initGame(window_name, window_width, window_height);
	game.startLoop();

	return 0;
}
