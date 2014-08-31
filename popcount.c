#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long uint64_t;
const uint64_t m1  = 0x5555555555555555; //binary: 0101...
const uint64_t m2  = 0x3333333333333333; //binary: 00110011..
const uint64_t m4  = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
const uint64_t m8  = 0x00ff00ff00ff00ff; //binary:  8 zeros,  8 ones ...
const uint64_t m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
const uint64_t m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones
const uint64_t hff = 0xffffffffffffffff; //binary: all ones
const uint64_t h01 = 0x0101010101010101; //the sum of 256 to the power of 0,1,2,3...
int popcount1(uint64_t x)
{
    x = (x & m1) + ((x >> 1) & m1);
    x = (x & m2) + ((x >> 2) & m2);
    x = (x & m4) + ((x >> 4) & m4);
    x = (x & m8) + ((x >> 8) & m8);
    x = (x & m32) + ((x >> 16) & m32);
    return x;
}
int main(void)
{
    char str[128] = {};
    unsigned long long v;
    while (scanf("%s", str) != EOF) {
        v = strtoull(str, NULL, 10);
        printf("%llu\n", v);
        printf("%d\n", popcount1(v));
    }
    return 0;
}

