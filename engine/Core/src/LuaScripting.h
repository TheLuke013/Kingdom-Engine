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

};

#endif