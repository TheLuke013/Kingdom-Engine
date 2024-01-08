#include "Editor.h"

//construtor do editor
KingdomEngine::Editor::Editor()
{
    editorWindow = new Window("Kingdom Engine", 1024, 600); //cria a janela do editor da engine
}

//destutor do editor
KingdomEngine::Editor::~Editor()
{
    FinishEditor();
}

//inicializa o editor e o imgui
void KingdomEngine::Editor::StartEditorGUI()
{
    //configuracao do imgui
    ImGui::CreateContext(); //define o contexto imgui
    ImGui::StyleColorsClassic(); //define o estilo de cor classico
    ImGui_ImplGlfw_InitForOpenGL(editorWindow->GetWindow(), true); //inicializa o backend para glfw
    ImGui_ImplOpenGL3_Init(); //inicializa o backend para opengl3
    //ativa navegacao por teclado e gamepad
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
}

//finaliza o editor e o imgui
void KingdomEngine::Editor::FinishEditor()
{
    //libera memoria do imgui e destroi o contexto
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void KingdomEngine::Editor::CreateEditorGUI()
{
    //inicia um novo frame imgui
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::ShowDemoWindow();
}

void KingdomEngine::Editor::Render()
{
    glfwPollEvents();

    ImGui::Render();

    editorWindow->RenderBGColor();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(editorWindow->GetWindow());
}
