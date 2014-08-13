#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, n;
    if (1 == argc) return 0;
    n = atoi(argv[1]);
    for (i = 31; i >= 0; i--)
        printf("%d", (n & (1 << i))? 1: 0);
    puts("");
    return 0;
}

