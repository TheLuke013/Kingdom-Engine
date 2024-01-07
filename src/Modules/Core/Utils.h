#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <filesystem>
#include <Windows.h>
#include <sstream>
#include <iostream>

//estrutura de cores RGBA
struct Color
{
    int red;
    int green;
    int blue;
    int alpha;
};

//converte string com dados de cor RBGA para um struct Color
inline Color ParseBackgroundColor(const std::string& colorString)
{
    Color backgroundColor;
    //remove os parenteses da string
    std::string trimmedString = colorString.substr(colorString.find("(") + 1,
        colorString.find(")") - colorString.find("(") - 1);

    std::istringstream colorStream(trimmedString);
    std::string colorPart;

    //parse para red
    std::getline(colorStream, colorPart, ',');
    backgroundColor.red = std::stoi(colorPart);

    //parse para green
    std::getline(colorStream, colorPart, ',');
    backgroundColor.green = std::stoi(colorPart);

    //parse para blue
    std::getline(colorStream, colorPart, ',');
    backgroundColor.blue = std::stoi(colorPart);

    //parse para alpha
    std::getline(colorStream, colorPart, ',');
    backgroundColor.alpha = std::stoi(colorPart);

    return backgroundColor;
}

//converte um dado do tipo std::string para wchar
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
inline void ReadEngineFile(std::string filePath, std::map<std::string, std::string>& dataReceiver)
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
inline std::vector<std::string> GetFilesWithExtension(const std::filesystem::path& path, const std::string& extension)
{
    std::vector<std::string> files; //vector para armazenar os path dos arquivos

    for (const auto& entry : std::filesystem::recursive_directory_iterator(path))
    {
        if (entry.is_regular_file() && entry.path().extension() == extension)
        {
            files.emplace_back(entry.path().string());
        }
    }

    return files;
}

inline std::string ExtractScriptNameFromPath(const std::string& path)
{
    //procura a ultima barra invertida no caminho
    size_t lastSlash = path.find_last_of("/\\");
    //extrai o nome do arquivo apos ultima barra invertida
    std::string fileName = (lastSlash != std::string::npos) ? path.substr(lastSlash + 1) : path;
    //procura o ponto/.nome_da_extensao do arquivo
    size_t lastDot = fileName.find_last_of(".");
    //extrai o nome do arquivo antes da extensao dele
    std::string scriptName = (lastDot != std::string::npos) ? fileName.substr(0, lastDot) : fileName;

    return scriptName;
}

#endif