#include "typedef.h"
#include "lua.hpp"
#include "BinaryArray.h"
#include "BinaryArray_Reg.h"
#include "Debug.h"

int BinaryArray_Reg::BinaryArray_New(lua_State* L)
{
	int size = luaL_checkint(L,1);
	luaL_argcheck(L, size>0, 1, "invalid size");

	BinaryArray* binaryArray = (BinaryArray*)lua_newuserdata(L, sizeof(BinaryArray));
	binaryArray->Init(size);
	luaL_getmetatable(L, "BinaryArrayMetaTable");
	// Debug::StackDump(L);
	lua_setmetatable(L, 2);
	return 1;
}

int BinaryArray_Reg::BinaryArray_Set(lua_State* L)
{
	BinaryArray* binaryArray = (BinaryArray*)luaL_checkudata(L, 1, "BinaryArrayMetaTable");
	int index = luaL_checkint(L,2) - 1;
	luaL_checkany(L, 3);

	luaL_argcheck(L, binaryArray != NULL, 1, "'array' expected");
	luaL_argcheck(L, index >=0 && binaryArray->Count() > index, 2, "index out of range");
	
	if (lua_toboolean(L, 3))
	{
		binaryArray->Set(index, true);
	}
	else
	{
		binaryArray->Set(index, false);
	}
	return 0;
}

int BinaryArray_Reg::BinaryArray_Get(lua_State* L)
{
	BinaryArray* binaryArray = (BinaryArray*)luaL_checkudata(L, 1, "BinaryArrayMetaTable");
	int index = luaL_checkint(L,2) - 1;

	luaL_argcheck(L, binaryArray != NULL, 1, "'array' expected");
	luaL_argcheck(L, index >=0 && binaryArray->Count() > index, 2, "index out of range");
	
	bool v = binaryArray->Get(index);
	
	lua_pushboolean(L, (int)v);

	return 1;
}

int BinaryArray_Reg::BinaryArray_Count(lua_State* L)
{
	BinaryArray* binaryArray = (BinaryArray*)luaL_checkudata(L, 1, "BinaryArrayMetaTable");

	luaL_argcheck(L, binaryArray != NULL, 1, "'array' expected");

	lua_pushinteger(L, binaryArray->Count());

	return 1;
}

void BinaryArray_Reg::Reg(lua_State* L)
{
	const struct luaL_Reg binaryArrayMetaTable_Lib [] = {
		{"Set", BinaryArray_Set},
		{"Get", BinaryArray_Get},
		{"Count", BinaryArray_Count},
		{NULL, NULL}
	};

	const struct luaL_Reg binaryArray_Lib[] = {
		{ "New", BinaryArray_New },
		{ NULL, NULL }
	};
	luaL_newmetatable(L, "BinaryArrayMetaTable");
	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	luaL_register(L, NULL, binaryArrayMetaTable_Lib);

	luaL_register(L, "BinaryArray", binaryArray_Lib);
}

