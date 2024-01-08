#include "App.h"

//inicializa o nucleo da engine e o opengl
void KingdomEngine::App::InitEngine(int args_count, char* args_string[])
{
	InitOpenGL(); //inicializa o opengl
}

//inicializa o contexto opengl
void KingdomEngine::App::InitOpenGL()
{
	//verifica se foi possivel inicializar o glfw
	if (!glfwInit())
	{
		Finish();
	}

	//configura a versao do opengl para 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //define o perfil do opengl

	editorWindow = new Window("Kingdom Engine", 1024, 600); //cria a janela do editor da engine

	gladLoadGL(); //carrega o opengl
}

//inicia o loop principal de toda aplicacao
void KingdomEngine::App::Run()
{
	editorWindow->SetSize(800, 800);
	editorWindow->SetVSync(true);
	editorWindow->SetTitle("Novo titulo");
	editorWindow->SetBackgroundColor(100, 100, 10, 255);
	editorWindow->Update();
}

//finaliza a engine encerrando o programa
void KingdomEngine::App::Finish()
{
	glfwTerminate(); //finaliza o glfw
}

//cria a janela de debug da engine
void KingdomEngine::App::CreateDebugWindow()
{
	Window debugWindow("Debug", 800, 600);
	debugWindow.Update();
}
