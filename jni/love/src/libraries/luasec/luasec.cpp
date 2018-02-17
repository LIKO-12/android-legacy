/**
 * LuaSec-0.7alpha wrapper for LOVE
 * Copyright (c) 2039 Dark Energy Processor
 */

#include "luasec.h"

extern "C" {
#include "ssl.h"
#include "config.h"
#include "context.h"
#include "options.h"
#include "x509.h"

extern int luaopen_ssl_config(lua_State *L);
}

// Quick macro for adding functions to 
// the preloder.
#define PRELOAD(name, function) \
	lua_getglobal(L, "package"); \
	lua_getfield(L, -1, "preload"); \
	lua_pushcfunction(L, function); \
	lua_setfield(L, -2, name); \
	lua_pop(L, 2);

// Quick macro for loading script
#define SCRIPT_LOAD(name) \
	if (luaL_loadbuffer(L, (const char*)T_L_POPIPA, T_L_POPIPA_len, name) == 0) \
		lua_call(L, 0, 1); \
	return 1

namespace luasec
{
int __open(lua_State *L)
{
	PRELOAD("ssl", __open_ssl);
	PRELOAD("ssl.core", luaopen_ssl_core);
	PRELOAD("ssl.config", luaopen_ssl_config);
	PRELOAD("ssl.context", luaopen_ssl_context);
	PRELOAD("ssl.https", __open_ssl_https);
	PRELOAD("ssl.x509", luaopen_ssl_x509);

	return 0;
}

int __open_ssl(lua_State *L)
{
	#include "ssl.lua.h"
	SCRIPT_LOAD("ssl.lua");
}

int __open_ssl_https(lua_State *L)
{
	#include "https.lua.h"
	SCRIPT_LOAD("https.lua");
}

}
