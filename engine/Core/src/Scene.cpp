#include "Scene.h"

//construtor da classe
Scene::Scene(std::string sceneName) : sceneName(sceneName)
{
    luaScript = new LuaScripting();
    luaScript->RegisterFunctionsInLua();
    hasScript = false;
}

//destrutor da classe
Scene::~Scene()
{
    delete luaScript;
}

//retorna o nome da cena
std::string Scene::GetSceneName()
{
    return sceneName;
}

//define o script associado a cena
void Scene::SetScript(const std::string& scriptPath)
{
    this->scriptPath = scriptPath;
    luaScript->ExecuteScript(scriptPath);
    hasScript = true;
}

//metodo que sera chamado ao iniciar o jogo
void Scene::Start()
{
    if (hasScript)
    {
        luaScript->CallLuaFunction<void>("Start");
    }
}

//metodo que sera chamado durante o loop do jogo
void Scene::Update()
{
    //se a cena tiver um script entao o execute
    if (hasScript)
    {
        luaScript->CallLuaFunction<void>("Update");
    }

    //itera sobre todos os nodes da cena e chama o metodo Render de cada um
    for (auto node : nodes)
    {
        node->Render();
    }
}

//adiciona um node a cena
void Scene::AddNode(Node* node)
{
    nodes.push_back(node);
}

//remove um node da cena
void Scene::RemoveNode(std::string nodeName)
{
    for (auto node = nodes.begin(); node != nodes.end(); ++node)
    {
        if ((*node)->GetNodeName() == nodeName)
        {
            nodes.erase(node);
            break;
        }
    }
}