#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include "../../ThirdParty/Irrlicht/include/irrlicht.h"

#include "SceneManager.h"
#include "Utils.h"
#include "LuaScripting.h"

class Game
{
private:
	//janela do jogo
	std::string windowTitle;
	int windowWidth;
	int windowHeight;

	std::string mainSceneName;
	std::string projectPath;

	Color bgColor; //cor de fundo

	//Engine classes
	SceneManager* sceneManager;
	LuaScripting luaScript;

	//Irrlicht
    irr::IrrlichtDevice* device;
	irr::video::IVideoDriver* driver;
	irr::gui::IGUIEnvironment* guiEnv;

public:
	Game();
    ~Game();
	bool LoadData(const std::map<std::string, std::string> &gameConfigData, std::string projectPath);
	bool InitGame();
	void StartLoop();
};

#endif