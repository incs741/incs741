/*
 *  @author   : Rajan Khullar
 *  @author   : Shawn Hu
 *  @created  : 10/04/16
 *  @updated  : 10/05/16
 */

#include "crypt-sub.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern const char* gen(void)
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

extern void cat(const char* path)
{
    int c;
    FILE *file = fopen(path, "r");
    if(file)
    {
        while((c = fgetc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
}

extern const char* read_key(const char* path)
{
    char *str = (char*) malloc (N*sizeof(char));
    FILE *file = fopen(path, "r");
    if(file)
    {
        fgets(str, N+1, file);
        fclose(file);
    }
    return str;
}

static char* seed(void)
{
    char *str = (char*) malloc (N*sizeof(char));
    strcpy(str, "abcdefghijklmnopqrstuvwxyz");
    return str;
}

static void swap(char *a, unsigned int i, unsigned int j)
{
    char t = a[i];
    a[i] = a[j];
    a[j] = t;
}
