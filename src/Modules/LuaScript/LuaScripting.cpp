#include "LuaScripting.h"
#include <Nodes/Sprite.h>

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
                                .addStaticFunction("WindowSetVSync", &Engine::SetVSync)
                                .addStaticFunction("WindowSetTitle", &Engine::SetTitle)
                                .addStaticFunction("WindowSetBgColor", &Engine::SetBackgroundColor)
                                .addStaticFunction("GetFPS", &Engine::GetFPS)
                                .addStaticFunction("QuitGame", &Engine::QuitGame)
                                .addStaticFunction("ChangeScene", &Engine::ChangeScene)
                            .endClass();

    //classe Sprite
    luabridge::getGlobalNamespace(L)
                            .beginClass<Sprite>("Sprite")
                                .addConstructor<void (*)(const std::string&)>()
                                .addFunction("SetTexture", &Sprite::SetTexture)
                                .addFunction("SetPosition", &Sprite::SetPosition)
                                .addFunction("SetRotation", &Sprite::SetRotation)
                                .addFunction("SetScale", &Sprite::SetScale)
                                .addFunction("AddNode", &Sprite::AddNode)
                                .addFunction("GetNodeType", &Sprite::GetNodeType)
                            .endClass();
}
