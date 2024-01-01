#ifndef SCENE_H
#define SCENE_H

#include "../../ThirdParty/Irrlicht/include/irrlicht.h"
#include <string>
#include "../../LuaScript/src/LuaScripting.h"

class Scene
{
private:
    irr::scene::ISceneNode* rootNode;

    std::string sceneName; //nome da cena
    std::string scriptPath; //caminho para o script da cena
    bool hasScript;

    LuaScripting* luaScript;

public:
    Scene(std::string sceneName);
    ~Scene();

    std::string GetSceneName();
    void SetScript(const std::string& scriptPath);
    void DrawScene();

    //metodos essenciais da cena
    void Start();
    void Update();
};

#endif