/*
 *  @author   : Rajan Khullar
 *  @author   : Shawn Hu
 *  @created  : 10/05/16
 *  @updated  : 10/05/16
 */

#ifndef CRYPT_SUB_H
#define CRYPT_SUB_H
#define N 26

//extern const unsigned int N = 26;

/* main functions */
extern const char* gen(void);
extern const char* enc(const char* key, const char* ptex);
extern const char* dec(const char* key, const char* ctex);

/* support functions */
static char* seed(void);
static void swap(char* a, unsigned int i, unsigned int j);

#endif // LINKED_LIST_H
