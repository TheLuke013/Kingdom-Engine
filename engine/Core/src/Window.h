#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include "../../ThirdParty/Irrlicht/include/irrlicht.h"
#include "Utils.h"
#include "SceneManager.h"

class Window
{
private:
    Color bgColor; //cor de fundo

    irr::IrrlichtDevice* device;
    irr::SIrrlichtCreationParameters params; //criacao de parametros para o dispositivo

public:
    Window(std::string title, int width, int height);
    ~Window();

    irr::IrrlichtDevice* GetDevice() const;

    void Run(SceneManager* sceneManager);

    //setters
    void SetFullScreen(bool value);
    void SetVSync(bool value);
    void SetTitle(std::string value);
    void SetSize(int width, int height);
    void SetBackgroundColor(std::string RGBAColor);
};

#endif