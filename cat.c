/*
 *  @author   : Rajan Khullar
 *  @created  : 10/04/16
 *  @updated  : 10/09/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool exists(const char* path);
void cat(const char* path);

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

bool exists(const char* path)
{
    FILE *file = fopen(path, "r");
    if(file)
    {
        fclose(file);
        return true;
    }
    return false;
}

void cat(const char* path)
{
    int c;
    FILE *file = fopen(path, "r");
    if(file)
    {
        while((c = fgetc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
}
