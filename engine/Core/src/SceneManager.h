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

    //getters e setters
    Scene* GetCurrentScene();
    Scene* GetScene(std::string sceneName);

    void CreateNewScene(std::string sceneName);
    void AddScene(Scene* newScene);
    void LoadMainScene(std::string mainSceneName);
    bool LoadScenes(std::string projectPath);
    void RunCurrentScene();

};

#endif