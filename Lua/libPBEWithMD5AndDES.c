
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rand.h>

#include "PBEWithMD5AndDES.h"

// 加密
// 1 data
// 2 data length
// 3 secret 
// 4 secret length
// return
// 1 flag
// 2 encrypt

static int lua_encrypt(lua_State *L) {

	const char *data = luaL_checkstring(L, 1);
	size_t datalen = (short)luaL_checkint(L, 2);

	const char *secret = luaL_checkstring(L, 3);
	size_t secretlen = luaL_checkint(L, 4);

	char *encrypt ;
	if (PBEWithMD5AndDES_encrypt(( unsigned char *)data, datalen , ( unsigned char *)secret, secretlen , &encrypt) != NULL) {
		lua_pushboolean(L,1);
		lua_pushstring(L,encrypt);
		free(encrypt);
	} else {
		lua_pushboolean(L,0);
		lua_pushstring(L,"error");
	}

    return 2;
}

// 解密
// 1 data
// 2 secret 
// 3 secret length
// return
// 1 flag
// 2 decrypt

static int lua_decrypt(lua_State *L){

	const char *data = luaL_checkstring(L, 1);
	const char *secret = luaL_checkstring(L, 2);
	size_t secretlen = luaL_checkint(L, 3);

	size_t len;
	unsigned char *decrypt;
	if (PBEWithMD5AndDES_decrypt((unsigned char *)data , (unsigned char *)secret, secretlen, &decrypt, &len ) != NULL) {
		lua_pushboolean(L,1);
		lua_pushlstring(L,decrypt,len);
		free(decrypt);
	} else {
		lua_pushboolean(L,0);
		lua_pushstring(L,"error");
	}
    return 2;
}



static const luaL_Reg lib[] = {
    {"encrypt", lua_encrypt},
    {"decrypt", lua_decrypt},
    {NULL, NULL}
};


int luaopen_libPBEWithMD5AndDES(lua_State *L) {
    luaL_register(L, "libPBEWithMD5AndDES", lib);
    return 0;
}
