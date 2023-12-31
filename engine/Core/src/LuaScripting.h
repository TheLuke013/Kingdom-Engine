#ifndef LUA_SCRIPTING_H
#define LUA_SCRIPTING_H

#include "../../ThirdParty/Lua542/include/lua.hpp"
#include "../../ThirdParty/LuaBridge/LuaBridge.h"
#include <iostream>

class LuaScripting
{
private:
    lua_State* L;

    //funcoes Lua
    static int SetVSync(lua_State* L);
    static int SetTitle(lua_State* L);
    static int SetBackgroundColor(lua_State* L);

    static int GetFPS(lua_State* L);

public:
    LuaScripting();
    ~LuaScripting();

    bool ExecuteScript(const std::string& fileName);
    void RegisterFunctionsInLua();

    //chama uma funcao no script Lua
    template<typename Dummy = void, typename... Args>
    void CallLuaFunction(const std::string& functionName, Args&&... args)
    {
        lua_getglobal(L, functionName.c_str());

        //empilha argumentos se tiver algum argumento
        if constexpr (sizeof...(args) > 0)
        {
            int dummy[] = {0, (Push(L, std::forward<Args>(args)), 0)...};
            (void)dummy; //evita warning de variaveis que nao estao sendo usadas
        }

        //verifica se foi possivel chamar a funcao
        if (lua_pcall(L, sizeof...(Args), 0, 0) != LUA_OK)
        {
            std::cerr << "Erro ao chama funcao: " << functionName << " Erro: " << lua_tostring(L, -1) << std::endl;
        }
    }

    //sobrecarga
    void CallLuaFunction(const std::string& functionName)
    {
        lua_getglobal(L, functionName.c_str());

        //verifica se foi possivel chamar a funcao
        if (lua_pcall(L, 0, 0, 0) != LUA_OK)
        {
            std::cerr << "Erro ao chama funcao: " << functionName << " Erro: " << lua_tostring(L, -1) << std::endl;
        }
    }

private:
    //empilha argumentos Lua
    template<typename T>
    void Push(lua_State* L, T&& arg)
    {
        lua_pushinteger(L, arg);
    }

};

#endif