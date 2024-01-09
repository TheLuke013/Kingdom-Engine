#include "App.h"

//construtor da aplicacao(Kingdom Engine)
KingdomEngine::App::App() : editor(nullptr) {}

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

	editor = new Editor(); //inicializa o editor da engine

	gladLoadGL(); //carrega o opengl
}

//inicia o loop principal de toda aplicacao
void KingdomEngine::App::Run()
{
	editor->StartEditorGUI(); //inicia o gui da engine
	std::thread debugThread;

	//loop principal de toda engine
	while (!glfwWindowShouldClose(editor->editorWindow->GetWindow()))
	{
		editor->CreateEditorGUI(); //cria os frames do gui da engine
		editor->Render(); //renderiza o editor

		//verifica se um projeto esta em execucao
		if (editor->isRunningProject)
		{
			//verifica se a thread de debug ja esta em execucao
			if (!debugThread.joinable())
			{
				//cria uma nova thread para a janela debug
				debugThread = std::thread(&KingdomEngine::App::CreateDebugTask, this);
				debugThread.detach(); ///faz a thread executar independentemente da thread principal
				editor->isRunningProject = false; //define como false para evitar outra chamada da thread
			}
		}

		//verifica se o editor nao esta em execucao
		if (!editor->isRunningEditor)
		{
			Finish(); //finaliza a engine
		}
	}
}

//finaliza a engine encerrando o programa
void KingdomEngine::App::Finish()
{
	delete editor; //deleta a instancia do editor
	glfwTerminate(); //finaliza o glfw
}

//cria a janela de debug da engine
void KingdomEngine::App::CreateDebugTask()
{
	//carrega os dados do jogo a partir do arquivo kep
	editor->project->LoadProjectFile("project.kep");

	//cria a janela de debug com as propriedades do projeto
	Window* debugWindow = new Window(
		editor->project->projectSettings.Title,
		editor->project->projectSettings.ScreenWidth,
		editor->project->projectSettings.ScreenHeight);

	while (!glfwWindowShouldClose(debugWindow->GetWindow()))
	{
		debugWindow->Render();
	}
	delete debugWindow;

	//define como false para parar a execucao do projeto
	editor->isRunningProject = false;
}
