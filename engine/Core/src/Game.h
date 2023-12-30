#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include "../../ThirdParty/Irrlicht/include/irrlicht.h"

#include "SceneManager.h"
#include "Utils.h"
#include "Window.h"

class Game
{
private:
	std::map<std::string, std::string> gameConfigData; //dados de config. do jogo

	std::string mainSceneName; //nome da cena principal
	std::string projectPath; //caminho do sistema ao diretorio do projeto
	std::vector<std::string> scriptPaths;
	std::map<std::string, std::string> scriptNames;

	//Engine classes
	Window* window;
	SceneManager* sceneManager;

	//Irrlicht

public:
	Game();
    ~Game();
	bool LoadData(const std::map<std::string, std::string> &gameConfigData, std::string projectPath);
	bool RegisterScripts();
	bool InitGame();
	void RunGame();
};

#endif