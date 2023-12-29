#include "LuaScripting.h"

//construtor
LuaScripting::LuaScripting() : L(nullptr)
{
    L = luaL_newstate();
    //abre bibliotecas padrao do Lua
    luaL_openlibs(L);
}

//destrutor
LuaScripting::~LuaScripting()
{
    //fecha o Lua e libera os recursos associados
    lua_close(L);
}

//executa um arquivo de script Lua
bool LuaScripting::ExecuteScript(const std::string& fileName)
{
    //verifica se o script foi executado com sucesso
    if (luaL_loadfile(L, fileName.c_str()) || lua_pcall(L, 0, 0, 0))
    {
        std::cerr << "Erro ao executar o Lua Script:" << lua_tostring(L, -1) << std::endl;
        return false;
    }

    return true;
}
