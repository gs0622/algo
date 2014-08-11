#include <stdio.h>
#include <stdlib.h>

char code[] = {"0123456789abcdef"};
char *itoa(int n)
{
    int i = 0, j, k;
    static char buf[64] = {};
    //if (n < 0) buf[i++] = '-', neg = 1;
    while (n) {
        if (n & ~0xf) buf[i++] = code[n & 0xf];
        else  buf[i++] = code[n];
        n = (unsigned)n >> 4; 
    }
    for (j = i-1; j > (i-1)/2; j--) k = buf[j], buf[j] = buf[i-1-j], buf[i-1-j] = k; 
    buf[i] = '\0';
    return buf;
}
int main(int argc, char *argv[])
{
    int n, i;
    if (1 == argc) return 0;
    for (i = 1; i < argc; i++) {
        n = atoi(argv[i]);
        //printf("n=%d\n", n);
        puts(itoa(n));
    }
    return 0;
}

