#include "lua.hpp"

int main()
{
	lua_State* L = luaL_newstate();  
    luaL_openlibs(L);  
    luaL_dofile(L, "../../lua/test.lua");  
    lua_close(L); 
	return 0;
}
