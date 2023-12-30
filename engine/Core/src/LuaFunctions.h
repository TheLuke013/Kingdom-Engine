#ifndef LUA_FUNCTIONS_H
#define LUA_FUNCTIONS_H

#include "../../ThirdParty/Lua542/include/lua.hpp"
#include <iostream>
#include <string>

class LuaFunctions
{
public:
    static int Print(lua_State* L)
    {
        //obter o numero de argumentos
        int args_count = lua_gettop(L);

        //concatenar os argumentos em uma string
        std::string output;
        for (int i = 1; i <= args_count; ++i)
        {
            //concatenar o valor do argumento da string a saida
            output += lua_tostring(L, i);

            //adicionar espaco entre os argumentos
            if (i < args_count)
                output += " ";
        }

        std::cout << output << std::endl;

        return 0;
    }

    static int Prompt(lua_State* L)
    {
        //obtem a mensagem do prompt e imprime a mensagem
        const char* prompt = lua_tostring(L, 1);
        std::cout << prompt;

        //ler entrada do usuario
        std::string userInput;
        std::getline(std::cin, userInput);

        //empurra a entrada como uma string
        lua_pushstring(L, userInput.c_str());

        return 1;
    }
};

#endif