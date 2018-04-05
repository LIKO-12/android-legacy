/**
 * LuaSec-0.7alpha wrapper for LOVE
 * Copyright (c) 2039 Dark Energy Processor
 */

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

namespace luasec
{
int __open(lua_State *L);
int __open_ssl(lua_State *L);
int __open_ssl_https(lua_State *L);
}
