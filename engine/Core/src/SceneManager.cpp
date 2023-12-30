#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::~SceneManager() {}

//inicializa a classe
void SceneManager::InitClass(irr::IrrlichtDevice* device)
{
    sceneManager = device->getSceneManager();
}

//chama funcao para desenhar na tela
void SceneManager::Draw()
{
    //verifica se ha uma cena principal definida
    if (mainScene == nullptr)
    {
        std::cerr << "Nenhuma cena principal definida" << std::endl;
    }
    else
    {
        //verifica se ha uma cena atual definida
        if (currentScene)
        {
            currentScene->DrawScene();
        }
        else
        {
            std::cerr << "Nenhuma cena atual definida" << std::endl;
        }
    }
}

//obtem a cena atual
Scene* SceneManager::GetCurrentScene()
{
    return currentScene;
}

//obtem uma classe pelo nome da cena
Scene* SceneManager::GetScene(std::string sceneName)
{
    for (int i = 0; i < scenes.size(); i++)
    {
        if (scenes.at(i)->GetSceneName() == sceneName)
        {
            return scenes.at(i);
        }
    }

    return nullptr;
}

//cria uma nova cena e adiciona ao vector das cenas
void SceneManager::CreateNewScene(std::string sceneName)
{
    Scene* newScene = new Scene(sceneName);
    AddScene(newScene);
}

//adiciona uma nova cena ao vector de cenas
void SceneManager::AddScene(Scene* newScene)
{
    scenes.push_back(newScene);
}

//carrega a cena principal do jogo
bool SceneManager::LoadMainScene(std::string mainSceneName)
{
    if (mainSceneName == "")
    {
        return false;
    }

    mainScene = GetScene(mainSceneName);
    currentScene = mainScene;
    return true;
}

//carrega todas as cenas do diretorio do projeto
bool SceneManager::LoadScenes(std::string projectPath, std::map<std::string, std::string>& scriptNames)
{
    //vector que ira armazenar os caminhos dos arquivos de cena
    std::vector<std::string> sceneFiles = GetFilesWithExtension(projectPath, ".scene");
    //itera sobre todos os caminhos do vector
    for (const auto& sceneFile : sceneFiles)
    {
        //verifica se pode abrir o arquivo para leitura
        if (!OpenEngineFile(sceneFile))
        {
            return false;
        }
        //map que ira armazenar dados da cena carregada
        std::map<std::string, std::string> sceneData;
        ReadEngineFile(sceneFile, sceneData); //le dados e armazena valores

        //verifica se todas chaves essenciais estao presentes
	    const std::vector<std::string> requiredKeys = {
		    "Name"
	    }; //chaves essenciais do map

        for (const auto& key : requiredKeys)
        {
            if (sceneData.find(key) == sceneData.end())
            {
                std::cerr << "Erro: Chave ausente no arquivo de dados da cena: " << key << std::endl;
			    return false;
            }
        }
        //cria a cena
        CreateNewScene(sceneData.at("Name"));

        //verifica se a cena possui um script associado
        if (sceneData.find("Script") != sceneData.end())
        {
            std::string scriptPath; //armazena o path do script
            //procura o script que esta associado ao da cena
            for (const auto& scriptName : scriptNames)
            {
                if (scriptName.first == sceneData["Script"])
                {
                    //atribui o script a cena
                    scriptPath = scriptName.second;
                    GetScene(sceneData["Name"])->SetScript(scriptPath);
                    std::cout << "A cena " << sceneData.at("Name") << " Possui um script" << std::endl;
                    break; //para o loop ao encontrar o script associado
                }
            }
        }
        else
        {
            std::cout << "A cena " << sceneData.at("Name") << " Nao possui um script" << std::endl;
        }
    }

    return true;
}

void SceneManager::RunCurrentScene()
{
    Draw();
}