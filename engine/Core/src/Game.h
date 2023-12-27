#ifndef GAME_H
#define GAME_H

#include <string>
#include "../../ThirdParty/Irrlicht/include/irrlicht.h"

class Game
{
private:
    irr::IrrlichtDevice* device;
	irr::video::IVideoDriver* driver;
	irr::scene::ISceneManager* scene_manager;
	irr::gui::IGUIEnvironment* gui_env;

public:
    ~Game();
	bool initGame(const char* windowTitle, int windowW, int windowH);
	void startLoop();
};

#endif