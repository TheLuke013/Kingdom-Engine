#include "Window.h"

//construtor
Window::Window(std::string title, int width, int height, std::string bgColor, bool fullscreen, bool vsync) : device(nullptr)
{
    params = irr::SIrrlichtCreationParameters();
    params.DriverType = irr::video::EDT_SOFTWARE; //tipo do driver
    SetSize(width, height); //resolucao da janela
    SetBackgroundColor(bgColor); //define a cor de fundo da janela
    SetFullScreen(fullscreen); //tela cheia
    SetVSync(vsync); //vsync
    params.EventReceiver = nullptr; //receptor de eventos

    //cria o dispositivo da engine com params de exemplo
    device = irr::createDeviceEx(params);
    if (!device)
    {
        throw std::runtime_error("Erro: Falha ao criar o dispositivo da engine");
    }

    //verifica se a janela esta em fullscreen e maximiza a janela
    if (device->isFullscreen())
    {
        device->maximizeWindow();
    }

    //define o titulo da janela
    SetTitle(title);
}

//destrutor
Window::~Window()
{
    //verifica se device nao é nulo
    if (device)
    {
        //fecha o dispositivo antes de liberar os recursos
        device->closeDevice();
        //libera o dispositivo
        device->drop();
    }
}

//obtem o dispositivo
irr::IrrlichtDevice* Window::GetDevice() const
{
    return device;
}

//inicializa o loop da janela e do jogo
void Window::Run(SceneManager* sceneManager)
{
    //verifica se device nao é nulo
    if (!device)
        return;
    
    sceneManager->GetCurrentScene()->Start(); //executa a funcao start do script

    //enquanto o dispositivo estiver em execucao
    while (device->run())
    {
        //verifica se a janela do jogo esta ativa
        if (device->isWindowActive())
        {
            //limpa o frame anterior e define a cor de fundo
            device->getVideoDriver()->beginScene(true, true, irr::video::SColor(bgColor.red, bgColor.green, bgColor.blue, bgColor.alpha));

            sceneManager->RunCurrentScene();
            sceneManager->GetCurrentScene()->Update();

            //finaliza o desenho do frame
            device->getVideoDriver()->endScene();
        }
        else
        {
            //evita que o loop ocupado consuma todos os ciclos da CPU quando a janela não estiver ativa
            device->yield();
        }
    }
}

//define/redefine o fullscreen da janela
void Window::SetFullScreen(bool value)
{
    params.Fullscreen = value;

    //verifica se o dispositivo existe
    if (device)
    {
        if (value)
        {
            device->maximizeWindow();
        }
        else
        {
            device->minimizeWindow();
        }
    }
}

//define/redefine o vsync da janela
void Window::SetVSync(bool value)
{
    params.Vsync = value;
}

//define/redefine o titulo da janela
void Window::SetTitle(std::string value)
{
    device->setWindowCaption(ConvertStringToWChar(value));
}

//define/redefine o tamanho da janela
void Window::SetSize(int width, int height)
{
    if (width > 0 && height > 0)
    {
        params.WindowSize = irr::core::dimension2d<irr::u32>(width, height);
    }
    else
    {
        std::cerr << "Erro: Dimensoes invalidas para a janela" << std::endl;
    }
}

//define/redefine a cor de fundo da janela
void Window::SetBackgroundColor(std::string RGBAColor)
{
    bgColor = ParseBackgroundColor(RGBAColor);
}