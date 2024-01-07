#include <filesystem>

#include "Game.h"
#include "Project.h"

std::filesystem::path projectPath; //caminho do diretorio do projeto

int main(int argc, char *argv[])
{
    //verifica se os argumentos passados nao sao diferente de 2
    if (argc != 2)
    {
        std::cerr << "Use:" << argv[0] << " <project_path>" << std::endl;
        return 1;
    }

    projectPath = argv[1]; //atribui o caminho do projeto passado pelos argumentos

    //verifica se o caminho passado nao é vazio
    if (projectPath.empty())
    {
        std::cerr << "Project path not specified" << std::endl;
        return 1;
    }

    Project project(projectPath); //instancia do projeto
    //verifica se o arquivo foi aberto e carregado com sucesso
    if (!project.LoadProjectFile("project.kep"))
    {
        return 1;
    }
    
    Game game; //instancia do jogo
	
    //carrega os dados do jogo
    if (!game.LoadData(project))
    {
        std::cerr << "Error: Unable to load game data" << std::endl;
        return 1;
    }

    //inicializa o jogo
    if (!game.InitGame(project))
    {
        std::cerr << "Error: Unable to initialize the game" << std::endl;
        return 1;
    }

	game.RunGame(); //inicia o loop principal

    return 0;
}
