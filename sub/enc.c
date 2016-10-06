/*
 *  @author   : Rajan Khullar
 *  @created  : 10/05/16
 *  @updated  : 10/05/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt-sub.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
        return 1;
    const char *path = argv[1];
    const char *key = read_key("key.txt");
    printf("%s\n", path);
    FILE *fi = fopen(path, "r");
    FILE *fo = fopen("ciphertext.txt", "w");
    if(fi && fo)
    {
        fclose(fi);
        fclose(fo);
    }
    free((void*) key);
    return 0;
}
