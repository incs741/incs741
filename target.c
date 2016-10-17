/*
 *  @author   : Rajan Khullar
 *  @author   : Shawn Hu
 *  @created  : 10/04/16
 *  @updated  : 10/17/16
 */

#include "support.h"

FILE *fi, *fo;

int gen(void)
{
    const char *key = gkey();
    printf("%s\n", key);
    fo = fopen(pathK, "w");
    fprintf(fo, "%s\n", key);
    fclose(fo);
    free((char*)key);
    return 0;
}

int enc(const char *path, const char *key, const char *out)
{
    FILE *fi = fopen(path, "r"), *fo = fopen(out, "w");
    if(fi == NULL || fo == NULL)
        return -1;
    int c, o;
    while((c = fgetc(fi)) != EOF)
    {
        o = filter((char) c);
        if(o > -1)
            fputc(key[o], fo);
    }
    fputc('\n', fo);
    fclose(fi); fclose(fo);
    free((char*)key);
    printf("created %s\n", out);
    return 0;
}

int dec(const char *path, const char *key, const char *out)
{
    return enc(path, ikey(key), out);
}

int main(int argc, char *argv[])
{
    if(mode == modeG)
        return gen();
    if(argc < 2)
    {
        printf("missing paramter: filepath\n");
        return -1;
    }
    const char *path = argv[1];
    if(!exists(path))
    {
        printf("failed to open %s\n", path);
        return -1;
    }
    if(!exists(pathK))
    {
        printf("failed to open %s\n", pathK);
        return -1;
    }
    const char *key = rkey(pathK);
    if(mode == modeE)
        return enc(path, key, pathC);
    if(mode == modeD)
        return dec(path, key, pathP);
    return 0;
}
