/*
 *  @author   : Rajan Khullar
 *  @created  : 10/05/16
 *  @updated  : 10/07/16
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
        printf("enc secret.txt\n");
        return -1;
    }

    if(!exists(key_sub))
    {
        printf("cannot open %s\n", key_sub);
        return -1;
    }

    const char *path = argv[1];
    char *key = (char*) rkey(key_sub);

    printf("%s\n", path);
    printf("key: %s\n", key);

    FILE *fi = fopen(path, "r");
    FILE *fo = fopen(ctex_sub, "w");
    if(fi && fo)
    {
        fclose(fi);
        fclose(fo);
    }
    free(key);
    return 0;
}
