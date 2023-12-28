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
    sceneManager = device->getSceneManager();
}

//chama funcao para desenhar na tela
void SceneManager::Draw()
{
    

    sceneManager->drawAll();
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

//carrega a cena principal do jogo
void SceneManager::LoadMainScene(std::string sceneFile)
{
    std::string fileName = sceneFile + ".scene";
    std::cout << fileName << std::endl;
}

//carrega todas as cenas do diretorio do projeto
void SceneManager::LoadScenes(std::string projectPath)
{
    std::vector<std::string> sceneFiles = GetFilesWithExtension(projectPath, ".scene");
    for (int i = 0; i < sceneFiles.size(); i++)
    {
        std::cout << sceneFiles.at(i) << std::endl;
    }
}