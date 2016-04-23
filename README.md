PBEWithMD5AndDES in C and Python
================

##### C &amp; Python 2.x implementation of PBEWithMD5AndDES by Jasypt Java Package: org.jasypt.encryption.pbe.StandardPBEStringEncryptor
----

PBEWithMD5AndDES seems popular in the Java world, and many are asking for implementation of XX language.

The C implementation uses OpenSSL. And I've updated the [Python one on stackoverflow] [1].

Version
----

0.1

C Example Usage
-----------

```sh
$ make
$ ./example
$ ./encrypt input=<your input string> password=<your password string>
$ ./decrypt input=<your input string> password=<your password string>
```


C Example Test
--------------

##### Suppose that your jasypt is extracted into ${JASYPT_PATH}

Lua lib

libPBEWithMD5AndDES.so

Lua Example Test
#####  luajit filename.lua

License
----

MIT for C implementation

[Creative Commons] [2] for Python 2.x implementation
