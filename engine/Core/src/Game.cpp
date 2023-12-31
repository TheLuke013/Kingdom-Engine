#include "Game.h"

Window* Game::window = nullptr;

Game::Game()
{
	sceneManager = SceneManager::GetInstance();
}

//destrutor: libera recursos do jogo ao finalizar execucao
Game::~Game()
{
	window->~Window();
}

//carrega os dados do jogo
bool Game::LoadData(const std::map<std::string, std::string> &gameConfigData, std::string projectPath)
{
	this->projectPath = projectPath;

	//chaves essenciais do map
	const std::vector<std::string> requiredKeys = {
		"Title", "ScreenWidth", "ScreenHeight", "MainScene",
        "BackgroundColor", "FullScreen", "VSync", "FPSLimit", "DebugMode"
	};

	//itera sobre os requiredKeys e atribui os valores das chaves ao gameConfigData da classe
	for (const auto& key : requiredKeys)
	{
		if (gameConfigData.find(key) == gameConfigData.end())
		{
			std::cerr << "Erro: Chave ausente no arquivo de configuração: " << key << std::endl;
			return false;
		}
		else
		{
			this->gameConfigData[key] = gameConfigData.at(key);
		}
	}

	mainSceneName = this->gameConfigData["MainScene"]; //define o nome da cena principal

	//registra todos scripts presentes no projeto
	if (!RegisterScripts())
	{
		std::cerr << "Erro ao carregar e registrar os scripts" << std::endl;
		return false;
	}

	return true;
}

//registra o caminho de todos scripts existentes no diretorio do projeto
bool Game::RegisterScripts()
{
	//armazena caminho de todos arquivos com extensao .lua
    scriptPaths = GetFilesWithExtension(projectPath, ".lua");
    //itera sobre todos os caminhos do vector
    for (const auto& scriptPath : scriptPaths)
    {
        //verifica se o arquivo é valido para ser aberto
        if (!OpenEngineFile(scriptPath))
        {
            return false;
        }
		scriptNames[ExtractScriptNameFromPath(scriptPath)] = scriptPath;
    }

    return true;
}

//inicializa o jogo
bool Game::InitGame()
{
	//cria o dispositivo da engine com o driver de sofware
	window = new Window(
		gameConfigData["Title"],
		std::stoi(gameConfigData["ScreenWidth"]),
		std::stoi(gameConfigData["ScreenHeight"]),
		gameConfigData["BackgroundColor"],
		std::stoi(gameConfigData["FullScreen"]),
		std::stoi(gameConfigData["VSync"]));

	//inicializa ponteiros para os componentes principais do dispositivo
	sceneManager->InitClass(window->GetDevice()); //gerenciador de cenas

	//carrega todas as cenas
	if (!sceneManager->LoadScenes(projectPath, scriptNames))
	{
		return false;
	}

	//define a cena principal
	if (!sceneManager->LoadMainScene(mainSceneName))
	{
		return false;
	}

	return true;
}

//inicializa o loop principal do jogo
void Game::RunGame()
{
	window->Run(sceneManager);
}

Window* Game::GetWindow()
{
	return window;
}