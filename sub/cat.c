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

int main(int argc, char *argv[])
{
    if(argc < 2)
        return 1;
    const char* path = argv[1];
    printf("%s\n", path);
    cat(path);
    return 0;
}
