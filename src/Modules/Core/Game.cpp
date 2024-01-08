#include "Game.h"
#include <Nodes/Sprite.h>

//inicializa membros estaticos
Window* Game::window = nullptr;
SceneManager* Game::sceneManager = nullptr;

Game::Game()
{
	sceneManager = SceneManager::GetInstance();
}

//destrutor: libera recursos do jogo ao finalizar execucao
Game::~Game()
{
	QuitGame();
}

//carrega os dados do jogo
bool Game::LoadData(Project& project)
{
	//registra todos scripts presentes no projeto
	if (!RegisterScripts(project))
	{
		std::cerr << "Error loading and registering scripts" << std::endl;
		return false;
	}

	return true;
}

//registra o caminho de todos scripts existentes no diretorio do projeto
bool Game::RegisterScripts(Project& project)
{
	//armazena caminho de todos arquivos com extensao .lua
    scriptPaths = GetFilesWithExtension(project.projectPath, ".lua");
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
bool Game::InitGame(Project& project)
{
	//cria a janela do jogo com suas propriedades
	window = new Window(
		project.projectSettings.Title,
		project.projectSettings.ScreenWidth,
		project.projectSettings.ScreenHeight,
		project.projectSettings.BackgroundColor,
		project.projectSettings.FullScreen,
		project.projectSettings.VSync,
		project.projectSettings.FPSLimit);

	//sceneManager->InitClass(window->GetDevice()); //inicializa o gerenciador de cenas

	//carrega todas as cenas
	if (!sceneManager->LoadScenes(project.projectPath.string(), scriptNames))
	{
		return false;
	}

	//define a cena principal
	if (!sceneManager->LoadMainScene(project.projectSettings.MainScene))
	{
		return false;
	}

	std::cout << "Current scene: " << sceneManager->GetCurrentScene()->GetSceneName() << std::endl;

	return true;
}

//inicializa o loop principal do jogo
void Game::RunGame()
{
	window->Run(sceneManager);
}

//obtem a janela principal
Window* Game::GetWindow()
{
	return window;
}

//obtem o gerenciador de cenas da engine
SceneManager* Game::GetSceneManager()
{
	return sceneManager;
}

//fecha o jogo
void Game::QuitGame()
{
	window->~Window();
}