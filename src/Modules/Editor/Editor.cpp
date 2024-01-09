#include "Editor.h"

//cria o fundo da engine
void KingdomEngine::Editor::CreateBackground()
{
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings;


    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);

    bool pOpen = true;
    if (ImGui::Begin("Kingdom Engine", &pOpen, flags))
    {
        CreateTabs();
    }
    ImGui::End();
}

//cria as abas principais da engine
void KingdomEngine::Editor::CreateTabs()
{
    //colecao das abas da engine
    if (ImGui::BeginTabBar("##MainTabBar"))
    {
        //aba Home
        if (ImGui::BeginTabItem("Home"))
        {
            //conteudo
            ImGui::EndTabItem();
        }

        //aba Editor
        if (ImGui::BeginTabItem("Editor"))
        {
            //conteudo

            //botao que ao clicar abre dialogo de arquivos para escolher o projeto que quer iniciar
            if (ImGui::Button("Run a project"))
            {
                IGFD::FileDialog::Instance()->OpenDialog("OpenProjectDialog", "Open a Project", nullptr, "");
            }

            std::string fileSelected = OpenFileDialog("OpenProjectDialog");
            //verifica se um arquivo foi selecionado e executa o projeto
            if (!fileSelected.empty())
            {
                std::cout << fileSelected << std::endl;
                project = new Project(fileSelected);
                isRunningProject = true;
                fileSelected = "";
            }

            ImGui::EndTabItem();
        }

        //aba Script
        if (ImGui::BeginTabItem("Script"))
        {
            //conteudo
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }
}

//abre janela de dialog de arquivos
std::string KingdomEngine::Editor::OpenFileDialog(const std::string& key)
{
    std::string selectedFilePath;

    //dialog de arquivo
    if (IGFD::FileDialog::Instance()->Display(key, NULL, ImVec2(3, 3)))
    {
        if (IGFD::FileDialog::Instance()->IsOk())
        {
            selectedFilePath = IGFD::FileDialog::Instance()->GetCurrentPath();
        }

        IGFD::FileDialog::Instance()->Close();
    }

    return selectedFilePath;
}

//construtor do editor
KingdomEngine::Editor::Editor()
{
    editorWindow = new Window("Kingdom Engine", 1024, 600); //cria a janela do editor da engine
    project = nullptr; //inicializa project como nullptr como padrao
    isRunningEditor = true; //define como true para nao encerrar o programa
    //define como false como padrao, pois por padrao a engine nao ira iniciar com um projeto em execucao
    isRunningProject = false;
}

//destrutor do editor
KingdomEngine::Editor::~Editor()
{
    FinishEditor();
}

//inicializa o editor e o imgui
void KingdomEngine::Editor::StartEditorGUI()
{
    //configuracao do imgui
    ImGui::CreateContext(); //define o contexto imgui
    ImGui::StyleColorsDark(); //define o estilo de cor dark
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

//cria um novo frame imgui, opengl e glfw
void KingdomEngine::Editor::CreateEditorGUI()
{
    //inicia um novo frame imgui
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    CreateBackground();
}

//renderiza a janela e o imgui
void KingdomEngine::Editor::Render()
{
    glfwPollEvents();

    ImGui::Render();

    editorWindow->RenderBGColor();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(editorWindow->GetWindow());
}
