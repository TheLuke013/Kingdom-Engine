#include "LuaScripting.h"
#include "Game.h"

//Window functions
int LuaScripting::SetVSync(lua_State* L)
{
    bool vsync = lua_toboolean(L, 1) != 0;
    Game::GetWindow()->SetVSync(vsync);
    return 0;
}

int LuaScripting::SetTitle(lua_State* L)
{
    std::string title = lua_tostring(L, 1);
    Game::GetWindow()->SetTitle(title);
    return 0;
}

int LuaScripting::SetBackgroundColor(lua_State* L)
{
    std::string bgColor = lua_tostring(L, 1);
    Game::GetWindow()->SetBackgroundColor(bgColor);
    return 0;
}

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

//registra as funcoes da api da engine em lua
void LuaScripting::RegisterFunctionsInLua()
{
    luabridge::getGlobalNamespace(L)
                                .addCFunction("window_set_vsync", &SetVSync)
                                .addCFunction("window_set_title", &SetTitle)
                                .addCFunction("window_set_bg_color", &SetBackgroundColor);
}
