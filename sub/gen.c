/*
 *  @author   : Rajan Khullar
 *  @author   : Shawn Hu
 *  @created  : 10/04/16
 *  @updated  : 10/07/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt-sub.h"

int main(int argc, char *argv[])
{
    const char *key = gen();
    printf("%s\n", key);
    FILE *file = fopen(key_sub, "w");
    fprintf(file, "%s\n", key);
    fclose(file);
    free((void*) key);
    return 0;
}
