/*
 *  @author   : Rajan Khullar
 *  @created  : 10/05/16
 *  @updated  : 10/07/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt-sub.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("%s\n", "enc secret.txt");
        return 1;
    }
    const char *path = argv[1];
    char *key = (char*) read_key(key_sub);
    printf("%s\n", path);
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
