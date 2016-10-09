/*
 *  @author   : Rajan Khullar
 *  @created  : 10/08/16
 *  @updated  : 10/08/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "crypt-sub.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("dec ciphertext.txt\n");
        return -1;
    }

    if(!exists(key_sub))
    {
        printf("cannot find %s\n", key_sub);
        return -1;
    }

    const char *path = argv[1];
    if(!exists(path))
    {
        printf("cannot find %s\n", path);
        return -1;
    }

    char *key = (char*) rkey(key_sub);
    key = (char*) ikey(key);

    FILE *fi = fopen(path, "r"), *fo = fopen(ptex_sub, "w");
    if(fi == NULL || fo == NULL)
    {
        printf("there has been an error\n");
        free(key);
        return -1;
    }

    int c, o;
    while((c = fgetc(fi)) != EOF)
    {
        o = filter((char) c);
        if(o > -1)
            fputc(key[o], fo);
    }
    fputc('\n', fo);

    fclose(fi);
    fclose(fo);
    free(key);

    return 0;
}