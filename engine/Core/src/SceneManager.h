#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "../../ThirdParty/Irrlicht/include/irrlicht.h"
#include "Scene.h"
#include <vector>

class SceneManager
{
private:
    static SceneManager* instance; //instancia da classe

    irr::scene::ISceneManager* scene_manager;
    std::vector<Scene*> scenes; //armazena ponteiros para as cenas
    Scene* currentScene;

public:
    ~SceneManager();

    static SceneManager* GetInstance(); //obtem instancia da classe

    void InitClass(irr::IrrlichtDevice* device);
    void Draw();

    Scene* GetCurrentScene();
    void CreateNewScene();
    void AddScene(Scene* newScene);
};

#endif