#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <map>
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

	std::string mainSceneName;
	std::string projectPath;

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
	bool InitGame();
	void StartLoop();
};

#endif