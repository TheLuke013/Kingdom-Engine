#include "App.h"

//construtor da aplicacao(Kingdom Engine)
KingdomEngine::App::App() : mode(ExecMode::EDITOR), editor(nullptr) {}

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
	editor->StartEditorGUI();

	while (!glfwWindowShouldClose(editor->editorWindow->GetWindow()))
	{
		editor->CreateEditorGUI();
		editor->Render();
	}
}

//finaliza a engine encerrando o programa
void KingdomEngine::App::Finish()
{
	editor->FinishEditor(); //finaliza o editor da engine
	glfwTerminate(); //finaliza o glfw
}

//cria a janela de debug da engine
void KingdomEngine::App::CreateDebugWindow()
{
	Window debugWindow("Debug", 800, 600);
	while (!glfwWindowShouldClose(debugWindow.GetWindow()))
	{
		debugWindow.Render();
	}
}
