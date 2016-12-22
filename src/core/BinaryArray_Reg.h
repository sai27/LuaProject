#pragma once
#include "lua.hpp"

class BinaryArray_Reg
{
private:
	static int BinaryArray_New(lua_State* L);
	static int BinaryArray_Set(lua_State* L);
	static int BinaryArray_Get(lua_State* L);
	static int BinaryArray_Count(lua_State* L);

public:
	static void Reg(lua_State* L);
};