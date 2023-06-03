#include "LuaEngineCore.h"
#include "stdafx.h"


LuaScriptManager::LuaScriptManager()
{

}

LuaScriptManager::~LuaScriptManager()
{

}

void LuaScriptManager::Initialize()
{
	std::cout << "Lua Script Manager Initailize" << std::endl;

	InitializeLuaActioName(); // 이름을 추가해주고
	AddAllLuaAction(); // 실행하기위한 Lua 파일들을 추가해주고
	AddFunctionRequirements(); // 스크립트 실행에 필요한 함수들을 Add해준다.

	std::cout << "Lua Script Manager Initailize Completed . . ." << std::endl;
}

void LuaScriptManager::InitializeLuaActioName()
{
	std::cout << "Lua Script Manager InitializeLuaActioName" << std::endl;
	LuaActionNameVec.push_back("HelloCPP.lua");
	LuaActionNameVec.push_back("Some.lua");
	LuaActionNameVec.push_back("Some1.lua");
	LuaActionNameVec.push_back("Some2.lua");
	LuaActionNameVec.push_back("Some3.lua");
	LuaActionNameVec.push_back("Some4.lua");
	LuaActionNameVec.push_back("Some5.lua");
}

void LuaScriptManager::AddAllLuaAction()
{
	std::cout << "Lua Script Manager AddAllLuaAction" << std::endl;

	for (int i = 0; i < LuaActionNameVec.size(); i++)
	{
		lua_State* L = luaL_newstate();
		luaL_loadfile(L, LuaActionNameVec[i].c_str());
		LuaActionMap[LuaActionNameVec[i]] = L;
	}
}

void LuaScriptManager::AddFunctionRequirements()
{
	std::cout << "Lua Script Manager AddFunctionRequirements" << std::endl;
	// 스크립트 실행에 필요한 함수들을 Add해줍니다.

	std::unordered_map<std::string, lua_State*>::iterator iter;

	for (std::pair<std::string, lua_State*> elem : LuaActionMap)
	{
		lua_register(elem.second, "SomeCPPFunction", GameScriptFunctionForLua::SomeCPPFunction);
		lua_register(elem.second, "SomeCPPFunction2", GameScriptFunctionForLua::SomeCPPFunction2);
		lua_register(elem.second, "SomeCPPFunction3", GameScriptFunctionForLua::SomeCPPFunction3);
		lua_register(elem.second, "SomeCPPFunction4", GameScriptFunctionForLua::SomeCPPFunction4);
	}
}

void LuaScriptManager::CallLuaActionByName(std::string name)
{
	lua_State* L = GetLuaActionByName(name);
	int lua_error = lua_pcall(L, 0, 0, 0);

	if (lua_error) {
		std::cout << "Lua Error ! ! !" << std::endl;
	}

	lua_close(L);
}

lua_State* LuaScriptManager::GetLuaActionByName(std::string name)
{
	return LuaActionMap[name];
}

EventLuaScriptManager::EventLuaScriptManager()
{

}

EventLuaScriptManager::~EventLuaScriptManager()
{

}

void EventLuaScriptManager::AddFunctionRequirements()
{

}

MonsterAIScriptManager::MonsterAIScriptManager()
{

}

MonsterAIScriptManager::~MonsterAIScriptManager()
{

}

void MonsterAIScriptManager::AddFunctionRequirements()
{

}

RaidScriptManager::RaidScriptManager()
{

}

RaidScriptManager::~RaidScriptManager()
{

}

void RaidScriptManager::AddFunctionRequirements()
{

}
