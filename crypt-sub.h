/*
 *  @author   : Rajan Khullar
 *  @author   : Shawn Hu
 *  @created  : 10/04/16
 *  @updated  : 10/08/16
 */

#include "macros.h"
#include <stdbool.h>

#ifndef CRYPT_SUB_H
#define CRYPT_SUB_H

/* primary functions */
extern const char* gen(void);
//extern const char* enc(const char* key, const char* ptex);
//extern const char* dec(const char* key, const char* ctex);
extern void cat(const char* path);
extern bool exists(const char* path);
extern const char* rkey(const char* path);
extern const char* ikey(const char* key);
extern int filter(char c);

/* support functions */
static char* seed(void);
static void swap(char* a, unsigned int i, unsigned int j);
static int find(const char *str, char c);

#endif // LINKED_LIST_H
