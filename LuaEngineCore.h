#pragma once
#include "stdafx.h"


class LuaScriptManager 
{
public:
	LuaScriptManager();
	~LuaScriptManager();

public:
	std::vector<std::string> LuaActionNameVec; 
	std::unordered_map<std::string, lua_State*> LuaActionMap;
	

public:
	virtual lua_State* GetLuaActionByName(std::string name);
	virtual void Initialize();
	virtual void InitializeLuaActioName();
	virtual void AddFunctionRequirements(); // 스크립트 실행에 필요한 함수들을 Add해줍니다.
	// Non Programmer들은 AddFunctionRequirements에서 Add된 CPP함수들만 사용할 수 있습니다.
	// Requirements를 공유하는 루아 액션(파일)들을 로드합니다.
	// Non Programmer들이 작업한 내용이 갱신됩니다.
	virtual void AddAllLuaAction();
	virtual void CallLuaActionByName(std::string name);
};

class EventLuaScriptManager : public LuaScriptManager
{
public:
	EventLuaScriptManager();
	~EventLuaScriptManager();

public:
	void AddFunctionRequirements();
};

class MonsterAIScriptManager : public LuaScriptManager
{
public:
	MonsterAIScriptManager();
	~MonsterAIScriptManager();

public:
	void AddFunctionRequirements();
};

class RaidScriptManager : public LuaScriptManager
{
public:
	RaidScriptManager();
	~RaidScriptManager();

public:
	void AddFunctionRequirements();
};

