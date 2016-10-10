/*
 *  @author   : Rajan Khullar
 *  @created  : 10/04/16
 *  @updated  : 10/10/16
 */

#include "support.h"

FILE *fk, *fi, *fo;
int   ck,  ci,  co;

int enc(const char *path, const char *key, const char *out)
{
    fk = fopen(key , "r"); if(fk == NULL) return -1; ck = 0;
    fi = fopen(path, "r"); if(fi == NULL) return -1; ci = 0;
    fo = fopen(out , "w"); if(fo == NULL) return -1; co = 0;
    unsigned int n = 0;
    while(true)
    {
        ci = fgetc(fi);
        ck = fgetc(fk);
        if(ci == EOF || ck == EOF)
            break;
        co = ci^ck;
        fputc(co, fo);
        n++;
    }
    fclose(fi); fclose(fk); fclose(fo);
    printf("%d\n", n);
    return 0;
}

int dec(const char *path, const char *key, const char *out)
{
    return enc(path, key, out);
}

int main(int argc, char *argv[])
{
    if(!exists(pathK))
        return -1;
    if(argc < 2)
        return -1;
    const char *path = argv[1];
    if(!exists(path))
        return -1;
    if(mode == modeE)
        return enc(path, pathK, pathC);
    if(mode == modeD)
        return dec(path, pathK, pathP);
    return 0;
}
