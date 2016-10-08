/*
 *  @author   : Rajan Khullar
 *  @created  : 10/XX/16
 *  @updated  : 10/XX/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "crypt-sub.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
    long sz = sysconf(_SC_PAGESIZE);
    printf("%ld\n", sz);
    return 0;
}
