#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

//#include <irrlicht.h>
#include "Utils.h"
#include "SceneManager.h"

class Window
{
private:
    Color bgColor; //cor de fundo

    //irr::IrrlichtDevice* device; //dispositivo da engine
    //irr::SIrrlichtCreationParameters params; //criacao de parametros para o dispositivo
    //irr::ITimer* timer; //timer do jogo
    //irr::u32 lastFrameTime; //armazena o tempo do ultimo frame

    float FPSLimit;

public:
    Window(std::string title, int width, int height, int bgColor[4], bool fullscreen, bool vsync, float fpsLimit);
    ~Window();

    void Run(SceneManager* sceneManager);
    void UpdateFPS();

    //setters
    void SetFullScreen(bool value);
    void SetVSync(bool value);
    void SetTitle(std::string value);
    void SetSize(int width, int height);
    void SetBackgroundColor(int r, int g, int b, int a);

    //getters
    //irr::IrrlichtDevice* GetDevice() const;
    float GetFPS(SceneManager* sceneManager);
};

#endif