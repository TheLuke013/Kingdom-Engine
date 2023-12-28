#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <map>
#include <codecvt>
#include "../../ThirdParty/Irrlicht/include/irrlicht.h"

#include "SceneManager.h"

class Game
{
private:
	//janela do jogo
	std::string windowTitle;
	int windowWidth;
	int windowHeight;

	//Engine classes
	SceneManager* scene_manager;

	//Irrlicht
    irr::IrrlichtDevice* device;
	irr::video::IVideoDriver* driver;
	irr::gui::IGUIEnvironment* gui_env;

public:
	Game();
    ~Game();
	bool LoadData(const std::map<std::string, std::string> &gameConfigData);
	bool InitGame();
	void StartLoop();
};

#endif