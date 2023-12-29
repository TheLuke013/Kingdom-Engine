#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include "../../ThirdParty/Irrlicht/include/irrlicht.h"

#include "SceneManager.h"
#include "Utils.h"

class Game
{
private:
	//janela do jogo
	std::string windowTitle;
	int windowWidth;
	int windowHeight;

	std::string mainSceneName; //nome da cena principal
	std::string projectPath; //caminho do sistema ao diretorio do projeto
	std::vector<std::string> scriptPaths;
	std::map<std::string, std::string> scriptNames;

	Color bgColor; //cor de fundo

	//Engine classes
	SceneManager* sceneManager;

	//Irrlicht
    irr::IrrlichtDevice* device;
	irr::video::IVideoDriver* driver;
	irr::gui::IGUIEnvironment* guiEnv;

public:
	Game();
    ~Game();
	bool LoadData(const std::map<std::string, std::string> &gameConfigData, std::string projectPath);
	bool RegisterScripts();
	bool InitGame();
	void StartLoop();
};

#endif