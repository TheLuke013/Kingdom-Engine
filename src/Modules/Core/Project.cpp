#include "Project.h"

//definicao dos elementos da estrutura que armazena o nome das secoes do arquivo de configuracao
const char* Project::ConfigSections::WindowSettings = "WindowSettings";
const char* Project::ConfigSections::GameSettings = "GameSettings";

//definicao dos elementos da estrutura que armazena os valores da secao WindowSettings
const char* Project::WindowKeys::Title = "Title";
const char* Project::WindowKeys::ScreenWidth = "ScreenWidth";
const char* Project::WindowKeys::ScreenHeight = "ScreenHeight";
const char* Project::WindowKeys::BackgroundColor = "BackgroundColor";
const char* Project::WindowKeys::FullScreen = "FullScreen";
const char* Project::WindowKeys::VSync = "VSync";
const char* Project::WindowKeys::FPSLimit = "FPSLimit";

//definicao dos elementos da estrutura que armazena os valores da secao GameSettings
const char* Project::GameKeys::DebugMode = "DebugMode";
const char* Project::GameKeys::MainScene = "MainScene";

//caminho do projeto
bool Project::LoadProjectFile(const char* filePath)
{
	std::filesystem::path projectFile = projectPath / filePath; //caminho para o arquivo de config. do projeto

	CSimpleIniA ini; //instancia INI
	SI_Error rc = ini.LoadFile(projectFile.c_str()); //carrega o arquivo de configuracoes do projeto
	//verifica se o arquivo foi carregado com sucesso
	if (rc < 0)
	{
		std::cerr << "Error: Unable to load project settings file" << std::endl;
		std::cerr << projectFile << std::endl;
		return false;
	}

	//obtem todas as secoes do arquivo de configuracao
	CSimpleIniA::TNamesDepend sections;
	ini.GetAllSections(sections);

	//obtem todas as chaves da secao WindowSettings
	CSimpleIniA::TNamesDepend windowKeys;
	ini.GetAllKeys("WindowSettings", windowKeys);
	LoadWindowSettings(ini);

	//obtem todas as chaves da secao GameSettings
	CSimpleIniA::TNamesDepend gameKeys;
	ini.GetAllKeys("GameSettings", gameKeys);
	LoadGameSettings(ini);

	return true;
}

//carrega os dados da janela e atribui os valores
void Project::LoadWindowSettings(CSimpleIniA& ini)
{
	projectSettings.Title = ini.GetValue(ConfigSections::WindowSettings, WindowKeys::Title);
	projectSettings.ScreenWidth = ini.GetLongValue(ConfigSections::WindowSettings, WindowKeys::ScreenWidth);
	projectSettings.ScreenHeight = ini.GetLongValue(ConfigSections::WindowSettings, WindowKeys::ScreenHeight);

	//carrega e atribui os valores de BackgroundColor
	const char* bgColorString = ini.GetValue(ConfigSections::WindowSettings, WindowKeys::BackgroundColor);
	sscanf_s(bgColorString, "(%d, %d, %d, %d)", &projectSettings.BackgroundColor[0], &projectSettings.BackgroundColor[1], &projectSettings.BackgroundColor[2], &projectSettings.BackgroundColor[3]);

	projectSettings.FullScreen = ini.GetBoolValue(ConfigSections::WindowSettings, WindowKeys::FullScreen);
	projectSettings.VSync = ini.GetBoolValue(ConfigSections::WindowSettings, WindowKeys::VSync);
	projectSettings.FPSLimit = static_cast<float>(ini.GetDoubleValue(ConfigSections::WindowSettings, WindowKeys::FPSLimit));
}

//carrega os dados do jogo e atribui os valores
void Project::LoadGameSettings(CSimpleIniA& ini)
{
	projectSettings.DebugMode = ini.GetBoolValue(ConfigSections::GameSettings, GameKeys::DebugMode);
	projectSettings.MainScene = ini.GetValue(ConfigSections::GameSettings, GameKeys::MainScene);
}
