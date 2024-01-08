#ifndef SCENE_H
#define SCENE_H

//#include <irrlicht.h>
#include <LuaScripting.h>
#include <string>
#include <vector>
#include "Nodes/Node.h"

class Scene
{
private:
    //irr::scene::ISceneNode* rootNode; //raiz da cena

    std::vector<Node*> nodes; //nodes filhos da cena

    std::string sceneName; //nome da cena
    std::string scriptPath; //caminho para o script da cena
    bool hasScript;

    LuaScripting* luaScript;

public:
    Scene(std::string sceneName);
    ~Scene();

    std::string GetSceneName();
    void SetScript(const std::string& scriptPath);

    //metodos essenciais da cena
    void Start();
    void Update();

    void AddNode(Node* node); //adiciona um node a cena
    void RemoveNode(std::string nodeName); //remove um node da cena
};

#endif