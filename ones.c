#include <stdio.h>

unsigned int ones32(register unsigned int x)
{
    /* 32-bit recursive reduction using SWAR...
       but first step is mapping 2-bit values
       into sum of 2 1-bit values in sneaky way
    */
    x -= ((x >> 1) & 0x55555555);
    x = (((x >> 2) & 0x33333333) + (x & 0x33333333));
    x = (((x >> 4) + x) & 0x0f0f0f0f);
    x += (x >> 8);
    x += (x >> 16);
    return(x & 0x0000003f);
}

int main(void)
{
    int x;
    while (scanf("%d", &x) == 1)
        printf("%d\n", ones32(x));
    return 0;
}

