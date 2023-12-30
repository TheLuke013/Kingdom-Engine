#include "Game.h"

std::string projectPath; //caminho do diretorio do projeto

std::map<std::string, std::string> configData;

//carrega os dados de configuracao do jogo
bool LoadGameConfig()
{
    //constroi o caminho para o arquivo project.kep
    std::string projectFile = projectPath + "project.kep";

    //verifica se foi possivel abrir o arquivo
    if (!OpenEngineFile(projectFile))
    {
        return 1;
    }

    //le o arquivo e armazena os dados do projeto
    ReadEngineFile(projectFile, configData);
    
    return true;
}

int main(int argc, char *argv[])
{
    //verifica se ha argumento para o arquivo de dados do jogo
    if (argc == 2)
    {
        projectPath = argv[1];
        if (projectPath.empty())
        {
            std::cerr << "Caminho do projeto nao especificado" << std::endl;
            return 1;
        }

        if (!LoadGameConfig())
        {
            std::cerr << "Erro ao abrir arquivo de config. do projeto" << std::endl;
            return 1;
        }
    }
    else
    {
        std::cerr << "Uso: " << argv[0] << " <caminho_do_arquivo_de_configuracao>" << std::endl;
        return 1;
    }
    
    Game game; //instancia do jogo
	
    //carrega os dados do jogo
    if (!game.LoadData(configData, projectPath))
    {
        std::cerr << "Erro ao carregar os dados do jogo" << std::endl;
        return 1;
    }

    //inicializa o jogo
    if (!game.InitGame())
    {
        std::cerr << "Erro ao inicializar o jogo" << std::endl;
        return 1;
    }

	game.RunGame(); //inicia o loop principal

    return 0;
}
