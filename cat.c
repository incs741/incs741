/*
 *  @author   : Rajan Khullar
 *  @created  : 10/04/16
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
        return 1;
    const char *path = argv[1];
    if(!exists(path))
    {
        printf("cannot find %s\n", path);
        return -1;
    }
    cat(path);
    return 0;
}
