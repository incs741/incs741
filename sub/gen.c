/*
 *  @author   : Rajan Khullar
 *  @author   : Shawn Hu
 *  @created  : 10/05/16
 *  @updated  : 10/05/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt-sub.h"

FILE *fp;

int main(void)
{
    const char *key = gen();
    fp = fopen("key.txt", "w");
    fprintf(fp, "%s\n", key);
    fclose(fp);
    free((void*) key);
    return 0;
}
