/*
 *  @author   : Rajan Khullar
 *  @author   : Shawn Hu
 *  @created  : 10/05/16
 *  @updated  : 10/05/16
 */

#include "crypt-sub.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

extern const char* gen()
{
    char *key = seed();
    unsigned int i, j;
    srand(time(NULL));
    for(i = 0; i < N; i++)
    {
        j = rand() % N;
        swap(key, i, j);
    }
    return key;
}

static char* seed(void)
{
    char *str = (char*) malloc (N*sizeof(char));
    strcpy(str, "abcdefghijklmnopqrstuvwxyz");
    return str;
}

static void swap(char* a, unsigned int i, unsigned int j)
{
    char t = a[i];
    a[i] = a[j];
    a[j] = t;
}
