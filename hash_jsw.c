#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
unsigned char tab[256];
unsigned int hash(void *key, int len)
{
    unsigned char *p = key;
    unsigned h = 16777551;
    int i;
    for ( i = 0; i < len; i++ )
        h = ( h << 1 | h >> 31 ) ^ tab[p[i]];
    return h;
}
int main(int argc, char *argv[])
{
    unsigned int i, h, n=argc-1;
    srand(time(NULL));
    for (i=0;i<256;i++) tab[i]=rand()%256;
    for (i=0;i<n;i++) {
        h = hash(argv[i+1], strlen(argv[i+1]));
        printf("h(%s)=%d/0x%x\n", argv[i+1], h, h);
    }
    return 0;
}

