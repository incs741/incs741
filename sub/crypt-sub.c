/*
 *  @author   : Rajan Khullar
 *  @author   : Shawn Hu
 *  @created  : 10/04/16
 *  @updated  : 10/07/16
 */

#include "macros.h"
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
    for(i = 0; i < langN; i++)
    {
        j = rand() % langN;
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
    char *str = (char*) malloc ((langN+1)*sizeof(char));
    FILE *file = fopen(path, "r");
    if(file)
    {
        fgets(str, langN+1, file);
        fclose(file);
    }
    return str;
}

static char* seed(void)
{
    char *str = (char*) malloc((langN+1)*sizeof(char));
    unsigned int x, c = (unsigned int) 'a';
    for(x = 0; x < langN; x++)
        str[x] = c++;
    str[langN] = '\0';
    return str;
}

static void swap(char *a, unsigned int i, unsigned int j)
{
    char t = a[i];
    a[i] = a[j];
    a[j] = t;
}
