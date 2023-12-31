#ifndef APP_CLASS_H
#define APP_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <thread>

#include <Window.h>
#include <Editor.h>

//namespace da KingdomEngine
namespace KingdomEngine
{
	//classe principal de toda a engine que ira iniciar o nucleo da engine podendo alternar do modo Editor a Debug
	class App
	{
	public:
		//construtor da aplicacao(Kingdom Engine)
		App();

		//inicializa o nucleo da engine e o opengl
		void InitEngine(int args_count, char* args_string[]);
		//inicializa o contexto opengl
		void InitOpenGL();
		//inicia o loop principal de toda aplicacao
		void Run();
		//finaliza a engine encerrando o programa
		void Finish();
		void CreateDebugTask();

	private:
		Editor* editor;

	};
}

#endif