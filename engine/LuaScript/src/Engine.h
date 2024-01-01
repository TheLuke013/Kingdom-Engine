#ifndef ENGINE_H
#define ENGINE_H

#include "../../ThirdParty/Lua542/include/lua.hpp"

class Engine
{
public:
    static int SetVSync(lua_State *L);
    static int SetTitle(lua_State *L);
    static int SetBackgroundColor(lua_State *L);
    static int GetFPS(lua_State *L);
    static int QuitGame(lua_State *L);
    static int ChangeScene(lua_State *L);

};

#endif