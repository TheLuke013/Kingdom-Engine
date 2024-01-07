#include "Engine.h"
#include <Game.h>

//define vsync
int Engine::SetVSync(lua_State *L)
{
    bool vsync = lua_toboolean(L, 1) != 0;
    Game::GetWindow()->SetVSync(vsync);
    return 0;
}

//altera titulo da janela do jogo
int Engine::SetTitle(lua_State *L)
{
    std::string title = lua_tostring(L, 1);
    Game::GetWindow()->SetTitle(title);
    return 0;
}

//altera cor de fundo da janela
int Engine::SetBackgroundColor(lua_State *L)
{
    std::string bgColor = lua_tostring(L, 1);
    Game::GetWindow()->SetBackgroundColor(bgColor);
    return 0;
}

//obtem o numero do fps
int Engine::GetFPS(lua_State *L)
{
    float fps = Game::GetWindow()->GetFPS(Game::GetSceneManager());
    lua_pushnumber(L, static_cast<lua_Number>(fps));
    return 1;
}

//fecha o jogo
int Engine::QuitGame(lua_State *L)
{
    Game::QuitGame();
    return 0;
}

//altera a cena
int Engine::ChangeScene(lua_State *L)
{
    std::string sceneName = lua_tostring(L, 1);
    Game::GetSceneManager()->ChangeScene(sceneName);
    std::cout << "Mudar para cena: " << sceneName << std::endl;
    return 0;
}