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

	GLFWwindow* window = glfwCreateWindow(1024, 600, "Kingdom Engine", NULL, NULL); //cria a janela
	//verifica se a janela foi criada com sucesso
	if (window == NULL)
	{
		std::cout << "Failed to create window" << std::endl;
		Finish();
	}

	glfwMakeContextCurrent(window); //faz da janela o contexto atual

	//loop que processa a janela
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents(); //processa os eventos da janela
	}

	gladLoadGL(); //carrega o opengl
}

//inicia o loop principal de toda aplicacao
void KingdomEngine::App::Run()
{
}

//finaliza a engine encerrando o programa
void KingdomEngine::App::Finish()
{
	glfwTerminate(); //finaliza o glfw
}
