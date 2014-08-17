#include <stdio.h>
#include <stdlib.h>

char *itob(int n)
{
    int i, j;
    static char buf[64] = {};
    for (i = 31, j = 0; i >= 0; i--)
        buf[j++] = (n & (1 << i))? '1': '0';
    buf[j] = 0;
    return buf;
}

int bitrev(int n)
{
    n = (n & 0xaaaaaaaa) >> 1 | (n & 0x55555555) << 1;
    n = (n & 0xcccccccc) >> 2 | (n & 0x33333333) << 2;
    n = (n & 0xf0f0f0f0) >> 4 | (n & 0x0f0f0f0f) << 4;
    n = (n & 0xff00ff00) >> 8 | (n & 0x00ff00ff) << 8;
    n = (n >> 16) | (n << 16);
    return n;
}

int main(int argc, char *argv[])
{
    int i, n;
    if (1 == argc) return 0;
    for (i = 1; i < argc; i++) {
        n = atoi(argv[i]);
        printf("%s\n", itob(n));
        printf("%s\n", itob(bitrev(n)));
    }
    return 0;
}
