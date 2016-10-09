/*
 *  @author   : Rajan Khullar
 *  @author   : Shawn Hu
 *  @created  : 10/04/16
 *  @updated  : 10/09/16
 */

#include "support.h"

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

static int find(const char *str, char c)
{
    int x = 0;
    while(*str)
    {
        if(c == *str++)
            return x;
        x++;
    }
    return -1;
}

extern int filter(char c)
{
    if('a' <= c && c <= 'z')
        return (int) c - (int) 'a';
    if('A' <= c && c <= 'Z')
        return (int) c - (int) 'A';
    return -1;
}

extern bool exists(const char *path)
{
    FILE *file = fopen(path, "r");
    if(file)
    {
        fclose(file);
        return true;
    }
    return false;
}

extern const char* gkey(void)
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

extern const char* rkey(const char *path)
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

extern const char* ikey(const char *key)
{
    char *str = (char*) malloc((langN+1)*sizeof(char));
    int i, j; char c;
    for(i = 0; i < langN; i++)
    {
        c = 'a' + i;
        j = find(key, c);
        if(j > -1)
            str[i] = 'a' + j;
    }
    str[langN] = '\0';
    return str;
}
