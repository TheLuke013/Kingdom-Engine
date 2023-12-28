#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "../../ThirdParty/Irrlicht/include/irrlicht.h"
#include "Scene.h"
#include "Utils.h"
#include <vector>
#include <iostream>

class SceneManager
{
private:
    static SceneManager* instance; //instancia da classe

    irr::scene::ISceneManager* sceneManager;
    std::vector<Scene*> scenes; //armazena ponteiros para as cenas
    Scene* currentScene;

    Scene* mainScene;

public:
    ~SceneManager();

    static SceneManager* GetInstance(); //obtem instancia da classe

    void InitClass(irr::IrrlichtDevice* device);
    void Draw();

    Scene* GetCurrentScene();
    void CreateNewScene();
    void AddScene(Scene* newScene);

    void LoadMainScene(std::string sceneFile);
    void LoadScenes(std::string projectPath);

};

#endif