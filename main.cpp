// #include "GameScriptFunction.h"
#include "stdafx.h"

int AddFunction(lua_State* LuaObj)
{
	int lua_v1 = lua_tonumber(LuaObj, 1);
	int lua_v2 = lua_tonumber(LuaObj, 2);
	lua_pushnumber(LuaObj, lua_v1 + lua_v2);
	return 1;
}

int main()
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	lua_register(L, "AddFunctionCPP", AddFunction);
	luaL_loadfile(L, "HelloCPP.lua");

	int lua_error = lua_pcall(L, 0, 0, 0);
	if (lua_error) {
		std::cout << "Lua Error ! ! !" << std::endl;
	}

	lua_close(L);
	// _getch();

	return 0;
}
