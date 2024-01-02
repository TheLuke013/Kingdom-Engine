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

    //retorna instancia global da classe
    static SceneManager* GetInstance()
    {
        if (instance == nullptr)
        {
            instance = new SceneManager();
        }

        return instance;
    }

    void InitClass(irr::IrrlichtDevice* device);

    //getters e setters
    Scene* GetCurrentScene();
    Scene* GetScene(std::string sceneName);
    irr::scene::ISceneManager* GetSceneManager();

    void CreateNewScene(std::string sceneName);
    void AddScene(Scene* newScene);
    bool LoadMainScene(std::string mainSceneName);
    bool LoadScenes(std::string projectPath, std::map<std::string, std::string>& scriptNames);
    void RunCurrentScene();
    bool ChangeScene(std::string sceneName);

};

#endif