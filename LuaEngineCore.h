#pragma once
#include <string>


class LuaEngineCore 
{
public:
	// Constructor & Deconstructor
	LuaEngineCore();
	~LuaEngineCore();

public:
	// Property

public:
	// Method
	void Initailize();
	void LoadLuaScript(std::string filePath);
	void LuaExecution();
	

};