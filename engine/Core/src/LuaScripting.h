#ifndef LUA_SCRIPTING_H
#define LUA_SCRIPTING_H

#include "../../ThirdParty/Lua542/include/lua.hpp"
#include <iostream>

class LuaScripting
{
private:
    lua_State* L;

public:
    LuaScripting();
    ~LuaScripting();

    bool ExecuteScript(const std::string& fileName);

    //registra uma funcao em Lua
    template<typename Function>
    void RegisterFunction(const std::string& functionName, Function function)
    {
        lua_pushcfunction(L, +[](lua_State* L) -> int {
            auto func = reinterpret_cast<Function>(lua_touserdata(L, lua_upvalueindex(1)));
            return func(L);
        });

        lua_pushlightuserdata(L, reinterpret_cast<void*>(function));
        lua_setglobal(L, functionName.c_str());
    }

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