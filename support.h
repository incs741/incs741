/*
 *  @author   : Rajan Khullar
 *  @created  : 10/04/16
 *  @updated  : 10/09/16
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef SUPPORT_H
#define SUPPORT_H

#define modeG 1
#define modeE 2
#define modeD 3
#define langN 26
#define pathK "key.txt"
#define pathC "ciphertext.txt"
#define pathP "plaintext.txt"

static char* seed(void);
static void swap(char*, unsigned int, unsigned int);
static int find(const char*, char);

extern int filter(char);
extern bool exists(const char*);

extern const char* gkey(void);
extern const char* rkey(const char *path);
extern const char* ikey(const char *key);


#endif // SUPPORT_H
