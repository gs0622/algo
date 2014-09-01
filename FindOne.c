/* Given a number having only one ’1′ and all other ’0′s in its binary representation,
   find position of the only set bit. */
#include <stdio.h>
#include <stdlib.h>
static int IsPowerOfTwo(unsigned long long v)
{
    return ((v & (v-1)) == 0)? 1/*yes*/: 0;
}
static int FindOne(unsigned long long v)
{
    unsigned int i = 1, pos = 1;
    if (0 == IsPowerOfTwo(v)) return -1;
    else {
        while (0 == (i & v)) {
            i<<=1, ++pos;
        }
    }
    return pos;
}
int main(void)
{
    char str[128];
    unsigned long long v;
    while (scanf("%s", str) != EOF) {
        v = strtoull(str, NULL, 0);
        printf("v=%llu, pos=%d\n", v, FindOne(v));
    }
    return 0;
}
