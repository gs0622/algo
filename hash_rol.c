/*Rolling hash*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned int hash(void *key, int len)
{
    const unsigned BASE = 257;
    const unsigned MOD = 1000000007;
    unsigned char *p = key;
    unsigned int h = 0;
    int i;
    for (i=0;i<len;i++) h=h*BASE+p[i], h%=MOD;
    return h;
}
int main(int argc, char *argv[])
{
    unsigned int i, h, n=argc-1;
    for (i=0;i<n;i++) {
        h = hash(argv[i+1], strlen(argv[i+1]));
        printf("h(%s)=%d/0x%x\n", argv[i+1], h, h);
    }
    return 0;
}

