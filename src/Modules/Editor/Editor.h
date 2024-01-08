#ifndef EDITOR_CLASS_H
#define EDITOR_CLASS_H

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <Window.h>

namespace KingdomEngine
{
	class Editor
	{
	public:
		Window* editorWindow;

		Editor(); //construtor do editor
		~Editor(); //destutor do editor

		//inicializa o editor e o imgui
		void StartEditorGUI();
		//finaliza o editor e o imgui
		void FinishEditor();
		void CreateEditorGUI();
		void Render();
	};
}

#endif
