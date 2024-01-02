#include "LuaScripting.h"
#include "../../Core/src/Nodes/Sprite.h"

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
    std::cout << "Executando script: " << fileName << std::endl;

    return true;
}

//registra as funcoes da api da engine em lua
void LuaScripting::RegisterFunctionsInLua()
{
    //classe Engine
    luabridge::getGlobalNamespace(L)
                            .beginClass<Engine>("Engine")
                                .addStaticFunction("window_set_vsync", &Engine::SetVSync)
                                .addStaticFunction("window_set_title", &Engine::SetTitle)
                                .addStaticFunction("window_set_bg_color", &Engine::SetBackgroundColor)
                                .addStaticFunction("get_fps", &Engine::GetFPS)
                                .addStaticFunction("quit_game", &Engine::QuitGame)
                                .addStaticFunction("change_scene", &Engine::ChangeScene)
                            .endClass();

    //classe Sprite
    luabridge::getGlobalNamespace(L)
                            .beginClass<Sprite>("Sprite")
                                .addConstructor<void (*)(const std::string&)>()
                                .addFunction("set_texture", &Sprite::SetTexture)
                                .addFunction("add_node", &Sprite::AddNode)
                            .endClass();
}
