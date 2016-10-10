/*
 *  @author   : Rajan Khullar
 *  @created  : 10/04/16
 *  @updated  : 10/10/16
 */

#include "support.h"

extern bool exists(const char *path)
{
    FILE *file = fopen(path, "r");
    if(file)
    {
        fclose(file);
        return true;
    }
    return false;
}
