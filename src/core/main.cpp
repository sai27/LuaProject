#include "lua.hpp"
#include "BinaryArray_Reg.h"
#include <iostream>
using namespace std;

int main()
{
	lua_State* L = luaL_newstate();  
	luaL_openlibs(L);

//	BinaryArray_Reg::RunTest(L);
    
    lua_close(L);

	system("pause");
	return 0;
}
