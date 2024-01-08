#ifndef WINDOW_CLASS_H
#define WINDOW_CLASS_H

#include <GLFW/glfw3.h>

#include "Utils.h"
#include "SceneManager.h"

namespace KingdomEngine
{
    class Window
    {
    private:
        Color bgColor; //cor de fundo

        GLFWwindow* window; //instancia da janela glfw

    public:
        int originalWidth; //largura original da janela
        int originalHeight; //altura original da janela

        Window(const std::string& title, int width, int height);
        ~Window();

        void CloseWindow();
        void Update();

        //setters
        void SetFullScreen(bool value);
        void SetVSync(bool value);
        void SetTitle(const std::string& value);
        void SetSize(int width, int height);
        void SetBackgroundColor(int r, int g, int b, int a);
    };
}

#endif