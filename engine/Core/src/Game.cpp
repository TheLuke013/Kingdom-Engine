#include "Game.h"

Game::Game()
{
	sceneManager = SceneManager::GetInstance();
}

//destrutor: libera recursos do jogo ao finalizar execucao
Game::~Game()
{
	device->drop();
}

//carrega os dados do jogo
bool Game::LoadData(const std::map<std::string, std::string> &gameConfigData, std::string projectPath)
{
	this->projectPath = projectPath;

	if (gameConfigData.find("Title") == gameConfigData.end() &&
		gameConfigData.find("ScreenWidth") == gameConfigData.end() &&
		gameConfigData.find("ScreenHeight") == gameConfigData.end() &&
		gameConfigData.find("MainScene") == gameConfigData.end())
	{
		std::cerr << "Erro: Chaves ausentes no arquivo de configuracao" << std::endl;
		return false;
	}

	//carrega os dados do jogo a partir do map
	windowTitle = gameConfigData.at("Title");
	windowWidth = std::stoi(gameConfigData.at("ScreenWidth"));
	windowHeight = std::stoi(gameConfigData.at("ScreenHeight"));
	mainSceneName = gameConfigData.at("MainScene");

	return true;
}

//inicializa o jogo
bool Game::InitGame()
{
	//cria o dispositivo da engine com o driver de sofware
	device = irr::createDevice(irr::video::EDT_SOFTWARE,
		irr::core::dimension2d<irr::u32>(windowWidth, windowHeight),
		16, false, false, false, 0);

	//verifica se o dispositivo foi criado com sucesso
	if (!device)
		return 1;

	//define o titulo da janela
	device->setWindowCaption(ConvertStringToWChar(windowTitle));

	//inicializa ponteiros para os componentes principais do dispositivo
	driver = device->getVideoDriver(); //driver de video
	guiEnv = device->getGUIEnvironment(); //ambiente de gui
	sceneManager->InitClass(device); //gerenciador de cenas

	//carrega todas as cenas
	if (!sceneManager->LoadScenes(projectPath))
	{
		return false;
	}

	//define a cena principal
	sceneManager->LoadMainScene(mainSceneName);

	return true;
}

//inicializa o loop principal do jogo
void Game::StartLoop()
{
	//enquanto o dispositivo estiver em execucao
	while (device->run())
	{
		//limpa o frame anterior e define a cor de fundo
		driver->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));

		sceneManager->RunCurrentScene(); //desenha todos os objetos da cena atual
		guiEnv->drawAll(); //desenha todos os elementos da interface grafica (gui)

		//finaliza o desenho do frame
		driver->endScene();
	}
}