#include "Window.h"

//construtor
KingdomEngine::Window::Window(const std::string& title, int width, int height)
{
    //define as cores de fundo
    bgColor = Color();
    bgColor.red = 255;
    bgColor.green = 255;
    bgColor.blue = 255;
    bgColor.alpha = 255;

    //define largura e altura original da janela
    originalWidth = width;
    originalHeight = height;

    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL); //cria a janela glfw
    //verifica se a janela foi criada com sucesso
    if (window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        CloseWindow();
    }

    glfwMakeContextCurrent(window); //faz da janela o contexto atual
}

//destrutor
KingdomEngine::Window::~Window()
{
    CloseWindow(); //chama metodo para fechar janela
}

//fecha a janela
void KingdomEngine::Window::CloseWindow()
{
    glfwDestroyWindow(window);
}

//inicializa o loop da janela e do jogo
void KingdomEngine::Window::Update()
{
    //loop que processa a janela
    while (!glfwWindowShouldClose(window))
    {
        //limpa a cor de fundo para uma nova cor
        glClearColor(bgColor.red / 255.0f, bgColor.green / 255.0f, bgColor.blue / 255.0f, bgColor.alpha / 255.0f);
        glClear(GL_COLOR_BUFFER_BIT); //limpa o buffer cores
        glfwSwapBuffers(window);
        glfwPollEvents(); //processa os eventos da janela
    }
}

//altera o fullscreen da janela
void KingdomEngine::Window::SetFullScreen(bool value)
{
    if (value)
    {
        //obtem o monitor primario
        GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
        //obtem a resolucao do monitor
        const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
        glfwSetWindowMonitor(window, primaryMonitor, 0, 0, mode->width, mode->height, mode->refreshRate);
    }
    else
    {
        glfwSetWindowMonitor(window, nullptr, 0, 0, originalWidth, originalHeight, 0);
    }
}

//altera o vsync da janela
void KingdomEngine::Window::SetVSync(bool value)
{
    glfwSwapInterval(value);
}

//altera o titulo da janela
void KingdomEngine::Window::SetTitle(const std::string& value)
{
    glfwSetWindowTitle(window, value.c_str());
}

//altera o tamanho da janela
void KingdomEngine::Window::SetSize(int width, int height)
{
    glfwSetWindowSize(window, width, height);
}

//altera a cor de fundo da janela
void KingdomEngine::Window::SetBackgroundColor(int r, int g, int b, int a)
{
    bgColor.red = r;
    bgColor.green = g;
    bgColor.blue = b;
    bgColor.alpha = a;
}
