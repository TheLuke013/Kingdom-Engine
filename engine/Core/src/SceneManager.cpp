#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::~SceneManager() {}

//retorna instancia global da classe
SceneManager* SceneManager::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new SceneManager();
    }

    return instance;
}

//inicializa a classe
void SceneManager::InitClass(irr::IrrlichtDevice* device)
{
    scene_manager = device->getSceneManager();
}

//chama funcao para desenhar na tela
void SceneManager::Draw()
{
    scene_manager->drawAll();
}

//cria uma nova cena e adiciona ao vector das cenas
void SceneManager::CreateNewScene()
{
    Scene* newScene = new Scene();
    AddScene(newScene);
}

//adiciona uma nova cena ao vector de cenas
void SceneManager::AddScene(Scene* newScene)
{
    scenes.push_back(newScene);
}