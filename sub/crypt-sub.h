/*
 *  @author   : Rajan Khullar
 *  @author   : Shawn Hu
 *  @created  : 10/04/16
 *  @updated  : 10/04/16
 */

#ifndef CRYPT_SUB_H
#define CRYPT_SUB_H
#define N 26

/* primary functions */
extern const char* gen(void);
extern const char* enc(const char* key, const char* ptex);
extern const char* dec(const char* key, const char* ctex);
extern const char* cat(const char* path);

/* support functions */
static char* seed(void);
static void swap(char* a, unsigned int i, unsigned int j);

#endif // LINKED_LIST_H
