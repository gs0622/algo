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

int palindrome(int n)
{
    int i, ret = 1, msb = sizeof(int) * 8 - 1;
    for (i = 0; i < (msb+1)/2; i++)
        if (!!(n & (1 << i)) != !!(n & (1 << (msb-i)))) {
            ret = 0;
            break;
        }
    return ret;
}

int main(int argc, char *argv[])
{
    int n;
    if (1 == argc) return 0;
    n = atoi(argv[1]);
    printf("%s\n", itob(n));
    printf("%s\n", palindrome(n)? "yes": "no");
    return 0;
}

