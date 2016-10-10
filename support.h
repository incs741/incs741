/*
 *  @author   : Rajan Khullar
 *  @created  : 10/04/16
 *  @updated  : 10/10/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef SUPPORT_H
#define SUPPORT_H

#define modeE 1
#define modeD 2
#define pathK "key.dat"
#define pathC "ciphertext.dat"
#define pathP "plaintext.dat"

extern bool exists(const char*);

#endif // SUPPORT_H
