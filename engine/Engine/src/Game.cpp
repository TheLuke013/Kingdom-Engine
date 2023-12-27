#include "Game.h"

//destrutor: libera recursos do jogo ao finalizar execucao
Game::~Game()
{
	device->drop();
}

//inicializa o jogo
bool Game::initGame(const char* windowTitle, int windowW, int windowH)
{
	//cria o dispositivo da engine com o driver de sofware
	device = irr::createDevice(irr::video::EDT_SOFTWARE,
		irr::core::dimension2d<irr::u32>(windowW, windowH),
		16, false, false, false, 0);

	//converte const char* windowTitle para wchar
	std::wstring wideWindowTitle(windowTitle, windowTitle + strlen(windowTitle));
	//define o titulo da janela
	device->setWindowCaption(wideWindowTitle.c_str());

	//verifica se o dispositivo foi criado com sucesso
	if (!device)
		return 1;

	//inicializa ponteiros para os componentes principais do dispositivo
	driver = device->getVideoDriver(); //driver de video
	scene_manager = device->getSceneManager(); //gerenciador de cena
	gui_env = device->getGUIEnvironment(); //ambiente de gui

	return true;
}

//inicializa o loop principal do jogo
void Game::startLoop()
{
	//enquanto o dispositivo estiver em execucao
	while (device->run())
	{
		//limpa o frame anterior e define a cor de fundo
		driver->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));

		scene_manager->drawAll(); //desenha todos os objetos na cena
		gui_env->drawAll(); //desenha todos os elementos da interface grafica (gui)

		//finaliza o desenho do frame
		driver->endScene();
	}
}
