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

//desenha a cena
void Scene::DrawScene()
{

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
    if (hasScript)
    {
        luaScript->CallLuaFunction<void>("Update");
    }
}