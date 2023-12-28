#include "Game.h"
#include <fstream>

std::string CONFIG_FILE_PATH; //caminho do arquivo de configuracao

std::map<std::string, std::string> configData;

//carrega os dados de configuracao do jogo
bool LoadGameConfig()
{
    std::ifstream configFile(CONFIG_FILE_PATH);

    //verifica se foi possivel abrir o arquivo
    if (!configFile.is_open())
    {
        return false;
    }

    std::string line; //linhas de texto do arquivo
    while (std::getline(configFile, line))
    {
        //verifica se a linha nao esta vazia ou é comentario
        if (!line.empty() && line[0] != '#')
        {
            size_t equalsPos = line.find('=');
            if (equalsPos != std::string::npos)
            {
                std::string key = line.substr(0, equalsPos);
                std::string value = line.substr(equalsPos + 1);

                configData[key] = value;
            }
        }
    }

    configFile.close();//fecha o arquivo

    return true;
}

int main(int argc, char *argv[])
{
    //verifica se ha argumento para o arquivo de dados do jogo
    if (argc == 2)
    {
        CONFIG_FILE_PATH = argv[1];
        if (!LoadGameConfig())
        {
            std::cerr << "Erro ao abrir arquivo de config. do projeto." << std::endl;
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
    if (!game.LoadData(configData))
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

	game.StartLoop(); //inicia o loop principal

    return 0;
}
