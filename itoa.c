#include <stdio.h>
#include <stdlib.h>

char code[] = {"0123456789abcdef"};

char *itoa(int n)
{
    int i, j;
    static char buf[16] = {};
    for (i = 28, j = 0; i >= 0; i-=4)
        buf[j++] = code[(n >> i) & 0xf]; 
    buf[j] = '\0';
    return buf;
}

int main(int argc, char *argv[])
{
    int n, i;
    if (1 == argc) return 0;
    for (i = 1; i < argc; i++) {
        n = atoi(argv[i]);
        puts(itoa(n));
    }
    return 0;
}

