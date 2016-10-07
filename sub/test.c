/*
 *  @author   : Rajan Khullar
 *  @created  : 10/XX/16
 *  @updated  : 10/XX/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt-sub.h"

int main(int argc, char *argv[])
{
    char *key = (char*) read_key(key_sub);
    printf("%s\n", key);
    free(key);
    return 0;
}
