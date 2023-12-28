#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <filesystem>
#include <Windows.h>

inline const wchar_t* ConvertStringToWChar(const std::string& string)
{
    static std::wstring wideString;

    int wideLength = MultiByteToWideChar(CP_UTF8, 0, string.c_str(), -1, nullptr, 0);
    wideString.resize(wideLength);
    MultiByteToWideChar(CP_UTF8, 0, string.c_str(), -1, &wideString[0], wideLength);
    
    return wideString.c_str();
}

//verifica se um arquivo pode ser aberto
inline bool OpenEngineFile(std::string filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        return false;
    }

    file.close();

    return true;
}

//le dados do arquivo e armazena valores a uma variavel map
inline void ReadEngineFile(std::string filePath, std::map<std::string, std::string> &dataReceiver)
{
    std::ifstream file(filePath);
    std::string line; //linhas de texto do arquivo
    while (std::getline(file, line))
    {
        //verifica se a linha nao esta vazia ou é comentario
        if (!line.empty() && line[0] != '#')
        {
            size_t equalsPos = line.find('='); //operador de atribuicao
            if (equalsPos != std::string::npos)
            {
                std::string key = line.substr(0, equalsPos);
                std::string value = line.substr(equalsPos + 1);

                dataReceiver[key] = value;
            }
        }
    }

    file.close();//fecha o arquivo
}

//obtem caminhos de arquivos com determinada extensao em um diretorio
inline std::vector<std::string> GetFilesWithExtension(const std::string& path, const std::string& extension)
{
    std::vector<std::string> files; //vector para armazenar os path dos arquivos

    for (const auto& entry : std::filesystem::recursive_directory_iterator(path))
    {
        if (entry.is_regular_file() && entry.path().extension() == extension)
        {
            files.push_back(entry.path().string());
        }
    }

    return files;
}

#endif