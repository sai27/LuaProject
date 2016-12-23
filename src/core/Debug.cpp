#include "typedef.h"
#include "lua.hpp"
#include "Debug.h"

void Debug::StackDump(lua_State* L)
{
	printf("===StackDump===\n");
	int top = lua_gettop(L);
	for (int i = top; i >= 1; i--)
	{
		int type = lua_type(L, i);
		switch (type)
		{
		case LUA_TSTRING:
			printf("=[%d][string]:%s", i, lua_tostring(L, i));
			break;
		case LUA_TBOOLEAN:
			printf("=[%d][boolean]:%s", i, lua_toboolean(L, i) ? "true" : "false");
			break;
		case LUA_TNUMBER:
			printf("=[%d][number]:%g", i, lua_tonumber(L, i));
			break;
		default:
			printf("=[%d][%s]", i, lua_typename(L, type));
		}
		printf("\n");
	}
	printf("===============\n");
}
