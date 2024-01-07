#include "Window.h"

//construtor
Window::Window(std::string title, int width, int height, int bgColor[4], bool fullscreen, bool vsync, float fpsLimit) : device(nullptr)
{
    params = irr::SIrrlichtCreationParameters();
    params.DriverType = irr::video::EDT_OPENGL; //tipo do driver
    SetSize(width, height); //resolucao da janela
    SetBackgroundColor(bgColor[0], bgColor[1], bgColor[2], bgColor[3]); //define a cor de fundo da janela
    SetFullScreen(fullscreen); //tela cheia
    SetVSync(vsync); //vsync
    params.EventReceiver = nullptr; //receptor de eventos
    FPSLimit = fpsLimit; //define o limite de fps

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

    SetTitle(title); //define o titulo da janela
    timer = device->getTimer(); //inicializa o timer
    lastFrameTime = device->getTimer()->getTime(); //inicializa o lastFrameTime
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

//inicializa o loop da janela e do jogo
void Window::Run(SceneManager* sceneManager)
{
    //verifica se device nao é nulo
    if (!device)
        return;

    timer->start(); //inicia o timer
    sceneManager->GetCurrentScene()->Start(); //executa a funcao start do script

    //enquanto o dispositivo estiver em execucao
    while (device->run())
    {
        //verifica se a janela do jogo esta ativa
        if (device->isWindowActive())
        {
            UpdateFPS(); //atualiza os quadros do jogo
            //limpa o frame anterior e define a cor de fundo
            device->getVideoDriver()->beginScene(true, true, irr::video::SColor(bgColor.red, bgColor.green, bgColor.blue, bgColor.alpha));

            sceneManager->RunCurrentScene();

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

//atualiza os quadros do jogo
void Window::UpdateFPS()
{
    //obtem tempo atual
    irr::u32 now = timer->getTime();

    //calcula o tempo decorrido desde o ultimo frame
    irr::u32 deltaTime = now - lastFrameTime;

    //calcula o tempo que cada frame deve levar para atingir o FPS limite
    float targetFrameTime = 1000.0f / FPSLimit;

    //dormir pelo tempo restante para atingir o FPS limite
    if (deltaTime < targetFrameTime)
    {
        float sleepTime = targetFrameTime - deltaTime;
        device->sleep(static_cast<irr::u32>(sleepTime));
    }

    //atualiza o ultimo tempo de frame
    lastFrameTime = timer->getTime();
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
void Window::SetBackgroundColor(int r, int g, int b, int a)
{
    bgColor.red = r;
    bgColor.green = g;
    bgColor.blue = b;
    bgColor.alpha = a;
}

//obtem o dispositivo
irr::IrrlichtDevice* Window::GetDevice() const
{
    return device;
}

//obtem o fps atual
float Window::GetFPS(SceneManager* sceneManager)
{
    //verifica se o dispositivo existe
    if (device && device->getTimer())
    {
        return static_cast<float>(device->getVideoDriver()->getFPS());
    }

    return 0.0f;
}
