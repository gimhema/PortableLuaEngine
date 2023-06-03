#include"GameScriptFunction.h"
#include<iostream>

int GameScriptFunctionForLua::HelloLua(lua_State* LuaObj)
{
	std::cout << "Hello Lua This Function Called By CPP ! !" << std::endl;

	return 0;
}

int GameScriptFunctionForLua::SomeCPPFunction(lua_State* LuaObj)
{
	return 0;
}

int GameScriptFunctionForLua::SomeCPPFunction2(lua_State* LuaObj)
{
	return 0;
}

int GameScriptFunctionForLua::SomeCPPFunction3(lua_State* LuaObj)
{
	return 0;
}

int GameScriptFunctionForLua::SomeCPPFunction4(lua_State* LuaObj)
{
	return 0;
}
