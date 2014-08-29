/*Swap all odd and even bits*/
#include <stdio.h>
#include <stdlib.h>
unsigned int swapEO(unsigned int n)
{
    unsigned int even, odd;;
    even = (n & 0xaaaaaaaa) >> 1;
    odd = (n & 0x55555555) << 1;
    return even | odd;
}
int main(int argc, char *argv[])
{
    unsigned int n;
    while (scanf("%x", &n) == 1) {
        n = swapEO(n);
        printf("0x%x\n", n);
    }
    return 0;
}

