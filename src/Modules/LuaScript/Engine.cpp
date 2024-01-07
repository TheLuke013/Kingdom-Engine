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

//altera a cor de fundo da janela
int Engine::SetBackgroundColor(lua_State* L)
{
    // Verifica se o argumento é uma tabela
    if (!lua_istable(L, 1))
    {
        return luaL_error(L, "O argumento deve ser uma tabela");
    }

    //tamanho da tabela
    int n = luaL_len(L, 1);

    //verifica se o tamanho da tabela é 4
    if (n != 4)
    {
        return luaL_error(L, "A tabela deve ter 4 elementos");
    }

    //extrai os elementos da tabela e os armazena no array bgColor
    int bgColor[4];
    for (int i = 0; i < 4; ++i)
    {
        lua_rawgeti(L, 1, i + 1);  //obtem o elemento na posição i+1
        bgColor[i] = static_cast<int>(lua_tointeger(L, -1));  //converte para int
        lua_pop(L, 1);  //remove o elemento da pilha
    }

    //define a cor de fundo da janela
    Game::GetWindow()->SetBackgroundColor(bgColor[0], bgColor[1], bgColor[2], bgColor[3]);

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