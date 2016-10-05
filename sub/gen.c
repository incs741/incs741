/*
 *  @author   : Rajan Khullar
 *  @author   : Shawn Hu
 *  @created  : 10/04/16
 *  @updated  : 10/04/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt-sub.h"

int main(void)
{
    const char *key = gen();
    //printf("%s\n", key);
    FILE *fp = fopen("key.txt", "w");
    fprintf(fp, "%s\n", key);
    fclose(fp);
    free((void*) key);
    return 0;
}