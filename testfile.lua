
local lib = require('libPBEWithMD5AndDES')

local tempstr = "hello nihao"
local secret = "abcabcabc"

print("string:" .. tempstr)
print("secret:" .. secret)

local ok, ret = lib.encrypt(tempstr,#tempstr,secret,#secret)
print('start encrypt')
print(ok)
print(ret)

local str = ret
print("temp:" .. str )
local ok, ret = lib.decrypt(str,secret,#secret)
print(ok)
print(ret)