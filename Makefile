CFLAGS = -shared -fPIC -lssl -lcrypto
ALL_INCS = -I /usr/local/include/luajit-2.0/ -I /usr/include/ -I .
ALL_LIBS = -lluajit-5.1


libPBEWithMD5AndDES.so:
	gcc $(CFLAGS) PBEWithMD5AndDES.h PBEWithMD5AndDES.c libPBEWithMD5AndDES.c -o $@ $(ALL_INCS) $(ALL_LIBS) 
clean:
	rm  -rf *.so
