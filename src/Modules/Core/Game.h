#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <irrlicht.h>

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
	static Window* window;
	static SceneManager* sceneManager;

	//Irrlicht

public:
	Game();
    ~Game();
	bool LoadData(const std::map<std::string, std::string> &gameConfigData, std::string projectPath);
	bool RegisterScripts();
	bool InitGame();
	void RunGame();

	static Window* GetWindow();
	static SceneManager* GetSceneManager();
	static void QuitGame();
};

#endif