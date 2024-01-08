#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <map>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "SceneManager.h"
#include "Utils.h"
#include "Window.h"
#include "Project.h"

class Game
{
private:
	std::vector<std::string> scriptPaths; //caminho dos scripts do projeto
	std::map<std::string, std::string> scriptNames; //nomes + caminhos dos projetos

	//Engine classes
	static Window* window;
	static SceneManager* sceneManager;

public:
	Game();
    ~Game();
	bool LoadData(Project& project);
	bool RegisterScripts(Project& project);
	bool InitGame(Project& project);
	void RunGame();

	static Window* GetWindow();
	static SceneManager* GetSceneManager();
	static void QuitGame();
};

#endif