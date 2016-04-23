#ifndef _PBEWITHMD5ANDDES_H_
#define _PBEWITHMD5ANDDES_H_

#include <stddef.h>

#ifdef __cplusplus 
extern "C" {
#endif

/**
 * Encrypt for PBEWithMD5AndDES
 * <br><br>
 * <b>Note: </b>Remember to free "out"
 *
 * @param *msg message for encrypt
 * @param msg_len lenght of msg
 * @param *passwd password for encrypt
 * @param passwd_len lenght of password
 * @param **out pointer to encrypt buffer, malloc() during encryption
 *
 * @return *out, which is encrypt Base64 string or NULL if failed
 */
char * PBEWithMD5AndDES_encrypt(unsigned char *msg, size_t msg_len, unsigned char *passwd, size_t passwd_len, char **out);

/**
 * Decrypt for PBEWithMD5AndDES
 * <br><br>
 * <b>Note: </b>Remember to free "out"
 *
 * @param *str Encrypt Base64 string, terminated with '\0'
 * @param *passwd password for decrypt
 * @param passwd_len lenght of password
 * @param **out pointer to decrypt buffer, terminated with '\0' (*out[*len], won't affect content) malloc() during decryption
 * @param *len length of out, set to 0 if failed
 *
 * @return *out, which points to buffer or NULL if failed
 */
unsigned char * PBEWithMD5AndDES_decrypt(char *str, unsigned char *passwd, size_t passwd_len, unsigned char **out, size_t *len);

/*check if the compiler is of C++ */
#ifdef __cplusplus 
}
#endif

#endif

