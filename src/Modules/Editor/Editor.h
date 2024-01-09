#ifndef EDITOR_CLASS_H
#define EDITOR_CLASS_H

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <ImGuiFileDialog.h>

#include <Window.h>

namespace KingdomEngine
{
	class Editor
	{
	private:
		//cria o fundo da engine
		void CreateBackground();
		//cria as abas principais da engine
		void CreateTabs();
		//abre janela de dialog de arquivos
		std::string OpenFileDialog(const std::string& key);

	public:
		Window* editorWindow;
		bool isRunningEditor;

		Editor(); //construtor do editor
		~Editor(); //destrutor do editor

		//inicializa o editor e o imgui
		void StartEditorGUI();
		//finaliza o editor e o imgui
		void FinishEditor();
		//cria um novo frame imgui, opengl e glfw
		void CreateEditorGUI();
		//renderiza a janela e o imgui
		void Render();
	};
}

#endif
