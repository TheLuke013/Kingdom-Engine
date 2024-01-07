#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <filesystem>
#include <SimpleIni.h>

class Project
{
private:
	//estrutura que contem dados da janela e do jogo
	struct Settings
	{
		//membros
		std::string Title;
		int ScreenWidth;
		int ScreenHeight;
		int BackgroundColor[4];
		bool FullScreen;
		bool VSync;
		float FPSLimit;
		bool DebugMode;
		std::string MainScene;

		//construtor
		Settings() :
			Title("Empty Title"),
			ScreenWidth(800),
			ScreenHeight(600),
			BackgroundColor{ 255, 0, 0, 0 },
			FullScreen(false),
			VSync(false),
			FPSLimit(60.0f),
			DebugMode(false),
			MainScene("Empty Scene") { }
	};

	//estrutura que armazena o nome das secoes do arquivo de configuracao
	struct ConfigSections
	{
		static const char* WindowSettings;
		static const char* GameSettings;
	};

	//estrutura que armazena os valores da secao WindowSettings
	struct WindowKeys
	{
		static const char* Title;
		static const char* ScreenWidth;
		static const char* ScreenHeight;
		static const char* BackgroundColor;
		static const char* FullScreen;
		static const char* VSync;
		static const char* FPSLimit;
	};

	//estrutura que armazena os valores da secao GameSettings
	struct GameKeys
	{
		static const char* DebugMode;
		static const char* MainScene;
	};

public:
	//construtor
	Project::Project(std::filesystem::path projectPath) : projectPath(projectPath)
	{
		projectSettings = Settings();
	}
	std::filesystem::path projectPath; //caminho do projeto

	Settings projectSettings;

	bool LoadProjectFile(const char* filePath); //carrega todos os dados de um projeto
	void LoadWindowSettings(CSimpleIniA& ini); //carrega os dados da janela e atribui os valores
	void LoadGameSettings(CSimpleIniA& ini); //carrega os dados do jogo e atribui os valores

};

#endif